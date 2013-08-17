#include "SearchSoldDialog.h"
#include "ui_SearchSoldDialog.h"
#include "Database.h"

SearchSoldDialog::SearchSoldDialog(QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::SearchSoldDialog)
{
        m_ui->setupUi(this);
        initDates();
        loadTableData();
        connectWidgets();
}

SearchSoldDialog::~SearchSoldDialog() {
        delete m_ui;
}

void SearchSoldDialog::initDates() {
        m_ui->deTo->setDate(QDate::currentDate());
        m_ui->deFrom->setDate(QDate::currentDate().addDays(-7));
}

void SearchSoldDialog::loadTableData() {
        m_ui->tableView->setModel(Database::instance()->productsSoldModel());
}

void SearchSoldDialog::connectWidgets() {
        // Кнопка Поиск
        connect(m_ui->btnFind, SIGNAL(clicked()), SLOT(find()));
}

void SearchSoldDialog::find() {
        QString name = m_ui->edtName->text();
        QString model = m_ui->edtModel->text();
        QString size = m_ui->edtSize->text();
        QString type = m_ui->edtType->text();
        QDate from = m_ui->deFrom->date();
        QDate to = m_ui->deTo->date();

        Database::instance()->refreshProductsSoldModel(name, model, size, type, from, to);
        m_ui->tableView->hideColumn(0);
        m_ui->tableView->resizeColumnsToContents();
}
