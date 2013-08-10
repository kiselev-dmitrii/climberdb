#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlQueryModel>
#include <QStringList>
#include <QDateTime>

struct Product;

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

        /// Вовзвращает список размеров из данной партии, которые еще не проданы
        QVector<Product>        getProductListFromConsignment(int consignmentID);

        /// Помещает товар с индексом productID в список проданных
        void                    soldProduct(int productID);

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
