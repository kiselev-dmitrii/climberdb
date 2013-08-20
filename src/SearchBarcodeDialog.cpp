#include "SearchBarcodeDialog.h"
#include "ui_SearchBarcodeDialog.h"
#include "Database.h"
#include "SaleProductDialog.h"
#include "EditConsignmentDialog.h"
#include <QDebug>

SearchBarcodeDialog::SearchBarcodeDialog(QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::SearchBarcodeDialog)
{
        m_ui->setupUi(this);
        loadTable();
        connectWidgets();
}

SearchBarcodeDialog::~SearchBarcodeDialog() {
        delete m_ui;
}

void SearchBarcodeDialog::loadTable() {
        QTableView* table = m_ui->tvProduct;
        Database::instance()->barcodeProductModel()->clear();
        table->setModel(Database::instance()->barcodeProductModel());
        table->setFixedHeight(table->verticalHeader()->height()*2 - 1);
}

void SearchBarcodeDialog::connectWidgets() {
        // На изменение edtBarcode
        connect(m_ui->edtBarcode, SIGNAL(textChanged(QString)), SLOT(onEdtBarcodeChange()));
        // На нажатие btnSellProduct
        connect(m_ui->btnSellProduct, SIGNAL(clicked()), SLOT(sellProduct()));
        // На нажатие btnOpenConsignment
        connect(m_ui->btnOpenConsignment, SIGNAL(clicked()), SLOT(openConsignmentDialog()));
}

void SearchBarcodeDialog::findProductByBarcode(const QString& barcode) {
        QTableView* table = m_ui->tvProduct;

        // Обновляем данные
        Database::instance()->refreshBarcodeProductModel(barcode);
        table->hideColumn(0);
        table->hideColumn(1);

        // Устанавливаем доступность кнопок Продать и Партия
        if (table->model()->rowCount() != 0) {
                bool isSold = table->model()->data(table->model()->index(0,1)).toBool();
                if (isSold) m_ui->btnSellProduct->setEnabled(false);
                else m_ui->btnSellProduct->setEnabled(true);

                m_ui->btnOpenConsignment->setEnabled(true);
        } else {
                m_ui->btnSellProduct->setEnabled(false);
                m_ui->btnOpenConsignment->setEnabled(false);
        }
}

void SearchBarcodeDialog::onEdtBarcodeChange() {
        if (m_ui->edtBarcode->text().size() == 13) findProductByBarcode(m_ui->edtBarcode->text());
}

void SearchBarcodeDialog::sellProduct() {
        int consignmentID = m_ui->tvProduct->model()->data(m_ui->tvProduct->model()->index(0,0)).toInt();
        QString size = m_ui->tvProduct->model()->data(m_ui->tvProduct->model()->index(0,4)).toString();

        SaleProductDialog* dialog = new SaleProductDialog(consignmentID, this);
        dialog->setCurrentSize(size);
        if (dialog->exec() == QDialog::Accepted) {
                int productID = dialog->selectedProductID();
                int clientID = dialog->selectedClientID();
                int sellingCost = dialog->selectedSellingCost();
                Database::instance()->soldProduct(productID, clientID, sellingCost);

                Database::instance()->refreshMainProductsModel();
                Database::instance()->refreshMainSoldProductsModel();
                close();
        }
}

void SearchBarcodeDialog::openConsignmentDialog() {
        int consignmentID = m_ui->tvProduct->model()->data(m_ui->tvProduct->model()->index(0,0)).toInt();
        EditConsignmentDialog* dialog = new EditConsignmentDialog(consignmentID, this);
        dialog->exec();
}
