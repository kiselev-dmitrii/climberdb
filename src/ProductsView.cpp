#include "ProductsView.h"
#include <QMenu>
#include <QContextMenuEvent>

ProductsView::ProductsView(QSqlQueryModel *model, QWidget *parent) :
        TableView(model, "ProductView", parent),
        m_contextMenu(nullptr)
{
        createContextMenu();
}

void ProductsView::createContextMenu() {
        m_contextMenu = new QMenu(this);
        m_contextMenu->addAction("&Продать");
        m_contextMenu->addAction("Распечатать ценник");
        m_contextMenu->addSeparator();
        m_contextMenu->addAction("&Редактировать");
        m_contextMenu->addAction("Удалить");
}

void ProductsView::contextMenuEvent(QContextMenuEvent *ev) {
        m_contextMenu->exec(ev->globalPos());
}
