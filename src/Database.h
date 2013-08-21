#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlQueryModel>
#include <QStringList>
#include <QDateTime>
#include <tuple>

using std::tuple;

struct Product;
struct Consignment;
struct Client;
struct ProductFilter;

/** Синглтон, служащий для доступа к базе данных
 */
class Database {
public:
        /// Точка доступа к объекту
        static Database*        instance();

        /// Возвращает/обновляет/обновляет новым запросом модель всех продуктов
        QSqlQueryModel*         mainProductsModel();
        QSqlQueryModel*         refreshMainProductsModel();
        QSqlQueryModel*         refreshMainProductsModel(const QString& name, const QString& model, const QString& size,
                                                         const QString& cost, const QString& type, const QString& gender,
                                                         const QString& comment, const QString& color, const QString& country);

        /// Возвращает/обновляет/обновляет новым запросом модель всех проданных продуктов
        QSqlQueryModel*         mainSoldProductsModel();
        QSqlQueryModel*         refreshMainSoldProductsModel();
        QSqlQueryModel*         refreshMainSoldProductsModel(const QDate& soldDate);

        /// Возвращает модель непроданных товаров для партии с индексом consignmentID
        QSqlQueryModel*         dialogSizesModel();
        QSqlQueryModel*         refreshDialogSizesModel();
        QSqlQueryModel*         refreshDialogSizesModel(int consignmentID);

        /// Возвращает модель всех клиентов
        QSqlQueryModel*         clientsModel();
        QSqlQueryModel*         refreshClientsModel();

        /// Возвращает модель, которая содержит лишь одну запись (используется для диалога поиска по штрихкоду)
        QSqlQueryModel*         barcodeProductModel();
        QSqlQueryModel*         refreshBarcodeProductModel(const QString& barcode);


        /// Возвращает модель проданных товаров (специально для соответствующего диалога)
        QSqlQueryModel*         productsSoldModel();
        QSqlQueryModel*         refreshProductsSoldModel();
        QSqlQueryModel*         refreshProductsSoldModel(const QString& name, const QString& model, const QString& size,
                                                         const QString& type, const QDate& from, const QDate& to);

        /// Добавляет новую запись в таблицу клиентов (Name, Surname, Mobile, Address, Discount).
        /// Возвращает ClientID
        int                     addNewClient(const Client& client);
        /// Обновляет запись о клиенте (Name, Surname, Mobile, Address, Discount)
        void                    editClientInfo(int clientID, const Client& client);
        /// Удаляет запись о клиенте
        void                    removeClient(int clientID);

        /// Вовзвращает список товара из данной партии, которые еще не проданы
        QVector<Product>        getProductListFromConsignment(int consignmentID);
        /// Возвращает список размеров из данной партии
        QStringList             getSizeListFromConsignment(int consignmentID);
        /// Возвращает информацию о партии с данным ID
        Consignment             getConsignmentByID(int consignmentID);
        /// Возвращает информацию о товаре по productID
        Product                 getProductByID(int productID);

        /// Возвращает количество и сумму проданного товара по маске за заданную дату
        tuple<int, int>         getCountAndSumOfSoldProducts(const QDate& from, const QDate& to, const ProductFilter& filter);
        /// Возвращает количество и сумму купленного товара по маске за заданную дату
        tuple<int, int>         getCountAndSumOfPurchasedProducts(const QDate& from, const QDate& to, const ProductFilter& filter);

        /// Возвращает список возможных цветов, типов, производителей
        QStringList             getAvailableColors();
        QStringList             getAvailableTypes();
        QStringList             getAvailableCountries();

        /// Получение ID по имени
        int                     getColorID(const QString& color);
        int                     getTypeID(const QString& type);
        int                     getCountryID(const QString& country);

        /// Добавляет новый цвет, тип, производителя и возвращает его ID
        int                     addColor(const QString& color);
        int                     addType(const QString& type);
        int                     addCountry(const QString& country);

        /// Добавляет новые размеры в партию consignmentID
        void                    addNewProducts(int consignmentID, const QStringList& sizes);

        /// Помещает товар с индексом productID в список проданных. clientID указывается в качестве покупателя
        void                    soldProduct(int productID, int clientID, int sellingCost);

        /// Делает возврат товара
        void                    returnProduct(int productID);

        /// Редактирование размера и даты добавления продукта
        void                    editProductSize(int productID, const QString& newSize);
        void                    editProductDeliveryDate(int productID, const QDateTime& newDeliveryDate);
        /// Удалеиние продукта
        void                    removeProduct(int productID);

        /// Обновляет данные, касающиеся партии с consignmentID
        void                    updateConsignment(int consignmentID, const Consignment& consignment);

        /// Добавляет новую партию и возвращает его ConsignmentID
        int                     addNewConsignment(const Consignment& consignment);

private:
        /// Закрытые конструкторы и оператор присваивания
        Database();
        Database(const Database&);
        Database& operator=(const Database&);

private:
        /// Создает подключение к БД
        /// Возвращает false при неудаче
        bool                    createConnction();

private:
        QSqlDatabase            m_db;
        QString                 m_dbName;

private:
        /// Модели для всех таблиц в приложении
        QSqlQueryModel          m_mainProductsModel;
        QSqlQueryModel          m_mainSoldProductsModel;
        QSqlQueryModel          m_dialogSizesModel;
        QSqlQueryModel          m_clientsModel;
        QSqlQueryModel          m_productsSoldModel;
        QSqlQueryModel          m_barcodeProductModel;
};


/** Структура клиента
 */
struct Client {
        int             id;
        QString         name;
        QString         surname;
        QString         mobile;
        QString         address;
        float           discount;
        int             countBuy;
        int             countReturns;
        float           rating;
};

/** Структура партии
 */
struct Consignment {
        int             id;
        QString         name;
        QString         model;
        QString         color;
        QString         type;
        QString         gender;
        QString         comment;
        int             cost;
        QString         country;
};

/** Структура записи в таблице Product
 */
struct Product {
        int             id;
        int             consignmentID;
        QString         size;
        QString         barcode;
        bool            isSold;
        int             sellingCost;
        QDateTime       deliveryDate;
        QDateTime       saleDate;
        QDateTime       lastReturnDate;
        int             countReturns;
        int             clientID;
};

/** Структура, которая используется для передачи в функции поиска по фильтру
 */
struct ProductFilter {
        QString         name;
        QString         model;
        QString         size;
        QString         type;

        QString         cost;
        QString         gender;
        QString         comment;
        QString         color;
        QString         country;
};

#endif // DATABASE_H
