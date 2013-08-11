#include "SoldProductsView.h"

SoldProductsView::SoldProductsView(QSqlQueryModel *model, QWidget *parent) :
        TableView(model, "SoldProductView", parent)
{
}
