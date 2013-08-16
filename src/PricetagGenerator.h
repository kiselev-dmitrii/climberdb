#ifndef PRICETAGGENERATOR_H
#define PRICETAGGENERATOR_H

#include <QString>
#include <QVector>

struct TagInfo;

/** Синглтон, служащий для создания ценников
 */
class PricetagGenerator {
public:
        /// Точка доступа к объекту
        static PricetagGenerator*       instance();

        /// Возвращает количество ценников на страницу
        int             tagsPerPage();

        /// Добавляет новый продукт к распечатке ценника
        void            addNewProduct(int productID);

        /// Добавляет новую партию к распечатке ценника
        void            addNewConsignment(int consignmentID);

        /// Возвращает текущее количество ценников к распечатке
        int             countOfTags();

        /// Возвращает требуемое количество листов для распечатки
        int             countOfPages();

        /// Возврашает количество ценников, которое необходимо добавить
        /// для полного заполнения страницы
        int             restOfTags();

private:
        /// Закрытые конструкторы и оператор присваивания
        PricetagGenerator();
        PricetagGenerator(const PricetagGenerator&);
        PricetagGenerator& operator=(const PricetagGenerator&);

private:
        const int               m_tagsPerPage;
        QVector<TagInfo>        m_tags;

};

/** Информация, используемая при печати ценников
 */
struct TagInfo {
        QString                 name;
        QString                 model;
        QString                 size;
        QVector<QString>        sizes;
        int                     cost;
        QString                 barcode;
};

#endif // PRICETAGGENERATOR_H
