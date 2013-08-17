#ifndef SOLDPRODUCTSVIEW_H
#define SOLDPRODUCTSVIEW_H

#include <QMenu>
#include "TableView.h"

/** Таблица проданных товаров.
 */
class SoldProductsView : public TableView {
public:
        /// Конструктор
        explicit        SoldProductsView(QSqlQueryModel* model, QWidget* parent = nullptr);

private slots:
        /// Обработка пунктов меню
        void            processMenuActions(QAction* action);
        void            processReturnProductAction(int productID);
        void            processAboutClientAction(int clientID);
        void            processOtherSize(int consignmentID);

private:
        /// Создает контекстное меню
        void            createContextMenu();
        /// Событие на нажатие правой кнопки мыши
        void            contextMenuEvent(QContextMenuEvent *ev);

        /// Возвращает ProductID выделенного товара
        int             selectedProductID();

private:
        QMenu*          m_contextMenu;
        Q_OBJECT
};

#endif // SOLDPRODUCTSVIEW_H
