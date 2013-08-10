#include "ProductDialog.h"
#include "ui_ProductDialog.h"

ProductDialog::ProductDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::ProductDialog)
{
        ui->setupUi(this);
}

ProductDialog::~ProductDialog()
{
        delete ui;
}
