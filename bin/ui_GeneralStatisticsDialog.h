/********************************************************************************
** Form generated from reading UI file 'GeneralStatisticsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALSTATISTICSDIALOG_H
#define UI_GENERALSTATISTICSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GeneralStatisticsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblInfo;
    QGridLayout *gltFilter;
    QLabel *lblType;
    QLabel *lblSize;
    QLineEdit *edtName;
    QLineEdit *edtModel;
    QLabel *lblName;
    QLabel *lblModel;
    QLineEdit *edtSize;
    QLineEdit *edtType;
    QHBoxLayout *ltDates;
    QLabel *lblFrom;
    QDateEdit *deFrom;
    QLabel *lblTo;
    QDateEdit *deTo;
    QSpacerItem *spacer1;
    QPushButton *btnGetStatistics;
    QSpacerItem *verticalSpacer;
    QGridLayout *gltStatistics;
    QLabel *lblSalesCount;
    QLabel *lblDeliverySum;
    QLineEdit *edtDeliveryCount;
    QLineEdit *edtSalesSum;
    QLineEdit *edtSalesCount;
    QLabel *lblSalesSum;
    QLabel *lblDeliveryCount;
    QLineEdit *edtDeliverySum;

    void setupUi(QDialog *GeneralStatisticsDialog)
    {
        if (GeneralStatisticsDialog->objectName().isEmpty())
            GeneralStatisticsDialog->setObjectName(QStringLiteral("GeneralStatisticsDialog"));
        GeneralStatisticsDialog->resize(490, 241);
        verticalLayout = new QVBoxLayout(GeneralStatisticsDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblInfo = new QLabel(GeneralStatisticsDialog);
        lblInfo->setObjectName(QStringLiteral("lblInfo"));

        verticalLayout->addWidget(lblInfo);

        gltFilter = new QGridLayout();
        gltFilter->setObjectName(QStringLiteral("gltFilter"));
        lblType = new QLabel(GeneralStatisticsDialog);
        lblType->setObjectName(QStringLiteral("lblType"));

        gltFilter->addWidget(lblType, 1, 2, 1, 1);

        lblSize = new QLabel(GeneralStatisticsDialog);
        lblSize->setObjectName(QStringLiteral("lblSize"));

        gltFilter->addWidget(lblSize, 0, 2, 1, 1);

        edtName = new QLineEdit(GeneralStatisticsDialog);
        edtName->setObjectName(QStringLiteral("edtName"));

        gltFilter->addWidget(edtName, 0, 1, 1, 1);

        edtModel = new QLineEdit(GeneralStatisticsDialog);
        edtModel->setObjectName(QStringLiteral("edtModel"));

        gltFilter->addWidget(edtModel, 1, 1, 1, 1);

        lblName = new QLabel(GeneralStatisticsDialog);
        lblName->setObjectName(QStringLiteral("lblName"));

        gltFilter->addWidget(lblName, 0, 0, 1, 1);

        lblModel = new QLabel(GeneralStatisticsDialog);
        lblModel->setObjectName(QStringLiteral("lblModel"));

        gltFilter->addWidget(lblModel, 1, 0, 1, 1);

        edtSize = new QLineEdit(GeneralStatisticsDialog);
        edtSize->setObjectName(QStringLiteral("edtSize"));

        gltFilter->addWidget(edtSize, 0, 3, 1, 1);

        edtType = new QLineEdit(GeneralStatisticsDialog);
        edtType->setObjectName(QStringLiteral("edtType"));

        gltFilter->addWidget(edtType, 1, 3, 1, 1);


        verticalLayout->addLayout(gltFilter);

        ltDates = new QHBoxLayout();
        ltDates->setObjectName(QStringLiteral("ltDates"));
        lblFrom = new QLabel(GeneralStatisticsDialog);
        lblFrom->setObjectName(QStringLiteral("lblFrom"));

        ltDates->addWidget(lblFrom);

        deFrom = new QDateEdit(GeneralStatisticsDialog);
        deFrom->setObjectName(QStringLiteral("deFrom"));
        deFrom->setCalendarPopup(true);

        ltDates->addWidget(deFrom);

        lblTo = new QLabel(GeneralStatisticsDialog);
        lblTo->setObjectName(QStringLiteral("lblTo"));

        ltDates->addWidget(lblTo);

        deTo = new QDateEdit(GeneralStatisticsDialog);
        deTo->setObjectName(QStringLiteral("deTo"));
        deTo->setCalendarPopup(true);

        ltDates->addWidget(deTo);

        spacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ltDates->addItem(spacer1);

        btnGetStatistics = new QPushButton(GeneralStatisticsDialog);
        btnGetStatistics->setObjectName(QStringLiteral("btnGetStatistics"));

        ltDates->addWidget(btnGetStatistics);


        verticalLayout->addLayout(ltDates);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gltStatistics = new QGridLayout();
        gltStatistics->setObjectName(QStringLiteral("gltStatistics"));
        lblSalesCount = new QLabel(GeneralStatisticsDialog);
        lblSalesCount->setObjectName(QStringLiteral("lblSalesCount"));

        gltStatistics->addWidget(lblSalesCount, 0, 0, 1, 1);

        lblDeliverySum = new QLabel(GeneralStatisticsDialog);
        lblDeliverySum->setObjectName(QStringLiteral("lblDeliverySum"));

        gltStatistics->addWidget(lblDeliverySum, 3, 0, 1, 1);

        edtDeliveryCount = new QLineEdit(GeneralStatisticsDialog);
        edtDeliveryCount->setObjectName(QStringLiteral("edtDeliveryCount"));
        edtDeliveryCount->setReadOnly(true);

        gltStatistics->addWidget(edtDeliveryCount, 2, 1, 1, 1);

        edtSalesSum = new QLineEdit(GeneralStatisticsDialog);
        edtSalesSum->setObjectName(QStringLiteral("edtSalesSum"));
        edtSalesSum->setReadOnly(true);

        gltStatistics->addWidget(edtSalesSum, 1, 1, 1, 1);

        edtSalesCount = new QLineEdit(GeneralStatisticsDialog);
        edtSalesCount->setObjectName(QStringLiteral("edtSalesCount"));
        edtSalesCount->setReadOnly(true);

        gltStatistics->addWidget(edtSalesCount, 0, 1, 1, 1);

        lblSalesSum = new QLabel(GeneralStatisticsDialog);
        lblSalesSum->setObjectName(QStringLiteral("lblSalesSum"));

        gltStatistics->addWidget(lblSalesSum, 1, 0, 1, 1);

        lblDeliveryCount = new QLabel(GeneralStatisticsDialog);
        lblDeliveryCount->setObjectName(QStringLiteral("lblDeliveryCount"));

        gltStatistics->addWidget(lblDeliveryCount, 2, 0, 1, 1);

        edtDeliverySum = new QLineEdit(GeneralStatisticsDialog);
        edtDeliverySum->setObjectName(QStringLiteral("edtDeliverySum"));
        edtDeliverySum->setReadOnly(true);

        gltStatistics->addWidget(edtDeliverySum, 3, 1, 1, 1);


        verticalLayout->addLayout(gltStatistics);


        retranslateUi(GeneralStatisticsDialog);

        QMetaObject::connectSlotsByName(GeneralStatisticsDialog);
    } // setupUi

    void retranslateUi(QDialog *GeneralStatisticsDialog)
    {
        GeneralStatisticsDialog->setWindowTitle(QApplication::translate("GeneralStatisticsDialog", "\320\236\320\261\321\211\320\260\321\217 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", 0));
        lblInfo->setText(QApplication::translate("GeneralStatisticsDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\204\320\270\320\273\321\214\321\202\321\200 \320\270 \320\277\321\200\320\276\320\274\320\265\320\266\321\203\321\202\320\276\320\272 \320\262\321\200\320\265\320\274\320\265\320\275\320\270, \320\277\320\276 \320\272\320\276\321\202\320\276\321\200\320\276\320\274\321\203 \320\261\321\203\320\264\320\265\321\202 \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\321\201\321\217 \321\201\320\261\320\276\321\200 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\270:", 0));
        lblType->setText(QApplication::translate("GeneralStatisticsDialog", "\320\242\320\270\320\277:", 0));
        lblSize->setText(QApplication::translate("GeneralStatisticsDialog", "\320\240\320\260\320\267\320\274\320\265\321\200:", 0));
        lblName->setText(QApplication::translate("GeneralStatisticsDialog", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265:", 0));
        lblModel->setText(QApplication::translate("GeneralStatisticsDialog", "\320\234\320\276\320\264\320\265\320\273\321\214:", 0));
        lblFrom->setText(QApplication::translate("GeneralStatisticsDialog", "\321\201 ", 0));
        lblTo->setText(QApplication::translate("GeneralStatisticsDialog", " \320\277\320\276 ", 0));
        btnGetStatistics->setText(QApplication::translate("GeneralStatisticsDialog", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\321\203", 0));
        lblSalesCount->setText(QApplication::translate("GeneralStatisticsDialog", "\320\236\320\261\321\211\320\265\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\321\200\320\276\320\264\320\260\320\266:", 0));
        lblDeliverySum->setText(QApplication::translate("GeneralStatisticsDialog", "\320\237\321\200\320\270\321\205\320\276\320\264 (\321\201\321\203\320\274\320\274\320\260):", 0));
        lblSalesSum->setText(QApplication::translate("GeneralStatisticsDialog", "\320\236\320\261\321\211\320\260\321\217 \321\201\321\203\320\274\320\274\320\260 \320\277\321\200\320\276\320\264\320\260\320\266:", 0));
        lblDeliveryCount->setText(QApplication::translate("GeneralStatisticsDialog", "\320\237\321\200\320\270\321\205\320\276\320\264 (\320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276):", 0));
    } // retranslateUi

};

namespace Ui {
    class GeneralStatisticsDialog: public Ui_GeneralStatisticsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALSTATISTICSDIALOG_H
