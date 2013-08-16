#include "MainWindow.h"
#include "PricetagGenerator.h"
#include "ui_MainWindow.h"
#include "PricetagDialog.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        m_ui(new Ui::MainWindow)
{
        m_ui->setupUi(this);
        createMainViews();
        connectWidgets();
}

MainWindow::~MainWindow() {
        delete m_ui;
}

void MainWindow::createMainViews() {
        m_mainProductList = new MainProductList();
        m_ui->ltMainLayout->addLayout(m_mainProductList);

        m_mainSoldList = new MainSoldList();
        m_ui->ltMainLayout->addLayout(m_mainSoldList);
}

void MainWindow::connectWidgets() {
        // Основное меню
        connect(m_ui->actGeneratePricetags, SIGNAL(triggered()), SLOT(processGeneratePricetagsAction()));
        connect(m_ui->actClearPricetags, SIGNAL(triggered()), SLOT(processClearPricetagsAction()));
}

void MainWindow::processGeneratePricetagsAction() {
        PricetagDialog* dialog = new PricetagDialog(this);
        dialog->exec();
}

void MainWindow::processClearPricetagsAction() {
        PricetagGenerator::instance()->clearTags();
}
