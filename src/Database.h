#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlQueryModel>
#include <QStringList>
#include <QDateTime>

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

/** Синглтон, служащий для доступа к базе данных
 */
class Database {
public:
        /// Точка доступа к объекту
        static Database*        instance();

        /// Возвращает модель для основной таблицы продуктов
        void                    getAllProductsModel(QSqlQueryModel* sqlModel, const QString& name, const QString& model, const QString& size,
                                                    const QString& cost, const QString& type, const QString& gender,
                                                    const QString& comment, const QString& color, const QString& country);

        /// Возвращает список проданного товара за конкретный день
        void                    getSoldProductsOnDate(QSqlQueryModel* sqlModel, const QDate& soldDate);

        /// Вовзвращает список размеров из данной партии, которые еще не проданы
        QVector<Product>        getProductListFromConsignment(int consignmentID);

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
};

#endif // DATABASE_H
