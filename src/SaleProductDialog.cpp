#include "SaleProductDialog.h"
#include "ui_SaleProductDialog.h"
#include "ClientsDialog.h"
#include <QDebug>

SaleProductDialog::SaleProductDialog(int consignmentID, QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::saleProductDialog),
        m_consignmentID(consignmentID),
        m_selectedClientID(0),
        m_selectedProductID(0),
        m_defaultCost(0)
{
        m_ui->setupUi(this);
        loadAvailableSize();
        loadAvailableClients();
        loadDefaultCost();
        onDiscountClick();
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

void SaleProductDialog::loadDefaultCost() {
        Consignment consignment = Database::instance()->getConsignmentByID(m_consignmentID);
        m_defaultCost = consignment.cost;

        // Устанавливаем минимум и максимум
        m_ui->spnCost->setMaximum(m_defaultCost);
        m_ui->spnDiscount->setMaximum(m_defaultCost);
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

        // Скидка и стоимость
        connect(m_ui->chbDiscount, SIGNAL(clicked()), SLOT(onDiscountClick()));
        connect(m_ui->spnDiscount, SIGNAL(valueChanged(int)), SLOT(onDiscountChange(int)));
        connect(m_ui->spnCost, SIGNAL(valueChanged(int)), SLOT(onSellingCostChange(int)));
}

float SaleProductDialog::currentClientDiscount() {
        QString discount = m_ui->cbClient->model()->data(m_ui->cbClient->model()->index(m_ui->cbClient->currentIndex(), 5)).toString();
        discount.remove(discount.length()-2, 2);
        return discount.toFloat();
}

void SaleProductDialog::openClientsDialog() {
        ClientsDialog* dialog = new ClientsDialog(this);
        dialog->exec();
}

void SaleProductDialog::onChangeClient(int index) {
        // Изменяем выбранного клиента
        m_selectedClientID = m_ui->cbClient->model()->data(m_ui->cbClient->model()->index(index, 0)).toInt();
        // Меняем скидку
        onDiscountClick();
}

void SaleProductDialog::onChangeSize(int index) {
        m_selectedProductID = m_ui->cbSize->model()->data(m_ui->cbSize->model()->index(index, 0)).toInt();
}

void SaleProductDialog::onDiscountClick() {
        if (m_ui->chbDiscount->isChecked()) {
                m_ui->spnDiscount->setEnabled(true);
                m_ui->spnCost->setEnabled(true);

                float discount = currentClientDiscount();
                m_ui->spnDiscount->setValue(m_defaultCost*(discount/100.0));
                m_ui->spnCost->setValue(m_defaultCost - m_ui->spnDiscount->value());
        } else {
                m_ui->spnDiscount->setEnabled(false);
                m_ui->spnCost->setEnabled(false);

                m_ui->spnDiscount->setValue(0);
                m_ui->spnCost->setValue(m_defaultCost - m_ui->spnDiscount->value());
        }
}

void SaleProductDialog::onDiscountChange(int value) {
        m_ui->spnCost->setValue(m_defaultCost - value);
}

void SaleProductDialog::onSellingCostChange(int value) {
        m_ui->spnDiscount->setValue(m_defaultCost - value);
}
