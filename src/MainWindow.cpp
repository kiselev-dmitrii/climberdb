#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "PricetagDialog.h"
#include "PricetagGenerator.h"
#include "ClientsDialog.h"
#include "SearchSoldDialog.h"
#include "SearchBarcodeDialog.h"
#include "GeneralStatisticsDialog.h"
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        m_ui(new Ui::MainWindow),
        m_mainProductList(nullptr),
        m_mainSoldList(nullptr)
{
        m_ui->setupUi(this);
        createMainViews();
        createShortcuts();
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

void MainWindow::createShortcuts() {
        QShortcut* shortcut;
        // F12 - поиск товара по штрихкоду
        shortcut = new QShortcut(Qt::Key_F12, this);
        shortcut->setContext(Qt::ApplicationShortcut);
        connect(shortcut, SIGNAL(activated()), SLOT(openSearchBarcodeDialog()));
}

void MainWindow::connectWidgets() {
        // Меню: БД
        connect(m_ui->actClients, SIGNAL(triggered()), SLOT(processClientsAction()));
        connect(m_ui->actSearchOnSales, SIGNAL(triggered()), SLOT(processSearchSoldAction()));

        // Меню: Ценники
        connect(m_ui->actGeneratePricetags, SIGNAL(triggered()), SLOT(processGeneratePricetagsAction()));
        connect(m_ui->actClearPricetags, SIGNAL(triggered()), SLOT(processClearPricetagsAction()));

        // Меню: Анализ
        connect(m_ui->actGeneralStatistics, SIGNAL(triggered()), SLOT(processGeneralStatisticsAction()));
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

void MainWindow::processGeneralStatisticsAction() {
        GeneralStatisticsDialog* dialog = new GeneralStatisticsDialog(this);
        dialog->exec();
}

void MainWindow::openSearchBarcodeDialog() {
        SearchBarcodeDialog* dialog = new SearchBarcodeDialog(this);
        dialog->exec();
}
