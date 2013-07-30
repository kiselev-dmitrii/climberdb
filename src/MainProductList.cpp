#include "MainProductList.h"
#include <QHeaderView>
#include <QShortcut>

MainProductList::MainProductList(QWidget *parent) :
        QVBoxLayout(parent),
        m_productsView(nullptr),
        m_productsFilter(nullptr)
{
        createWidgets();
        connectWidgets();
}

void MainProductList::createWidgets() {
        m_productsView = new ProductsView();
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
}

void MainProductList::applyFilter() {
        for (int i = 0; i < m_productsFilter->columnCount(); ++i) {
                qDebug() << m_productsFilter->columnText(i);

        }
}
