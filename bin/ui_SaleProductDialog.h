/********************************************************************************
** Form generated from reading UI file 'SaleProductDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALEPRODUCTDIALOG_H
#define UI_SALEPRODUCTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_saleProductDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *btnBox;
    QComboBox *cbSize;
    QLabel *lblInfo;
    QLabel *lblClient;
    QLabel *lblSize;
    QHBoxLayout *horizontalLayout;
    QComboBox *cbClient;
    QPushButton *btnAddClient;

    void setupUi(QDialog *saleProductDialog)
    {
        if (saleProductDialog->objectName().isEmpty())
            saleProductDialog->setObjectName(QStringLiteral("saleProductDialog"));
        saleProductDialog->resize(247, 115);
        gridLayout = new QGridLayout(saleProductDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btnBox = new QDialogButtonBox(saleProductDialog);
        btnBox->setObjectName(QStringLiteral("btnBox"));
        btnBox->setOrientation(Qt::Horizontal);
        btnBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(btnBox, 3, 1, 1, 1);

        cbSize = new QComboBox(saleProductDialog);
        cbSize->setObjectName(QStringLiteral("cbSize"));

        gridLayout->addWidget(cbSize, 1, 1, 1, 1);

        lblInfo = new QLabel(saleProductDialog);
        lblInfo->setObjectName(QStringLiteral("lblInfo"));

        gridLayout->addWidget(lblInfo, 1, 0, 1, 1);

        lblClient = new QLabel(saleProductDialog);
        lblClient->setObjectName(QStringLiteral("lblClient"));

        gridLayout->addWidget(lblClient, 2, 0, 1, 1);

        lblSize = new QLabel(saleProductDialog);
        lblSize->setObjectName(QStringLiteral("lblSize"));

        gridLayout->addWidget(lblSize, 0, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cbClient = new QComboBox(saleProductDialog);
        cbClient->setObjectName(QStringLiteral("cbClient"));

        horizontalLayout->addWidget(cbClient);

        btnAddClient = new QPushButton(saleProductDialog);
        btnAddClient->setObjectName(QStringLiteral("btnAddClient"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnAddClient->sizePolicy().hasHeightForWidth());
        btnAddClient->setSizePolicy(sizePolicy);
        btnAddClient->setMaximumSize(QSize(25, 16777215));

        horizontalLayout->addWidget(btnAddClient);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);


        retranslateUi(saleProductDialog);
        QObject::connect(btnBox, SIGNAL(accepted()), saleProductDialog, SLOT(accept()));
        QObject::connect(btnBox, SIGNAL(rejected()), saleProductDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(saleProductDialog);
    } // setupUi

    void retranslateUi(QDialog *saleProductDialog)
    {
        saleProductDialog->setWindowTitle(QApplication::translate("saleProductDialog", "\320\237\321\200\320\276\320\264\320\260\320\266\320\260", 0));
        lblInfo->setText(QApplication::translate("saleProductDialog", "\320\240\320\260\320\267\320\274\320\265\321\200: ", 0));
        lblClient->setText(QApplication::translate("saleProductDialog", "\320\232\320\273\320\270\320\265\320\275\321\202:", 0));
        lblSize->setText(QApplication::translate("saleProductDialog", "\320\237\320\276\320\266\320\260\320\273\321\203\320\271\321\201\321\202\320\260, \320\262\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\200\320\260\320\267\320\274\320\265\321\200 \320\270 \320\272\320\273\320\270\320\265\320\275\321\202\320\260:", 0));
        btnAddClient->setText(QApplication::translate("saleProductDialog", "+", 0));
    } // retranslateUi

};

namespace Ui {
    class saleProductDialog: public Ui_saleProductDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALEPRODUCTDIALOG_H
