/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actSales;
    QAction *actClients;
    QAction *actPrintPricetags;
    QAction *actClearPricetags;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *ltMainLayout;
    QMenuBar *mbMainMenu;
    QMenu *mnDatabase;
    QMenu *mnPricetags;
    QStatusBar *sbMainStatusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(900, 600);
        actSales = new QAction(MainWindow);
        actSales->setObjectName(QStringLiteral("actSales"));
        actClients = new QAction(MainWindow);
        actClients->setObjectName(QStringLiteral("actClients"));
        actPrintPricetags = new QAction(MainWindow);
        actPrintPricetags->setObjectName(QStringLiteral("actPrintPricetags"));
        actClearPricetags = new QAction(MainWindow);
        actClearPricetags->setObjectName(QStringLiteral("actClearPricetags"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        ltMainLayout = new QVBoxLayout();
        ltMainLayout->setObjectName(QStringLiteral("ltMainLayout"));

        verticalLayout_2->addLayout(ltMainLayout);

        MainWindow->setCentralWidget(centralwidget);
        mbMainMenu = new QMenuBar(MainWindow);
        mbMainMenu->setObjectName(QStringLiteral("mbMainMenu"));
        mbMainMenu->setGeometry(QRect(0, 0, 900, 21));
        mnDatabase = new QMenu(mbMainMenu);
        mnDatabase->setObjectName(QStringLiteral("mnDatabase"));
        mnPricetags = new QMenu(mbMainMenu);
        mnPricetags->setObjectName(QStringLiteral("mnPricetags"));
        MainWindow->setMenuBar(mbMainMenu);
        sbMainStatusBar = new QStatusBar(MainWindow);
        sbMainStatusBar->setObjectName(QStringLiteral("sbMainStatusBar"));
        MainWindow->setStatusBar(sbMainStatusBar);

        mbMainMenu->addAction(mnDatabase->menuAction());
        mbMainMenu->addAction(mnPricetags->menuAction());
        mnDatabase->addAction(actSales);
        mnDatabase->addAction(actClients);
        mnPricetags->addAction(actPrintPricetags);
        mnPricetags->addAction(actClearPricetags);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Climber Shop Database", 0));
        actSales->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\320\260\320\266\320\270", 0));
        actClients->setText(QApplication::translate("MainWindow", "\320\232\320\273\320\270\320\265\320\275\321\202\321\213", 0));
        actPrintPricetags->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\207\320\260\321\202\321\214 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\275\321\213\321\205 \321\206\320\265\320\275\320\275\320\270\320\272\320\276\320\262", 0));
        actClearPricetags->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 ", 0));
        mnDatabase->setTitle(QApplication::translate("MainWindow", "\320\221\320\260\320\267\320\260 \320\264\320\260\320\275\320\275\321\213\321\205", 0));
        mnPricetags->setTitle(QApplication::translate("MainWindow", "\320\246\320\265\320\275\320\275\320\270\320\272\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
