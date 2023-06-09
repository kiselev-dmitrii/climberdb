#include "SoldProductsView.h"
#include <QContextMenuEvent>
#include <QDebug>
#include <QHeaderView>
#include "ClientsDialog.h"
#include "EditConsignmentDialog.h"
#include "Database.h"

SoldProductsView::SoldProductsView(QSqlQueryModel *model, QWidget *parent) :
        TableView(model, "SoldProductView", parent),
        m_contextMenu(nullptr)
{
        createContextMenu();
        horizontalHeader()->hideSection(0);     //в первом столбце храним ProductID
}

void SoldProductsView::createContextMenu() {
        m_contextMenu = new QMenu(this);
        m_contextMenu->addAction("Возвратить товар");
        m_contextMenu->addSeparator();
        m_contextMenu->addAction("Размеры в наличии");
        m_contextMenu->addAction("Подробнее о клиенте");

        connect(m_contextMenu, SIGNAL(triggered(QAction*)), this, SLOT(processMenuActions(QAction*)));
}

void SoldProductsView::processMenuActions(QAction *action) {
        int productID = selectedProductID();
        Product product = Database::instance()->getProductByID(productID);

        if (action->text() == "Возвратить товар") processReturnProductAction(productID);
        else if (action->text() == "Подробнее о клиенте") processAboutClientAction(product.clientID);
        else if (action->text() == "Размеры в наличии") processOtherSize(product.consignmentID);
}

void SoldProductsView::processReturnProductAction(int productID) {
        Database::instance()->returnProduct(productID);
        Database::instance()->refreshMainSoldProductsModel();
        Database::instance()->refreshMainProductsModel();
}

void SoldProductsView::processAboutClientAction(int clientID) {
        ClientsDialog* dialog = new ClientsDialog(this, clientID);
        dialog->exec();
}

void SoldProductsView::processOtherSize(int consignmentID) {
        EditConsignmentDialog* dialog = new EditConsignmentDialog(consignmentID, this);
        dialog->exec();
}

void SoldProductsView::contextMenuEvent(QContextMenuEvent *ev) {
        Q_ASSERT(m_contextMenu != nullptr);
        if (selectedIndexes().size() != 0) m_contextMenu->exec(ev->globalPos());
}

int SoldProductsView::selectedProductID() {
        int row = this->selectedIndexes()[0].row();
        QModelIndex index = this->model()->index(row, 0);
        return this->model()->data(index).toInt();
}
