#ifndef SOLDPRODUCTSVIEW_H
#define SOLDPRODUCTSVIEW_H
#include "TableView.h"

/** Таблица проданных товаров.
 */
class SoldProductsView : public TableView {
public:
        /// Конструктор
        explicit        SoldProductsView(QSqlQueryModel* model, QWidget* parent = nullptr);
};

#endif // SOLDPRODUCTSVIEW_H
