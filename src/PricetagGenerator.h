#ifndef PRICETAGGENERATOR_H
#define PRICETAGGENERATOR_H

#include <QString>
#include <QVector>
#include <QStringList>

struct TagInfo;

/** Синглтон, служащий для создания ценников
 */
class PricetagGenerator {
public:
        /// Точка доступа к объекту
        static PricetagGenerator*       instance();

        /// Возвращает количество ценников на страницу
        int                     tagsPerPage();

        /// Добавляет новый продукт к распечатке ценника
        void                    addNewProduct(int productID);

        /// Добавляет новую партию к распечатке ценника
        void                    addNewConsignment(int consignmentID);

        /// Возвращает текущее количество ценников к распечатке
        int                     countOfTags();

        /// Возвращает требуемое количество листов для распечатки
        int                     countOfPages();

        /// Возврашает количество ценников, которое необходимо добавить
        /// для полного заполнения страницы
        int                     restOfTags();

        /// Генерирует ценник в m_generatedDirectory. При успешном исполнении возвращает true
        bool                    generateTags();

        /// Удаляет все ценники
        void                    clearTags();

        /// Возвращает вектор добавленных на генерирование ценников
        const QVector<TagInfo>& tags();

        /// Удаляет i-тый ценник
        void                    removeTag(int i);

        /// Возвращает путь к сгенерированным ценникам
        QString                 pathToTags();

private:
        /// Генерирует Html код ценника
        QString         generateHtml(const QString& header, const QString& tagTemplate);

private:
        /// Закрытые конструкторы и оператор присваивания
        PricetagGenerator();
        PricetagGenerator(const PricetagGenerator&);
        PricetagGenerator& operator=(const PricetagGenerator&);

private:
        const int               m_tagsPerPage;
        const int               m_countCols;

        QVector<TagInfo>        m_tags;

        const QString           m_templateDirectory;
        const QString           m_generatedDirectory;
        const QString           m_logoFilename;
        const QString           m_templateFilename;
        const QString           m_headerFlename;
        const QString           m_tagsFilename;
};

/** Информация, используемая при печати ценников
 */
struct TagInfo {
        QString                 name;
        QString                 model;
        QString                 size;
        QStringList             sizes;
        int                     cost;
        QString                 barcode;
};

#endif // PRICETAGGENERATOR_H
