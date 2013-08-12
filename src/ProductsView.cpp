#include "ProductsView.h"
#include <QMenu>
#include <QContextMenuEvent>
#include <QDebug>
#include <QInputDialog>
#include "Database.h"
#include "ConsignmentDialog.h"

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

void ProductsView::keyPressEvent(QKeyEvent *event) {
        if (event->key() == Qt::Key_Return) {
                processEditAction(selectedConsignmentID());
        }
        QTableView::keyPressEvent(event);

}

int ProductsView::selectedConsignmentID() {
        int row = this->selectedIndexes()[0].row();
        QModelIndex index = this->model()->index(row, columnCount()-1);
        return this->model()->data(index).toInt();
}

void ProductsView::processMenuActions(QAction *action) {
        // Получаем ID партии
        int consignmentID = selectedConsignmentID();

        // Обрабатываем пункты меню
        if (action->text() == "Продать") processSaleAction(consignmentID);
        if (action->text() == "Редактировать") processEditAction(consignmentID);
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

void ProductsView::processEditAction(int id) {
        ConsignmentDialog* dialog = new ConsignmentDialog(id, this);
        if (dialog->exec() == QDialog::Accepted) {
                // Обновляем модели и восстанавливаем выделение
                QModelIndexList selectedIndexes = this->selectedIndexes();
                Database::instance()->refreshMainProductsModel();
                if (selectedIndexes.size() != 0) this->setCurrentIndex(selectedIndexes[0]);
                Database::instance()->refreshMainSoldProductsModel();
        }
}
