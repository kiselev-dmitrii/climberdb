#include "SaleProductDialog.h"
#include "ui_SaleProductDialog.h"
#include "ClientsDialog.h"

SaleProductDialog::SaleProductDialog(int consignmentID, QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::saleProductDialog),
        m_consignmentID(consignmentID)
{
        m_ui->setupUi(this);
        loadAvailableSize();
        loadAvailableClients();
        connectWidgets();
}

SaleProductDialog::~SaleProductDialog() {
        delete m_ui;
}

void SaleProductDialog::loadAvailableSize() {
        m_availableProducts = Database::instance()->getProductListFromConsignment(m_consignmentID);

        QStringList items;
        for (Product product: m_availableProducts) items.append(product.size);
        m_ui->cbSize->addItems(items);
}

void SaleProductDialog::loadAvailableClients() {

}

void SaleProductDialog::connectWidgets() {
        // Кнопки Ok, Cancel
        connect(m_ui->btnBox, SIGNAL(accepted()), SLOT(accept()));
        connect(m_ui->btnBox, SIGNAL(rejected()), SLOT(reject()));

        // Кнопка добавления клиента
        connect(m_ui->btnAddClient, SIGNAL(clicked()), SLOT(openClientsDialog()));
}

void SaleProductDialog::openClientsDialog() {
        ClientsDialog* dialog = new ClientsDialog(this);
        dialog->exec();
}
