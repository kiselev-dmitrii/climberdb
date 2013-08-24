#include "MainSoldList.h"
#include "Database.h"
#include <QPushButton>
#include <QDateEdit>
#include <QLabel>
#include <QLineEdit>

MainSoldList::MainSoldList(QWidget* parent) :
        QVBoxLayout(parent),
        m_soldView(nullptr),
        m_ltInfoPanel(nullptr),
        m_ltDatePanel(nullptr),
        m_edtSumSelected(nullptr),
        m_edtSumSoldProducts(nullptr),
        m_dateEdit(nullptr),
        m_prevBtn(nullptr),
        m_nextBtn(nullptr)
{
        createView();
        createInfoPanel();
        createDatePanel();
        updateSumSoldProducts();
        connectWidgets();
}

void MainSoldList::createView() {
        Database::instance()->refreshMainSoldProductsModel(QDate::currentDate());
        m_soldView = new SoldProductsView(Database::instance()->mainSoldProductsModel());
        this->addWidget(m_soldView);
}

void MainSoldList::createInfoPanel() {
        m_ltInfoPanel = new QHBoxLayout();
        this->addLayout(m_ltInfoPanel);

        m_ltInfoPanel->addWidget(new QLabel("Сумма выделеных товаров:"));
        m_edtSumSelected = new QLineEdit();
        m_edtSumSelected->setReadOnly(true);
        m_edtSumSelected->setMaximumWidth(70);
        m_ltInfoPanel->addWidget(m_edtSumSelected);

        m_ltInfoPanel->addStretch();

        m_ltInfoPanel->addWidget(new QLabel("Сумма продаж за день:"));
        m_edtSumSoldProducts = new QLineEdit();
        m_edtSumSoldProducts->setReadOnly(true);
        m_edtSumSoldProducts->setMaximumWidth(70);
        m_ltInfoPanel->addWidget(m_edtSumSoldProducts);
}

void MainSoldList::createDatePanel() {
        m_ltDatePanel = new QHBoxLayout();
        this->addLayout(m_ltDatePanel);

        // Виджет даты
        m_dateEdit = new QDateEdit();
        m_dateEdit->setCalendarPopup(true);
        m_dateEdit->setDate(QDate::currentDate());
        m_ltDatePanel->addWidget(m_dateEdit);

        m_ltDatePanel->addStretch();

        // Кнопки
        m_nextBtn = new QPushButton("<-");
        m_prevBtn = new QPushButton("->");
        m_ltDatePanel->addWidget(m_nextBtn);
        m_ltDatePanel->addWidget(m_prevBtn);
}

void MainSoldList::updateSumSoldProducts() {
        int rowCount = m_soldView->model()->rowCount();
        if (rowCount == 0) {
                m_edtSumSoldProducts->setText("0");
        } else {
                int sum = 0;
                for (int row = 0; row < rowCount; ++row) {
                        QModelIndex index = m_soldView->model()->index(row, 4);
                        sum += m_soldView->model()->data(index).toInt();
                }
                m_edtSumSoldProducts->setText(QString::number(sum));
        }
}

void MainSoldList::connectWidgets() {
        connect(m_dateEdit, SIGNAL(dateChanged(QDate)), SLOT(setTableDate(QDate)));
        connect(m_nextBtn, SIGNAL(clicked()),  SLOT(setNextDate()));
        connect(m_prevBtn, SIGNAL(clicked()), SLOT(setPrevDate()));
        connect(m_soldView->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), SLOT(setSumSelected()));
}

void MainSoldList::setTableDate(const QDate &date) {
        Database::instance()->refreshMainSoldProductsModel(date);
        updateSumSoldProducts();
}

void MainSoldList::setPrevDate() {
        m_dateEdit->setDate(m_dateEdit->date().addDays(-1));
        updateSumSoldProducts();
}

void MainSoldList::setNextDate() {
        m_dateEdit->setDate(m_dateEdit->date().addDays(1));
        updateSumSoldProducts();
}

void MainSoldList::setSumSelected() {
        // Берем индексы выделенных строк четвертого столбца
        QModelIndexList selectedRows = m_soldView->selectionModel()->selectedRows(4);
        if (selectedRows.size() == 0) {
                m_edtSumSelected->setText("0");
        } else {
                int selectedSums = 0;
                for (QModelIndex &index: selectedRows) selectedSums +=  m_soldView->model()->data(index).toInt();
                m_edtSumSelected->setText(QString::number(selectedSums));
        }
}
