#include "CreateConsignmentDialog.h"
#include "ui_ConsignmentDialog.h"

CreateConsignmentDialog::CreateConsignmentDialog(QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::dlgConsignment)

{
        m_ui->setupUi(this);
}

CreateConsignmentDialog::~CreateConsignmentDialog() {
        delete m_ui;
}

