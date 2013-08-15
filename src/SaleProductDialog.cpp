#include "SaleProductDialog.h"
#include "ui_SaleProductDialog.h"
#include "ClientsDialog.h"
#include <QDebug>

SaleProductDialog::SaleProductDialog(int consignmentID, QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::saleProductDialog),
        m_consignmentID(consignmentID),
        m_selectedClientID(0),
        m_selectedProductID(0)
{
        m_ui->setupUi(this);
        loadAvailableSize();
        loadAvailableClients();
        connectWidgets();
}

SaleProductDialog::~SaleProductDialog() {
        delete m_ui;
}

int SaleProductDialog::selectedClientID() {
        return m_selectedClientID;
}

int SaleProductDialog::selectedProductID() {
        return m_selectedProductID;
}

void SaleProductDialog::loadAvailableSize() {
        Database::instance()->refreshDialogSizesModel(m_consignmentID);
        m_ui->cbSize->setModel(Database::instance()->dialogSizesModel());
        m_ui->cbSize->setModelColumn(1);
        m_ui->cbSize->setCurrentIndex(-1);
}

void SaleProductDialog::loadAvailableClients() {
        Database::instance()->refreshClientsModel();
        m_ui->cbClient->setModel(Database::instance()->clientsModel());
        m_ui->cbClient->setModelColumn(6);
        m_ui->cbClient->setCurrentIndex(-1);
}

void SaleProductDialog::connectWidgets() {
        // Кнопки Ok, Cancel
        connect(m_ui->btnBox, SIGNAL(accepted()), SLOT(accept()));
        connect(m_ui->btnBox, SIGNAL(rejected()), SLOT(reject()));

        // Кнопка добавления клиента
        connect(m_ui->btnAddClient, SIGNAL(clicked()), SLOT(openClientsDialog()));

        // При изменении клиента и размера
        connect(m_ui->cbClient, SIGNAL(currentIndexChanged(int)), SLOT(onChangeClient(int)));
        connect(m_ui->cbSize, SIGNAL(currentIndexChanged(int)), SLOT(onChangeSize(int)));
}

void SaleProductDialog::openClientsDialog() {
        ClientsDialog* dialog = new ClientsDialog(this);
        dialog->exec();
}

void SaleProductDialog::onChangeClient(int index) {
        m_selectedClientID = m_ui->cbClient->model()->data(m_ui->cbClient->model()->index(index, 0)).toInt();
}

void SaleProductDialog::onChangeSize(int index) {
        m_selectedProductID = m_ui->cbSize->model()->data(m_ui->cbSize->model()->index(index, 0)).toInt();
}
