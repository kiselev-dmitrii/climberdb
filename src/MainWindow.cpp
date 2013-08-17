#include "MainWindow.h"
#include "PricetagGenerator.h"
#include "ui_MainWindow.h"
#include "PricetagDialog.h"
#include "ClientsDialog.h"
#include "SearchSoldDialog.h"

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
        // Меню: БД
        connect(m_ui->actClients, SIGNAL(triggered()), SLOT(processClientsAction()));
        connect(m_ui->actSearchOnSales, SIGNAL(triggered()), SLOT(processSearchSoldAction()));

        // Меню: ценники
        connect(m_ui->actGeneratePricetags, SIGNAL(triggered()), SLOT(processGeneratePricetagsAction()));
        connect(m_ui->actClearPricetags, SIGNAL(triggered()), SLOT(processClearPricetagsAction()));
}

void MainWindow::processClientsAction() {
        ClientsDialog* dialog = new ClientsDialog(this);
        dialog->exec();
}

void MainWindow::processSearchSoldAction() {
        SearchSoldDialog* dialog = new SearchSoldDialog(this);
        dialog->exec();
}

void MainWindow::processGeneratePricetagsAction() {
        PricetagDialog* dialog = new PricetagDialog(this);
        dialog->exec();
}

void MainWindow::processClearPricetagsAction() {
        PricetagGenerator::instance()->clearTags();
}
