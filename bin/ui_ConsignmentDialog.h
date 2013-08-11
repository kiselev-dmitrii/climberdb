/********************************************************************************
** Form generated from reading UI file 'ConsignmentDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSIGNMENTDIALOG_H
#define UI_CONSIGNMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_dlgConsignment
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *btnBox;
    QLineEdit *edtComment;
    QComboBox *cbColor;
    QComboBox *cbType;
    QLabel *lblCountry;
    QLabel *lblComment;
    QLabel *lblColor;
    QComboBox *cbCountry;
    QLabel *lblType;
    QLabel *lblGender;
    QLineEdit *edtName;
    QLabel *lblModel;
    QLineEdit *edtModel;
    QLabel *lblName;
    QSpinBox *spnCost;
    QLabel *lblCost;
    QHBoxLayout *ltGender;
    QRadioButton *rbtnUnknown;
    QRadioButton *rbtnMale;
    QRadioButton *rbtnFemale;
    QGroupBox *gbProducts;
    QHBoxLayout *horizontalLayout;
    QTableView *tvProducts;

    void setupUi(QDialog *dlgConsignment)
    {
        if (dlgConsignment->objectName().isEmpty())
            dlgConsignment->setObjectName(QStringLiteral("dlgConsignment"));
        dlgConsignment->resize(604, 461);
        gridLayout = new QGridLayout(dlgConsignment);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btnBox = new QDialogButtonBox(dlgConsignment);
        btnBox->setObjectName(QStringLiteral("btnBox"));
        btnBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(btnBox, 10, 0, 1, 2);

        edtComment = new QLineEdit(dlgConsignment);
        edtComment->setObjectName(QStringLiteral("edtComment"));

        gridLayout->addWidget(edtComment, 7, 1, 1, 1);

        cbColor = new QComboBox(dlgConsignment);
        cbColor->setObjectName(QStringLiteral("cbColor"));
        cbColor->setEditable(true);

        gridLayout->addWidget(cbColor, 4, 1, 1, 1);

        cbType = new QComboBox(dlgConsignment);
        cbType->setObjectName(QStringLiteral("cbType"));
        cbType->setEditable(true);

        gridLayout->addWidget(cbType, 5, 1, 1, 1);

        lblCountry = new QLabel(dlgConsignment);
        lblCountry->setObjectName(QStringLiteral("lblCountry"));

        gridLayout->addWidget(lblCountry, 8, 0, 1, 1);

        lblComment = new QLabel(dlgConsignment);
        lblComment->setObjectName(QStringLiteral("lblComment"));

        gridLayout->addWidget(lblComment, 7, 0, 1, 1);

        lblColor = new QLabel(dlgConsignment);
        lblColor->setObjectName(QStringLiteral("lblColor"));

        gridLayout->addWidget(lblColor, 4, 0, 1, 1);

        cbCountry = new QComboBox(dlgConsignment);
        cbCountry->setObjectName(QStringLiteral("cbCountry"));
        cbCountry->setEditable(true);

        gridLayout->addWidget(cbCountry, 8, 1, 1, 1);

        lblType = new QLabel(dlgConsignment);
        lblType->setObjectName(QStringLiteral("lblType"));

        gridLayout->addWidget(lblType, 5, 0, 1, 1);

        lblGender = new QLabel(dlgConsignment);
        lblGender->setObjectName(QStringLiteral("lblGender"));

        gridLayout->addWidget(lblGender, 6, 0, 1, 1);

        edtName = new QLineEdit(dlgConsignment);
        edtName->setObjectName(QStringLiteral("edtName"));

        gridLayout->addWidget(edtName, 0, 1, 1, 1);

        lblModel = new QLabel(dlgConsignment);
        lblModel->setObjectName(QStringLiteral("lblModel"));

        gridLayout->addWidget(lblModel, 2, 0, 1, 1);

        edtModel = new QLineEdit(dlgConsignment);
        edtModel->setObjectName(QStringLiteral("edtModel"));

        gridLayout->addWidget(edtModel, 2, 1, 1, 1);

        lblName = new QLabel(dlgConsignment);
        lblName->setObjectName(QStringLiteral("lblName"));

        gridLayout->addWidget(lblName, 0, 0, 1, 1);

        spnCost = new QSpinBox(dlgConsignment);
        spnCost->setObjectName(QStringLiteral("spnCost"));
        spnCost->setMinimum(0);
        spnCost->setMaximum(100000);
        spnCost->setSingleStep(50);

        gridLayout->addWidget(spnCost, 3, 1, 1, 1);

        lblCost = new QLabel(dlgConsignment);
        lblCost->setObjectName(QStringLiteral("lblCost"));

        gridLayout->addWidget(lblCost, 3, 0, 1, 1);

        ltGender = new QHBoxLayout();
        ltGender->setObjectName(QStringLiteral("ltGender"));
        rbtnUnknown = new QRadioButton(dlgConsignment);
        rbtnUnknown->setObjectName(QStringLiteral("rbtnUnknown"));

        ltGender->addWidget(rbtnUnknown);

        rbtnMale = new QRadioButton(dlgConsignment);
        rbtnMale->setObjectName(QStringLiteral("rbtnMale"));

        ltGender->addWidget(rbtnMale);

        rbtnFemale = new QRadioButton(dlgConsignment);
        rbtnFemale->setObjectName(QStringLiteral("rbtnFemale"));

        ltGender->addWidget(rbtnFemale);


        gridLayout->addLayout(ltGender, 6, 1, 1, 1);

        gbProducts = new QGroupBox(dlgConsignment);
        gbProducts->setObjectName(QStringLiteral("gbProducts"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gbProducts->sizePolicy().hasHeightForWidth());
        gbProducts->setSizePolicy(sizePolicy);
        gbProducts->setMinimumSize(QSize(0, 0));
        gbProducts->setFlat(true);
        horizontalLayout = new QHBoxLayout(gbProducts);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tvProducts = new QTableView(gbProducts);
        tvProducts->setObjectName(QStringLiteral("tvProducts"));
        tvProducts->horizontalHeader()->setStretchLastSection(true);
        tvProducts->verticalHeader()->setDefaultSectionSize(19);

        horizontalLayout->addWidget(tvProducts);


        gridLayout->addWidget(gbProducts, 9, 0, 1, 2);


        retranslateUi(dlgConsignment);

        QMetaObject::connectSlotsByName(dlgConsignment);
    } // setupUi

    void retranslateUi(QDialog *dlgConsignment)
    {
        dlgConsignment->setWindowTitle(QApplication::translate("dlgConsignment", "Dialog", 0));
        lblCountry->setText(QApplication::translate("dlgConsignment", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\214:", 0));
        lblComment->setText(QApplication::translate("dlgConsignment", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\270:", 0));
        lblColor->setText(QApplication::translate("dlgConsignment", "\320\246\320\262\320\265\321\202:", 0));
        lblType->setText(QApplication::translate("dlgConsignment", "\320\242\320\270\320\277:", 0));
        lblGender->setText(QApplication::translate("dlgConsignment", "\320\237\320\276\320\273:", 0));
        lblModel->setText(QApplication::translate("dlgConsignment", "\320\234\320\276\320\264\320\265\320\273\321\214:", 0));
        lblName->setText(QApplication::translate("dlgConsignment", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265:", 0));
        lblCost->setText(QApplication::translate("dlgConsignment", "\320\246\320\265\320\275\320\260:", 0));
        rbtnUnknown->setText(QApplication::translate("dlgConsignment", "\320\235\320\265\320\270\320\267\320\262.", 0));
        rbtnMale->setText(QApplication::translate("dlgConsignment", "\320\234\321\203\320\266.", 0));
        rbtnFemale->setText(QApplication::translate("dlgConsignment", "\320\226\320\265\320\275.", 0));
        gbProducts->setTitle(QApplication::translate("dlgConsignment", "\320\222 \320\275\320\260\320\273\320\270\321\207\320\270\320\270: ", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgConsignment: public Ui_dlgConsignment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSIGNMENTDIALOG_H
