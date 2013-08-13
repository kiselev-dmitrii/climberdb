#include "Database.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <Utils.h>

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
        m_mainProductsModel.setQuery(m_mainProductsModel.query());
        return &m_mainProductsModel;
}

QSqlQueryModel* Database::mainSoldProductsModel() {
        return &m_mainSoldProductsModel;
}

QSqlQueryModel* Database::refreshMainSoldProductsModel(const QDate &soldDate) {
        QString queryString = R"(
                        SELECT
                                P.ID as "ProductID",
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

QSqlQueryModel* Database::refreshMainSoldProductsModel() {
        m_mainSoldProductsModel.query().exec();
        m_mainSoldProductsModel.setQuery(m_mainSoldProductsModel.query());
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

Consignment Database::getConsignmentByID(int consignmentID) {
        QString queryString = R"(
                        SELECT
                                C.ID as ID,
                                C.Name as Name,
                                C.Model as Model,
                                Color.Name as Color,
                                Type.Name as Type,
                                C.Gender as Gender,
                                C.Comment as Comment,
                                C.Cost as Cost,
                                Country.Name as Country
                        FROM
                                Consignment as C
                                LEFT JOIN Color ON C.ColorID = Color.ID
                                LEFT JOIN Type ON C.TypeID = Type.ID
                                LEFT JOIN Country ON C.CountryID = Country.ID
                        WHERE
                                C.ID = :consignmentID
                              )";
        QSqlQuery query;
        query.prepare(queryString);
        query.bindValue(":consignmentID", consignmentID);
        query.exec();
        query.first();

        Consignment consignment;
        consignment.id = query.value("ID").toInt();
        consignment.name = query.value("Name").toString();
        consignment.model = query.value("Model").toString();
        consignment.color = query.value("Color").toString();
        consignment.type = query.value("Type").toString();
        consignment.gender = query.value("Gender").toString();
        consignment.comment = query.value("Comment").toString();
        consignment.cost = query.value("Cost").toInt();
        consignment.country = query.value("Country").toString();

        return consignment;
}

QStringList Database::getAvailableTypes() {
        QString queryString = "SELECT Name FROM Type";
        QSqlQuery query(queryString);
        query.exec();

        QStringList result;
        while (query.next()) result.append(query.value("Name").toString());

        return result;
}

QStringList Database::getAvailableColors() {
        QString queryString = "SELECT Name FROM Color";
        QSqlQuery query(queryString);
        query.exec();

        QStringList result;
        while (query.next()) result.append(query.value("Name").toString());

        return result;
}

QStringList Database::getAvailableCountries() {
        QString queryString = "SELECT Name FROM Country";
        QSqlQuery query(queryString);
        query.exec();

        QStringList result;
        while (query.next()) result.append(query.value("Name").toString());

        return result;
}

int Database::getColorID(const QString &color) {
        QString queryString = "SELECT ID FROM Color WHERE Name = :color";
        QSqlQuery query;

        query.prepare(queryString);
        query.bindValue(":color", color);
        query.exec();
        query.first();
        if (query.size() == 0) return -1;
        else return query.value("ID").toInt();
}

int Database::getTypeID(const QString &type) {
        QString queryString = "SELECT ID FROM Type WHERE Name = :type";
        QSqlQuery query;

        query.prepare(queryString);
        query.bindValue(":type", type);
        query.exec();
        query.first();
        if (query.size() == 0) return -1;
        else return query.value("ID").toInt();
}

int Database::getCountryID(const QString &country) {
        QString queryString = "SELECT ID FROM Country WHERE Name = :country";
        QSqlQuery query;

        query.prepare(queryString);
        query.bindValue(":country", country);
        query.exec();
        query.first();
        if (query.size() == 0) return -1;
        else return query.value("ID").toInt();
}

int Database::addColor(const QString &color) {
        QString queryString = "INSERT INTO Color (Name) VALUES (:color)";
        QSqlQuery query;

        query.prepare(queryString);
        query.bindValue(":color", color);
        query.exec();
        return query.lastInsertId().toInt();
}

int Database::addType(const QString &type) {
        QString queryString = "INSERT INTO Type (Name) VALUES (:type)";
        QSqlQuery query;

        query.prepare(queryString);
        query.bindValue(":type", type);
        query.exec();
        return query.lastInsertId().toInt();
}

int Database::addCountry(const QString &country) {
        QString queryString = "INSERT INTO Country (Name) VALUES (:country)";
        QSqlQuery query;

        query.prepare(queryString);
        query.bindValue(":country", country);
        query.exec();
        return query.lastInsertId().toInt();
}

void Database::addNewProducts(int consignmentID, const QStringList &sizes) {
        QString queryString = R"(
                                INSERT INTO Product (ConsignmentID, Size, Barcode, DeliveryDate)
                                VALUES (:consignmentID, :size, :barcode, DATETIME('now', 'localtime'))
                                )";

        QMap<QString, QString> barcodes = Utils::generateBarcodes(consignmentID, sizes);
        for (auto &size: sizes) {
                QSqlQuery query;
                query.prepare(queryString);
                query.bindValue(":consignmentID", consignmentID);
                query.bindValue(":size", size);
                query.bindValue(":barcode", barcodes[size]);
                query.exec();
        }

}

QSqlQueryModel* Database::dialogSizesModel() {
        return &m_dialogSizesModel;
}

QSqlQueryModel* Database::refreshDialogSizesModel() {
        m_dialogSizesModel.query().exec();
        m_dialogSizesModel.setQuery(m_dialogSizesModel.query());
        return &m_dialogSizesModel;
}

QSqlQueryModel* Database::refreshDialogSizesModel(int consignmentID) {
         QString queryString = R"(
                        SELECT
                                ID as 'ID',
                                Size as 'Размер',
                                DeliveryDate as 'Дата доставки',
                                CountReturns as 'Количество возвратов',
                                LastReturnDate as 'Дата последнего возврата',
                                Barcode as 'Штрихкод'
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

        m_dialogSizesModel.setQuery(query);
        return &m_dialogSizesModel;

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

void Database::returnProduct(int productID) {
        QString queryString;
        QSqlQuery query;

        // Если указан клиент, то у него нужно увеличить количество возвратов, возможно изменить рейтинг
        queryString = "SELECT ClientID FROM Product WHERE ID = :productID";
        query.prepare(queryString);
        query.bindValue(":productID", productID);
        query.exec();
        query.first();
        if (!query.isNull(0)) {         //клиент указан
                int clientID = query.value("ClientID").toInt();
                Q_ASSERT(clientID != 0);

                queryString = R"(
                                UPDATE
                                        Client
                                SET
                                        CountReturns = CountReturns + 1
                                WHERE
                                        ID = :clientID
                              )";
                query.prepare(queryString);
                query.bindValue(":clientID", clientID);
                query.exec();
        }

        // Собственно делаем возврат товара
        queryString = R"(
                        UPDATE
                                Product
                        SET
                                IsSold = 0,
                                SaleDate = NULL,
                                LastReturnDate = DATETIME('now', 'localtime'),
                                CountReturns = CountReturns + 1,
                                ClientID = NULL
                        WHERE
                                ID = :productID
                              )";
        query.prepare(queryString);
        query.bindValue(":productID", productID);
        query.exec();
}

void Database::editProductSize(int productID, const QString &newSize) {
         QString queryString = R"(
                        UPDATE
                                Product
                        SET
                                Size = :newSize
                        WHERE
                                ID = :productID
                              )";
        QSqlQuery query;
        query.prepare(queryString);
        query.bindValue(":newSize", newSize);
        query.bindValue(":productID", productID);
        query.exec();
}

void Database::editProductDeliveryDate(int productID, const QDateTime &newDeliveryDate) {
         QString queryString = R"(
                        UPDATE
                                Product
                        SET
                                DeliveryDate = :newDeliveryDate
                        WHERE
                                ID = :productID
                              )";
        QSqlQuery query;
        query.prepare(queryString);
        query.bindValue(":newDeliveryDate", newDeliveryDate);
        query.bindValue(":productID", productID);
        query.exec();
}

void Database::removeProduct(int productID) {
        QString queryString = R"(
                        DELETE FROM
                                Product
                        WHERE
                                ID = :productID
                              )";
        QSqlQuery query;
        query.prepare(queryString);
        query.bindValue(":productID", productID);
        query.exec();
}

void Database::updateConsignment(int consignmentID, const Consignment &consignment) {
        int colorID, typeID, countryID;

        if (consignment.color != "") {
                colorID = this->getColorID(consignment.color);
                if (colorID < 0) colorID = this->addColor(consignment.color);
        }

        if (consignment.type != "") {
                typeID = this->getTypeID(consignment.type);
                if (typeID < 0) typeID = this->addType(consignment.type);
        }

        if (consignment.country != "") {
                countryID = this->getCountryID(consignment.country);
                if (countryID < 0) countryID = this->addCountry(consignment.country);
        }

        QString queryString = R"(
                        UPDATE
                                Consignment
                        SET
                                Name = :name,
                                Model = :model,
                                ColorID = :colorID,
                                TypeID = :typeID,
                                Gender = :gender,
                                Comment = :comment,
                                Cost = :cost,
                                CountryID = :countryID
                        WHERE
                                ID = :consignmentID
                              )";

        QSqlQuery query;
        query.prepare(queryString);
        query.bindValue(":name", consignment.name);
        query.bindValue(":model", consignment.model);
        query.bindValue(":colorID", colorID);
        query.bindValue(":typeID", typeID);
        query.bindValue(":gender", consignment.gender);
        query.bindValue(":comment", consignment.comment);
        query.bindValue(":cost", consignment.cost);
        query.bindValue(":countryID", countryID);
        query.bindValue(":consignmentID", consignmentID);
        query.exec();
}

int Database::addNewConsignment(const Consignment &consignment) {
        int colorID, typeID, countryID;

        if (consignment.color != "") {
                colorID = this->getColorID(consignment.color);
                if (colorID < 0) colorID = this->addColor(consignment.color);
        }

        if (consignment.type != "") {
                typeID = this->getTypeID(consignment.type);
                if (typeID < 0) typeID = this->addType(consignment.type);
        }

        if (consignment.country != "") {
                countryID = this->getCountryID(consignment.country);
                if (countryID < 0) countryID = this->addCountry(consignment.country);
        }

        QString queryString = R"(
                                INSERT INTO Consignment (Name, Model, ColorID, TypeID, Gender, Comment, Cost, CountryID)
                                VALUES (:name, :model, :colorID, :typeID, :gender, :comment, :cost, :countryID)
                              )";

        QSqlQuery query;
        query.prepare(queryString);
        query.bindValue(":name", consignment.name);
        query.bindValue(":model", consignment.model);
        query.bindValue(":colorID", colorID);
        query.bindValue(":typeID", typeID);
        query.bindValue(":gender", consignment.gender);
        query.bindValue(":comment", consignment.comment);
        query.bindValue(":cost", consignment.cost);
        query.bindValue(":countryID", countryID);
        query.exec();

        return query.lastInsertId().toInt();
}
