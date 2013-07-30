#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlQueryModel>

/** Синглтон, служащий для доступа к базе данных
 */
class Database {
public:
        /// Точка доступа к объекту
        static Database*        instance();

        /// Возвращает модель для основной таблицы продуктов
        QSqlQueryModel* getAllProductsModel(const QString& name, const QString& model, const QString& size,
                                            const QString& cost, const QString& type, const QString& gender,
                                            const QString& comment, const QString& color, const QString& country);

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
        QSqlQueryModel          m_allProductsModel;
};

#endif // DATABASE_H
