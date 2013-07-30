#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), m_ui(new Ui::MainWindow) {
        m_ui->setupUi(this);

        m_mainProductList = new MainProductList();
        m_ui->ltMainLayout->insertLayout(0, m_mainProductList);

        /*
        // Установка hotkeys
        for (int i = 0; i < 9; ++i) {
                QShortcut* shortcut = new QShortcut(QKeySequence(QString("Alt+%1").arg(i+1)), this);
                qDebug() << shortcut->key().toString();
                auto slot = std::bind(&ProductsFilter::setFocusOnField, m_productsFilter, i);
                QObject::connect(shortcut, &QShortcut::activated , slot);
        }
        */

}

MainWindow::~MainWindow() {
        delete m_ui;
}
