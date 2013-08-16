#include "ProductsView.h"
#include <QMenu>
#include <QContextMenuEvent>
#include <QDebug>
#include <QInputDialog>
#include <QHeaderView>
#include <QMessageBox>
#include "Database.h"
#include "EditConsignmentDialog.h"
#include "CreateConsignmentDialog.h"
#include "SaleProductDialog.h"
#include "PricetagGenerator.h"

ProductsView::ProductsView(QSqlQueryModel *model, QWidget *parent) :
        TableView(model, "ProductView", parent),
        m_contextMenu(nullptr)
{
        createContextMenu();
}

void ProductsView::createContextMenu() {
        m_contextMenu = new QMenu(this);
        m_contextMenu->addAction("Добавить");
        m_contextMenu->addAction("Продать");
        m_contextMenu->addAction("Генерировать ценники");
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
        else if (action->text() == "Редактировать") processEditAction(consignmentID);
        else if (action->text() == "Добавить") processAddAction();
        else if (action->text() == "Генерировать ценники") processGeneratePricetags(consignmentID);

}

void ProductsView::processSaleAction(int consignmentID) {
        // Формируем список размеров
        SaleProductDialog* dialog = new SaleProductDialog(consignmentID, this);
        if (dialog->exec() == QDialog::Accepted) {
                int productID = dialog->selectedProductID();
                int clientID = dialog->selectedClientID();
                Database::instance()->soldProduct(productID, clientID);

                Database::instance()->refreshMainProductsModel();
                Database::instance()->refreshMainSoldProductsModel();
        }
}

void ProductsView::processEditAction(int id) {
        EditConsignmentDialog* dialog = new EditConsignmentDialog(id, this);
        if (dialog->exec() == QDialog::Accepted) {
                // Обновляем модели и восстанавливаем выделение
                QModelIndexList selectedIndexes = this->selectedIndexes();
                Database::instance()->refreshMainProductsModel();
                if (selectedIndexes.size() != 0) this->setCurrentIndex(selectedIndexes[0]);
                Database::instance()->refreshMainSoldProductsModel();
        }
}

void ProductsView::processAddAction() {
        CreateConsignmentDialog* dialog = new CreateConsignmentDialog(this);
        dialog->exec();
}

void ProductsView::processGeneratePricetags(int consignmentID) {
        PricetagGenerator::instance()->addNewConsignment(consignmentID);
        int countOfTags = PricetagGenerator::instance()->countOfTags();
        int restOfTags = PricetagGenerator::instance()->restOfTags();

        QMessageBox msgBox;
        msgBox.setWindowTitle("Ценники добавлены");
        QString msg = "Партия добавлена в очередь на распечатку.\n " \
                      "Всего к распечатке " + QString::number(countOfTags) + ".\n" \
                      "До заполнения страницы осталось добавить " + QString::number(restOfTags) + " ценников";
        msgBox.setText(msg);
        msgBox.exec();
}
