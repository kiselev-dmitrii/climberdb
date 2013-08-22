/********************************************************************************
** Form generated from reading UI file 'SalesPlotDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALESPLOTDIALOG_H
#define UI_SALESPLOTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SalesPlotDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblInfo;
    QHBoxLayout *ltDates;
    QLabel *lblFrom;
    QDateEdit *deFrom;
    QLabel *lblTo;
    QDateEdit *deTo;
    QSpacerItem *spacer1;
    QPushButton *btnPlot;
    QGraphicsView *gvPlot;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chbDeliveries;
    QCheckBox *chbSales;
    QPushButton *btnShowSums;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *SalesPlotDialog)
    {
        if (SalesPlotDialog->objectName().isEmpty())
            SalesPlotDialog->setObjectName(QStringLiteral("SalesPlotDialog"));
        SalesPlotDialog->resize(595, 363);
        verticalLayout = new QVBoxLayout(SalesPlotDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblInfo = new QLabel(SalesPlotDialog);
        lblInfo->setObjectName(QStringLiteral("lblInfo"));

        verticalLayout->addWidget(lblInfo);

        ltDates = new QHBoxLayout();
        ltDates->setObjectName(QStringLiteral("ltDates"));
        lblFrom = new QLabel(SalesPlotDialog);
        lblFrom->setObjectName(QStringLiteral("lblFrom"));

        ltDates->addWidget(lblFrom);

        deFrom = new QDateEdit(SalesPlotDialog);
        deFrom->setObjectName(QStringLiteral("deFrom"));
        deFrom->setCalendarPopup(true);

        ltDates->addWidget(deFrom);

        lblTo = new QLabel(SalesPlotDialog);
        lblTo->setObjectName(QStringLiteral("lblTo"));

        ltDates->addWidget(lblTo);

        deTo = new QDateEdit(SalesPlotDialog);
        deTo->setObjectName(QStringLiteral("deTo"));
        deTo->setCalendarPopup(true);

        ltDates->addWidget(deTo);

        spacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ltDates->addItem(spacer1);

        btnPlot = new QPushButton(SalesPlotDialog);
        btnPlot->setObjectName(QStringLiteral("btnPlot"));

        ltDates->addWidget(btnPlot);


        verticalLayout->addLayout(ltDates);

        gvPlot = new QGraphicsView(SalesPlotDialog);
        gvPlot->setObjectName(QStringLiteral("gvPlot"));
        gvPlot->setRenderHints(QPainter::Antialiasing|QPainter::HighQualityAntialiasing|QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);

        verticalLayout->addWidget(gvPlot);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        chbDeliveries = new QCheckBox(SalesPlotDialog);
        chbDeliveries->setObjectName(QStringLiteral("chbDeliveries"));

        horizontalLayout->addWidget(chbDeliveries);

        chbSales = new QCheckBox(SalesPlotDialog);
        chbSales->setObjectName(QStringLiteral("chbSales"));
        chbSales->setChecked(true);

        horizontalLayout->addWidget(chbSales);

        btnShowSums = new QPushButton(SalesPlotDialog);
        btnShowSums->setObjectName(QStringLiteral("btnShowSums"));
        btnShowSums->setCheckable(true);
        btnShowSums->setFlat(false);

        horizontalLayout->addWidget(btnShowSums);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SalesPlotDialog);

        QMetaObject::connectSlotsByName(SalesPlotDialog);
    } // setupUi

    void retranslateUi(QDialog *SalesPlotDialog)
    {
        SalesPlotDialog->setWindowTitle(QApplication::translate("SalesPlotDialog", "\320\223\321\200\320\260\321\204\320\270\320\272 \320\277\321\200\320\276\320\264\320\260\320\266", 0));
        lblInfo->setText(QApplication::translate("SalesPlotDialog", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\277\321\200\320\276\320\274\320\265\320\266\321\203\321\202\320\276\320\272 \320\262\321\200\320\265\320\274\320\265\320\275\320\270 \320\277\320\276 \320\272\320\276\321\202\320\276\321\200\320\276\320\274\321\203 \320\261\321\203\320\264\320\265\321\202 \320\276\321\202\321\200\320\270\321\201\320\276\320\262\321\213\320\262\320\260\321\202\321\214\321\201\321\217 \320\263\321\200\320\260\321\204\320\270\320\272 \320\277\321\200\320\276\320\264\320\260\320\266.", 0));
        lblFrom->setText(QApplication::translate("SalesPlotDialog", "\321\201 ", 0));
        lblTo->setText(QApplication::translate("SalesPlotDialog", " \320\277\320\276 ", 0));
        btnPlot->setText(QApplication::translate("SalesPlotDialog", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", 0));
        chbDeliveries->setText(QApplication::translate("SalesPlotDialog", "\320\237\320\276\321\201\321\202\320\260\320\262\320\272\320\270", 0));
        chbSales->setText(QApplication::translate("SalesPlotDialog", "\320\237\321\200\320\276\320\264\320\260\320\266\320\270", 0));
        btnShowSums->setText(QApplication::translate("SalesPlotDialog", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\202\321\214 \321\201\321\203\320\274\320\274\321\213", 0));
    } // retranslateUi

};

namespace Ui {
    class SalesPlotDialog: public Ui_SalesPlotDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALESPLOTDIALOG_H
