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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_saleProductDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *lblClient;
    QComboBox *cbSize;
    QLabel *lblInfo;
    QDialogButtonBox *btnBox;
    QLabel *lblSize;
    QHBoxLayout *ltClient;
    QComboBox *cbClient;
    QPushButton *btnAddClient;
    QCheckBox *chbDiscount;
    QSpinBox *spnDiscount;
    QLabel *lblCost;
    QSpinBox *spnCost;

    void setupUi(QDialog *saleProductDialog)
    {
        if (saleProductDialog->objectName().isEmpty())
            saleProductDialog->setObjectName(QStringLiteral("saleProductDialog"));
        saleProductDialog->resize(247, 169);
        gridLayout = new QGridLayout(saleProductDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lblClient = new QLabel(saleProductDialog);
        lblClient->setObjectName(QStringLiteral("lblClient"));

        gridLayout->addWidget(lblClient, 2, 0, 1, 1);

        cbSize = new QComboBox(saleProductDialog);
        cbSize->setObjectName(QStringLiteral("cbSize"));

        gridLayout->addWidget(cbSize, 1, 1, 1, 1);

        lblInfo = new QLabel(saleProductDialog);
        lblInfo->setObjectName(QStringLiteral("lblInfo"));

        gridLayout->addWidget(lblInfo, 1, 0, 1, 1);

        btnBox = new QDialogButtonBox(saleProductDialog);
        btnBox->setObjectName(QStringLiteral("btnBox"));
        btnBox->setOrientation(Qt::Horizontal);
        btnBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(btnBox, 5, 1, 1, 1);

        lblSize = new QLabel(saleProductDialog);
        lblSize->setObjectName(QStringLiteral("lblSize"));

        gridLayout->addWidget(lblSize, 0, 0, 1, 2);

        ltClient = new QHBoxLayout();
        ltClient->setObjectName(QStringLiteral("ltClient"));
        cbClient = new QComboBox(saleProductDialog);
        cbClient->setObjectName(QStringLiteral("cbClient"));

        ltClient->addWidget(cbClient);

        btnAddClient = new QPushButton(saleProductDialog);
        btnAddClient->setObjectName(QStringLiteral("btnAddClient"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnAddClient->sizePolicy().hasHeightForWidth());
        btnAddClient->setSizePolicy(sizePolicy);
        btnAddClient->setMaximumSize(QSize(25, 16777215));

        ltClient->addWidget(btnAddClient);


        gridLayout->addLayout(ltClient, 2, 1, 1, 1);

        chbDiscount = new QCheckBox(saleProductDialog);
        chbDiscount->setObjectName(QStringLiteral("chbDiscount"));

        gridLayout->addWidget(chbDiscount, 3, 0, 1, 1);

        spnDiscount = new QSpinBox(saleProductDialog);
        spnDiscount->setObjectName(QStringLiteral("spnDiscount"));

        gridLayout->addWidget(spnDiscount, 3, 1, 1, 1);

        lblCost = new QLabel(saleProductDialog);
        lblCost->setObjectName(QStringLiteral("lblCost"));

        gridLayout->addWidget(lblCost, 4, 0, 1, 1);

        spnCost = new QSpinBox(saleProductDialog);
        spnCost->setObjectName(QStringLiteral("spnCost"));

        gridLayout->addWidget(spnCost, 4, 1, 1, 1);


        retranslateUi(saleProductDialog);
        QObject::connect(btnBox, SIGNAL(accepted()), saleProductDialog, SLOT(accept()));
        QObject::connect(btnBox, SIGNAL(rejected()), saleProductDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(saleProductDialog);
    } // setupUi

    void retranslateUi(QDialog *saleProductDialog)
    {
        saleProductDialog->setWindowTitle(QApplication::translate("saleProductDialog", "\320\237\321\200\320\276\320\264\320\260\320\266\320\260", 0));
        lblClient->setText(QApplication::translate("saleProductDialog", "\320\232\320\273\320\270\320\265\320\275\321\202:", 0));
        lblInfo->setText(QApplication::translate("saleProductDialog", "\320\240\320\260\320\267\320\274\320\265\321\200: ", 0));
        lblSize->setText(QApplication::translate("saleProductDialog", "\320\237\320\276\320\266\320\260\320\273\321\203\320\271\321\201\321\202\320\260, \320\262\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\200\320\260\320\267\320\274\320\265\321\200 \320\270 \320\272\320\273\320\270\320\265\320\275\321\202\320\260:", 0));
        btnAddClient->setText(QApplication::translate("saleProductDialog", "+", 0));
        chbDiscount->setText(QApplication::translate("saleProductDialog", "\320\241\320\272\320\270\320\264\320\272\320\260:", 0));
        spnDiscount->setSuffix(QApplication::translate("saleProductDialog", " \321\200\321\203\320\261.", 0));
        lblCost->setText(QApplication::translate("saleProductDialog", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214:", 0));
        spnCost->setSuffix(QApplication::translate("saleProductDialog", " \321\200\321\203\320\261.", 0));
    } // retranslateUi

};

namespace Ui {
    class saleProductDialog: public Ui_saleProductDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALEPRODUCTDIALOG_H
