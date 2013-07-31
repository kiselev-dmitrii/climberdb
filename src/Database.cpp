#include "Database.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

Database::Database() {
        m_dbName = "shop.db";
        createConnction();
}

Database* Database::instance() {
        static Database instance;
        return &instance;
}

bool Database::createConnction() {
        m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName(m_dbName);
        if (!m_db.open()) {
                qDebug() << "Cannot open database " << m_dbName;
                return false;
        }
        return true;
}

void Database::getAllProductsModel(QSqlQueryModel* sqlModel, const QString& name, const QString& model, const QString& size,
                                   const QString& cost, const QString& type, const QString& gender,
                                   const QString& comment, const QString& color, const QString& country) {
        QString queryString = R"(
                SELECT
                        C.Name as 'Наименование',
                        C.Model as 'Модель',
                        GROUP_CONCAT(Size, ", ") as 'Размеры',
                        C.Cost as 'Цена',
                        Type.Name as 'Тип',
                        C.Gender as 'Пол',
                        C.Comment as 'Комментарии',
                        Color.Name as 'Цвет',
                        Country.Name as 'Производитель'
                FROM
                        Consignment as C
                        JOIN 		Product as P 	        ON     C.ID = P.ConsignmentID
                        LEFT JOIN 	Type      		ON     C.TypeID = Type.ID
                        LEFT JOIN 	Color 			ON     C.ColorID = Color.ID
                        LEFT JOIN 	Country 		ON     C.CountryID = Country.ID
                WHERE
                        P.IsSold = 0 AND
                        IFNULL(C.Name, "") LIKE '%'||:name||'%' AND
                        IFNULL(C.Model, "") LIKE '%'||:model||'%' AND
                        IFNULL(Size, "") LIKE :size||'%' AND
                        IFNULL(C.Cost, "") LIKE :cost||'%' AND
                        IFNULL(Type.Name, "") LIKE '%'||:type||'%' AND
                        IFNULL(C.Gender, "") LIKE '%'||:gender||'%' AND
                        IFNULL(C.Comment, "") LIKE '%'||:comment||'%' AND
                        IFNULL(Color.Name, "") LIKE '%'||:color||'%' AND
                        IFNULL(Country.Name, "") LIKE '%'||:country||'%'
                GROUP BY
                        C.Name, C.Model, C.Cost, C.TypeID, C.Gender, C.Comment
                ORDER BY
                        C.ID
                )";
        QSqlQuery query;
        query.prepare(queryString);
        query.bindValue(":name", name);
        query.bindValue(":model", model);
        query.bindValue(":size", size);
        query.bindValue(":cost", cost);
        query.bindValue(":type", type);
        query.bindValue(":gender", gender);
        query.bindValue(":comment", comment);
        query.bindValue(":color", color);
        query.bindValue(":country", country);
        query.exec();

        sqlModel->setQuery(query);
}

void Database::getSoldProductsOnDate(QSqlQueryModel* sqlModel, const QDate& soldDate) {
        QString queryString = R"(
                        SELECT
                                C.Name as 'Наименование',
                                C.Model as 'Модель',
                                P.Size as 'Размер',
                                C.Cost as 'Цена',
                                IFNULL(Type.Name, "")  || " " || LOWER(IFNULL(C.Gender, "")) || " " || LOWER(IFNULL(C.Comment, "")) || LOWER(IFNULL(Color.Name, "")) as 'Тип',
                                Country.Name as 'Производитель',
                                (P.SaleDate) as 'Время продажи',
                                IFNULL(Client.Name, "") || " " || IFNULL(Client.Surname, "") as 'Покупатель'
                        FROM
                                Consignment as C
                                JOIN 		Product as P 	        ON     C.ID = P.ConsignmentID
                                LEFT JOIN 	Type      		ON     C.TypeID = Type.ID
                                LEFT JOIN 	Color 			ON     C.ColorID = Color.ID
                                LEFT JOIN 	Country 		ON     C.CountryID = Country.ID
                                LEFT JOIN       Client                  ON     P.ClientID = Client.ID
                        WHERE
                                P.IsSold = 1   AND
                                date(P.SaleDate) = :soldDate
                        ORDER BY
                                P.SaleDate
                               )";
        QSqlQuery query;
        query.prepare(queryString);
        query.bindValue(":soldDate", soldDate);
        query.exec();

        sqlModel->setQuery(query);
}
