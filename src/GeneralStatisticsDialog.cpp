#include "GeneralStatisticsDialog.h"
#include "ui_GeneralStatisticsDialog.h"
#include "Database.h"

GeneralStatisticsDialog::GeneralStatisticsDialog(QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::GeneralStatisticsDialog)
{
        m_ui->setupUi(this);
        initDates();
        connectWidgets();
}

GeneralStatisticsDialog::~GeneralStatisticsDialog() {
        delete m_ui;
}

void GeneralStatisticsDialog::initDates() {
        m_ui->deTo->setDate(QDate::currentDate());
        m_ui->deFrom->setDate(QDate::currentDate().addMonths(-1));
}

void GeneralStatisticsDialog::connectWidgets() {
        // Нажатие на кнопку Получить статистику
        connect(m_ui->btnGetStatistics, SIGNAL(clicked()), SLOT(onGetStatisticsButton()));
}

void GeneralStatisticsDialog::onGetStatisticsButton() {
        // Получаем введенные данные от пользователя
        ProductFilter filter;
        filter.name = m_ui->edtName->text();
        filter.model = m_ui->edtModel->text();
        filter.size = m_ui->edtSize->text();
        filter.type = m_ui->edtType->text();

        QDate from = m_ui->deFrom->date();
        QDate to = m_ui->deTo->date();

        // Статистика о продажах
        int count, sum;
        std::tie(count, sum) = Database::instance()->getCountAndSumOfSoldProducts(from, to, filter);
        m_ui->edtSalesCount->setText(QString::number(count));
        m_ui->edtSalesSum->setText(QString::number(sum));

        // Статистика о продажах
        std::tie(count, sum) = Database::instance()->getCountAndSumOfPurchasedProducts(from, to, filter);
        m_ui->edtDeliveryCount->setText(QString::number(count));
        m_ui->edtDeliverySum->setText(QString::number(sum));
}
