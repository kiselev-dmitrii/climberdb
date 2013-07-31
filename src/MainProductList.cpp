#include "MainProductList.h"
#include <QHeaderView>
#include <QShortcut>
#include "Database.h"

MainProductList::MainProductList(QWidget *parent) :
        QVBoxLayout(parent),
        m_productsView(nullptr),
        m_productsFilter(nullptr)
{
        createWidgets();
        connectWidgets();
}

void MainProductList::createWidgets() {
        Database::instance()->getAllProductsModel(&m_currentModel, "","","","","","","","","");
        m_productsView = new ProductsView(&m_currentModel);
        this->addWidget(m_productsView);

        m_productsFilter = new ProductsFilter(m_productsView->columnsWidth());
        m_productsFilter->setColumnOffset(0, m_productsView->verticalHeader()->width());        //учитываем верт. шапку
        this->addWidget(m_productsFilter);
}


void MainProductList::connectWidgets() {
        // Устанавливаем синхронный ресайз
        connect(m_productsView->horizontalHeader(), &QHeaderView::sectionResized,
                m_productsFilter, &ProductsFilter::columnResize);

        connect(m_productsFilter, SIGNAL(enterPressed()), this, SLOT(applyFilter()));
        connect(m_productsFilter, SIGNAL(escapePressed()), this, SLOT(revertTable()));
}

void MainProductList::applyFilter() {
        QString name = m_productsFilter->columnText(0);
        QString model = m_productsFilter->columnText(1);
        QString size = m_productsFilter->columnText(2);
        QString cost = m_productsFilter->columnText(3);
        QString type = m_productsFilter->columnText(4);
        QString gender = m_productsFilter->columnText(5);
        QString comment = m_productsFilter->columnText(6);
        QString color = m_productsFilter->columnText(7);
        QString country = m_productsFilter->columnText(8);

        Database::instance()->getAllProductsModel(&m_currentModel, name, model, size, cost, type, gender, comment, color, country);
        m_productsView->setModel(&m_currentModel);

        // Применяем на таблицу фокус
        m_productsView->setFocus();
}

void MainProductList::revertTable() {
        m_productsFilter->clearFilter();
        applyFilter();
}
