#include "SearchBarcodeDialog.h"
#include "ui_SearchBarcodeDialog.h"

SearchBarcodeDialog::SearchBarcodeDialog(QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::SearchBarcodeDialog)
{
        m_ui->setupUi(this);
}

SearchBarcodeDialog::~SearchBarcodeDialog() {
        delete m_ui;
}
