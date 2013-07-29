#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), m_ui(new Ui::MainWindow) {
        m_ui->setupUi(this);

        // Создаем таблицу
        m_productsView = new ProductsView();
        m_ui->ltMainLayout->insertWidget(0, m_productsView);

        // Создаем фильтр
        QVector<int> fieldsWidth = m_productsView->columnsWidth();
        fieldsWidth[0] += m_productsView->verticalHeader()->size().width();
        m_productsFilter = new ProductFilter(fieldsWidth);
        m_ui->ltMainLayout->insertWidget(1, m_productsFilter);
        QObject::connect(m_productsView->horizontalHeader(), SIGNAL(sectionResized(int,int,int)), m_productsFilter, SLOT(columnResize(int,int,int)));
}

MainWindow::~MainWindow() {
        delete m_ui;
}
