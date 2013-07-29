#ifndef PRODUCTSVIEW_H
#define PRODUCTSVIEW_H

#include <QTableView>
#include <QSettings>
#include <qDebug>
#include <QSqlQueryModel>


/** Класс, представляющий собой основную таблицу товаров
 *  на окне.
 */
class ProductsView : public QTableView {
public:
        /// Конструктор
        explicit        ProductsView(QWidget *parent = 0);
        /// Деструктор
                        ~ProductsView();

        /// Возвращает коллекцию размеров столбцов
        QVector<int>    columnsWidth();
        /// Возвращает количество столбцов
        int             columnCount();

private:
        /// Загружает таблицу данными из БД
        void            loadView();

        /// Создает контекстное меню
        void            createContextMenu();

        /// Инициализируют настройки виджета
        void            applyUiSettings();
        void            applyCellSettings();
        void            applyHeaderSettings();
        void            applyFontSettings();

        /// Сохранение настроек виджета
        void            saveUiSettings();

private:
        /// События
        void            contextMenuEvent(QContextMenuEvent *ev);

private:
        QSettings       m_settings;
        QMenu*          m_contextMenu;
        QSqlQueryModel* m_model;
        Q_OBJECT

};

#endif // PRODUCTSVIEW_H
