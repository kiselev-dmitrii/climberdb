#include "ClientsDialog.h"
#include "ui_ClientsDialog.h"

ClientsDialog::ClientsDialog(QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::ClientsDialog)
{
        m_ui->setupUi(this);
}

ClientsDialog::~ClientsDialog() {
        delete m_ui;
}
