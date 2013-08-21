#include "GeneralStatisticsDialog.h"
#include "ui_GeneralStatisticsDialog.h"

GeneralStatisticsDialog::GeneralStatisticsDialog(QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::GeneralStatisticsDialog)
{
        m_ui->setupUi(this);
}

GeneralStatisticsDialog::~GeneralStatisticsDialog() {
        delete m_ui;
}
