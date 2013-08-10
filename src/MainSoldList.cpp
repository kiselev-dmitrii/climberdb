#include "MainSoldList.h"
#include "Database.h"
#include <QPushButton>
#include <QDateEdit>

MainSoldList::MainSoldList(QWidget* parent) :
        QVBoxLayout(parent),
        m_soldView(nullptr),
        m_panelLayout(nullptr),
        m_dateEdit(nullptr),
        m_prevBtn(nullptr),
        m_nextBtn(nullptr)
{
        createView();
        createDatePanel();
        connectWidgets();
}

void MainSoldList::createView() {
        Database::instance()->refreshMainSoldProductsModel(QDate::currentDate());
        m_soldView = new SoldProductsView(Database::instance()->mainSoldProductsModel());
        this->addWidget(m_soldView);
}

void MainSoldList::createDatePanel() {
        m_panelLayout = new QHBoxLayout();
        this->addLayout(m_panelLayout);

        // Виджет даты
        m_dateEdit = new QDateEdit();
        m_dateEdit->setCalendarPopup(true);
        m_dateEdit->setDate(QDate::currentDate());
        m_panelLayout->addWidget(m_dateEdit);

        m_panelLayout->addStretch();

        // Кнопки
        m_prevBtn = new QPushButton("<-");
        m_nextBtn = new QPushButton("->");
        m_panelLayout->addWidget(m_prevBtn);
        m_panelLayout->addWidget(m_nextBtn);
}

void MainSoldList::connectWidgets() {
        connect(m_dateEdit, SIGNAL(dateChanged(QDate)), SLOT(setTableDate(QDate)));
        connect(m_nextBtn, SIGNAL(clicked()),  SLOT(setNextDate()));
        connect(m_prevBtn, SIGNAL(clicked()), SLOT(setPrevDate()));
}

void MainSoldList::setTableDate(const QDate &date) {
        Database::instance()->refreshMainSoldProductsModel(date);
}

void MainSoldList::setPrevDate() {
        m_dateEdit->setDate(m_dateEdit->date().addDays(-1));
}

void MainSoldList::setNextDate() {
        m_dateEdit->setDate(m_dateEdit->date().addDays(1));
}
