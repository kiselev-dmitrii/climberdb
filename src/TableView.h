#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>
#include <QSettings>
#include <QSqlQueryModel>

/** Базовый, представляющий таблицу, которая
 *  всюду будет использоваться в данном приложении.
 *  Умеет автоматически загружать настройик из QSettings.
 *  Почти весь класс можно взять из ProductsView, исключая
 *  некоторые методы.
 */
class TableView : public QTableView {
public:
        /// Конструктор.
        /// model - модель по умолчанию
        explicit        TableView(QSqlQueryModel* model, const QString& settingsName, QWidget* parent = nullptr);
        /// Деструктор
                        ~TableView();

        /// Возвращает коллекцию размеров столбцов
        QVector<int>    columnsWidth();
        /// Возвращает количество столбцов
        int             columnCount();

private:
        /// Инициализируют настройки виджета
        void            applyUiSettings();
        void            applyCommonSettings();
        void            applyCellSettings();
        void            applyHeaderSettings();
        void            applyFontSettings();

        /// Сохранение настроек виджета
        void            saveUiSettings();

private:
        QSettings       m_settings;
        QString         m_settingsName;
        Q_OBJECT
};

#endif // TABLEVIEW_H
