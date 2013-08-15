#include "ClientsDialog.h"
#include "ui_ClientsDialog.h"
#include "Database.h"
#include <QModelIndex>
#include <QDebug>
#include <QContextMenuEvent>

ClientsDialog::ClientsDialog(QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::ClientsDialog),
        m_contextMenu(nullptr)
{
        m_ui->setupUi(this);
        loadClientsData();
        createContextMenu();
        connectWidgets();
}

ClientsDialog::~ClientsDialog() {
        delete m_ui;
}

void ClientsDialog::loadClientsData() {
        Database::instance()->refreshClientsModel();
        m_ui->tvClients->setModel(Database::instance()->clientsModel());
        m_ui->tvClients->horizontalHeader()->hideSection(0);
}

void ClientsDialog::createContextMenu() {
        m_contextMenu = new QMenu(this);
        m_contextMenu->addAction("Удалить");
}

void ClientsDialog::connectWidgets() {
        // Кнопки Добавить и Изменить
        connect(m_ui->btnAdd, SIGNAL(clicked()), SLOT(addNewClient()));
        connect(m_ui->btnChange, SIGNAL(clicked()), SLOT(changeClientData()));

        // Выбор записи
        connect(m_ui->tvClients->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), SLOT(onSelectClient(QModelIndex,QModelIndex)));

        // Обработка пунктов меню
        connect(m_contextMenu, SIGNAL(triggered(QAction*)), SLOT(processMenuActions(QAction*)));
}

void ClientsDialog::refreshAddingPanel(int row) {
        QModelIndex i;

        i = m_ui->tvClients->model()->index(row, 1);
        QString name = m_ui->tvClients->model()->data(i).toString();

        i = m_ui->tvClients->model()->index(row, 2);
        QString surname = m_ui->tvClients->model()->data(i).toString();

        i = m_ui->tvClients->model()->index(row, 3);
        QString mobile = m_ui->tvClients->model()->data(i).toString();

        i = m_ui->tvClients->model()->index(row, 4);
        QString address = m_ui->tvClients->model()->data(i).toString();

        i = m_ui->tvClients->model()->index(row, 5);
        QString discount = m_ui->tvClients->model()->data(i).toString();
        discount.remove(discount.length()-2, 2);

        m_ui->edtName->setText(name);
        m_ui->edtSurname->setText(surname);
        m_ui->edtMobile->setText(mobile);
        m_ui->edtAddress->setText(address);
        m_ui->spnDiscount->setValue(discount.toFloat());
}

int ClientsDialog::selectedClientID() {
        QTableView* table = m_ui->tvClients;

        int row = table->currentIndex().row();
        QModelIndex index = table->model()->index(row, 0);
        return table->model()->data(index).toInt();
}

void ClientsDialog::removeSelectedClient() {
        int clientID = selectedClientID();
        Database::instance()->removeClient(clientID);
        Database::instance()->refreshClientsModel();
}

void ClientsDialog::contextMenuEvent(QContextMenuEvent *event) {
        Q_ASSERT(m_contextMenu != nullptr);
        m_contextMenu->exec(event->globalPos());
}

void ClientsDialog::addNewClient() {
        Client client;
        client.name = m_ui->edtName->text();
        client.surname = m_ui->edtSurname->text();
        client.mobile = m_ui->edtMobile->text();
        client.address = m_ui->edtAddress->text();
        client.discount = m_ui->spnDiscount->value()/100.0;

        Database::instance()->addNewClient(client);
        Database::instance()->refreshClientsModel();
}

void ClientsDialog::changeClientData() {
        Client client;
        client.name = m_ui->edtName->text();
        client.surname = m_ui->edtSurname->text();
        client.mobile = m_ui->edtMobile->text();
        client.address = m_ui->edtAddress->text();
        client.discount = m_ui->spnDiscount->value()/100.0;

        int clientID = selectedClientID();

        Database::instance()->editClientInfo(clientID, client);
        Database::instance()->refreshClientsModel();
}

void ClientsDialog::onSelectClient(const QModelIndex& newIndex, const QModelIndex& oldIndex) {
        Q_UNUSED(oldIndex);

        int row = newIndex.row();
        qDebug() << row;
        refreshAddingPanel(row);
}

void ClientsDialog::processMenuActions(QAction *action) {
        if (action->text() == "Удалить") removeSelectedClient();
}
