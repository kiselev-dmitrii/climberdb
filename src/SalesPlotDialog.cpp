#include "SalesPlotDialog.h"
#include "ui_SalesPlotDialog.h"

SalesPlotDialog::SalesPlotDialog(QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::SalesPlotDialog)
{
        m_ui->setupUi(this);
}

SalesPlotDialog::~SalesPlotDialog() {
        delete m_ui;
}
