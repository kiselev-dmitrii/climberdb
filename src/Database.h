#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlQueryModel>
#include <QStringList>
#include <QDateTime>

struct Product;
struct Consignment;

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

        /// Вовзвращает список товара из данной партии, которые еще не проданы
        QVector<Product>        getProductListFromConsignment(int consignmentID);
        /// Возвращает информацию о партии с данным ID
        Consignment             getConsignmentByID(int consignmentID);

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
        void                    addNewSizes(int consignmentID, const QStringList& sizes);

        /// Возвращает модель непроданных товаров для партии с индексом consignmentID
        QSqlQueryModel*         dialogSizesModel();
        QSqlQueryModel*         refreshDialogSizesModel();
        QSqlQueryModel*         refreshDialogSizesModel(int consignmentID);

        /// Помещает товар с индексом productID в список проданных
        void                    soldProduct(int productID);

        /// Обновляет данные, касающиеся партии с consignmentID
        void                    updateConsignment(int consignmentID, const Consignment& consignment);

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
        QDateTime       deliveryDate;
        QDateTime       saleDate;
        QDateTime       lastReturnDate;
        int             countReturns;
        int             clientID;
};

#endif // DATABASE_H
