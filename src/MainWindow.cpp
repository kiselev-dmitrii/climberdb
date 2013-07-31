#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), m_ui(new Ui::MainWindow) {
        m_ui->setupUi(this);

        m_mainProductList = new MainProductList();
        m_ui->ltMainLayout->addLayout(m_mainProductList);

        m_mainSoldList = new MainSoldList();
        m_ui->ltMainLayout->addLayout(m_mainSoldList);
}

MainWindow::~MainWindow() {
        delete m_ui;
}
