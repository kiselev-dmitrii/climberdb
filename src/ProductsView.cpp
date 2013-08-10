#include "ProductsView.h"
#include <QMenu>
#include <QContextMenuEvent>
#include <QDebug>
#include <QInputDialog>
#include "Database.h"

ProductsView::ProductsView(QSqlQueryModel *model, QWidget *parent) :
        TableView(model, "ProductView", parent),
        m_contextMenu(nullptr)
{
        createContextMenu();
}

void ProductsView::createContextMenu() {
        m_contextMenu = new QMenu(this);
        m_contextMenu->addAction("Продать");
        m_contextMenu->addAction("Распечатать ценник");
        m_contextMenu->addSeparator();
        m_contextMenu->addAction("Редактировать");
        m_contextMenu->addAction("Удалить");

        connect(m_contextMenu, SIGNAL(triggered(QAction*)), SLOT(processMenuActions(QAction*)));
}

void ProductsView::contextMenuEvent(QContextMenuEvent *ev) {
        m_contextMenu->exec(ev->globalPos());
}

void ProductsView::processMenuActions(QAction *action) {
        // Получаем ID партии
        int row = this->selectedIndexes()[0].row();
        QModelIndex index = this->model()->index(row, columnCount()-1);
        int consignmentID = this->model()->data(index).toInt();

        // Обрабатываем пункты меню
        if (action->text() == "Продать") processSaleAction(consignmentID);
}

void ProductsView::processSaleAction(int id) {
        // Формируем список размеров
        QVector<Product> products = Database::instance()->getProductListFromConsignment(id);
        QStringList items;
        for (auto &product: products) items.append(product.size);

        // Создаем окно
        bool ok;
        QString selectedSize = QInputDialog::getItem(this, "Продажа", "Выберите размер для продажи", items, 0, false, &ok);


        if (ok) {
                for (auto &product: products) {
                        if (product.size == selectedSize) {
                                QModelIndex selectedIndex = this->selectedIndexes()[0];

                                Database::instance()->soldProduct(product.id);
                                Database::instance()->refreshMainProductsModel();
                                Database::instance()->refreshMainSoldProductsModel();

                                this->setCurrentIndex(selectedIndex);

                                break;
                        }
                }
        }

}
