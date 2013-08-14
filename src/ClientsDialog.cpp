#include "ClientsDialog.h"
#include "ui_ClientsDialog.h"
#include "Database.h"
#include <QModelIndex>
#include <QDebug>

ClientsDialog::ClientsDialog(QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::ClientsDialog)
{
        m_ui->setupUi(this);
        loadClientsData();
        connectWidgets();
}

ClientsDialog::~ClientsDialog() {
        delete m_ui;
}

void ClientsDialog::loadClientsData() {
        Database::instance()->refreshClientsModel();
        m_ui->tvClients->setModel(Database::instance()->clientsModel());
}

void ClientsDialog::connectWidgets() {
        /// Кнопки Добавить и Изменить
        connect(m_ui->btnAdd, SIGNAL(clicked()), SLOT(addNewClient()));
        connect(m_ui->btnChange, SIGNAL(clicked()), SLOT(changeClientData()));

        /// Выбор записи
        connect(m_ui->tvClients, SIGNAL(clicked(QModelIndex)), SLOT(onSelectClient(QModelIndex)));
}

void ClientsDialog::refreshAddingPanel(int row) {
        QModelIndex i;

        i = m_ui->tvClients->model()->index(row, 0);
        QString name = m_ui->tvClients->model()->data(i).toString();

        i = m_ui->tvClients->model()->index(row, 1);
        QString surname = m_ui->tvClients->model()->data(i).toString();

        i = m_ui->tvClients->model()->index(row, 2);
        QString mobile = m_ui->tvClients->model()->data(i).toString();

        i = m_ui->tvClients->model()->index(row, 3);
        QString address = m_ui->tvClients->model()->data(i).toString();

        i = m_ui->tvClients->model()->index(row, 4);
        QString discount = m_ui->tvClients->model()->data(i).toString();
        discount.remove(discount.length()-2, 2);

        m_ui->edtName->setText(name);
        m_ui->edtSurname->setText(surname);
        m_ui->edtMobile->setText(mobile);
        m_ui->edtAddress->setText(address);
        m_ui->spnDiscount->setValue(discount.toFloat());
}

void ClientsDialog::addNewClient() {

}

void ClientsDialog::changeClientData() {

}

void ClientsDialog::onSelectClient(const QModelIndex& index) {
        int row = index.row();
        qDebug() << row;
        refreshAddingPanel(row);
}
