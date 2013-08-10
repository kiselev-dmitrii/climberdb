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

QSqlQueryModel* Database::mainProductsModel() {
        return &m_mainProductsModel;
}

QSqlQueryModel* Database::refreshMainProductsModel(const QString &name, const QString &model, const QString &size,
                                                   const QString &cost, const QString &type, const QString &gender,
                                                   const QString &comment, const QString &color, const QString &country) {
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
                        Country.Name as 'Производитель',
                        C.ID as 'ID'
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

        m_mainProductsModel.setQuery(query);
        return &m_mainProductsModel;
}

QSqlQueryModel* Database::refreshMainProductsModel() {
        m_mainProductsModel.query().exec();
        return &m_mainProductsModel;
}

QSqlQueryModel* Database::mainSoldProductsModel() {
        return &m_mainSoldProductsModel;
}

QSqlQueryModel* Database::refreshMainSoldProductsModel(const QDate &soldDate) {
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

        m_mainSoldProductsModel.setQuery(query);
        return &m_mainSoldProductsModel;
}

QVector<Product> Database::getProductListFromConsignment(int consignmentID) {
        QString queryString = R"(
                        SELECT
                                *
                        FROM
                                Product
                        WHERE
                                IsSold = 0 AND
                                ConsignmentID = :consignmentID
                              )";
        QSqlQuery query;
        query.prepare(queryString);
        query.bindValue(":consignmentID", consignmentID);
        query.exec();

        QVector<Product> result;
        while (query.next()) {
                Product product;
                product.id = query.value("ID").toInt();
                product.consignmentID = query.value("ConsignmentID").toInt();
                product.size = query.value("Size").toString();
                product.barcode = query.value("Barcode").toString();
                product.isSold = query.value("IsSold").toBool();
                product.deliveryDate = query.value("DeliveryDate").toDateTime();
                product.saleDate = query.value("SaleDate").toDateTime();
                product.lastReturnDate = query.value("LastReturnDate").toDateTime();
                product.countReturns = query.value("CountReturns").toInt();
                product.clientID = query.value("ClientID").toInt();

                result.append(product);
        }

        return result;
}

void Database::soldProduct(int productID) {
        QString queryString = R"(
                        UPDATE
                                Product
                        SET
                                IsSold = 1,
                                SaleDate = DATETIME('now', 'localtime')
                        WHERE
                                ID = :productID
                              )";
        QSqlQuery query;
        query.prepare(queryString);
        query.bindValue(":productID", productID);
        query.exec();
}

QSqlQueryModel* Database::refreshMainSoldProductsModel() {
        m_mainSoldProductsModel.query().exec();
        return &m_mainSoldProductsModel;
}
