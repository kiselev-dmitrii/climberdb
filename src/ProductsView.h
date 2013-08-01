#ifndef PRODUCTSVIEW_H
#define PRODUCTSVIEW_H

#include "TableView.h"

/** Класс, представляющий собой основную таблицу товаров
 *  на окне.
 */
class ProductsView : public TableView {
public:
        /// Конструктор
        explicit        ProductsView(QSqlQueryModel* model, QWidget *parent = nullptr);

private:
        /// Создает контекстное меню
        void            createContextMenu();
        /// Событие на нажатие правой кнопки мыши
        void            contextMenuEvent(QContextMenuEvent *ev);

private slots:
        /// Обработка пунктов меню
        void            processMenuActions(QAction* action);
        void            processSaleAction(int id);

private:
        QMenu*          m_contextMenu;
        Q_OBJECT

};

#endif // PRODUCTSVIEW_H
