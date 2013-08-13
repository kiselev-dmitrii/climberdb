/********************************************************************************
** Form generated from reading UI file 'EditConsignmentDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITCONSIGNMENTDIALOG_H
#define UI_EDITCONSIGNMENTDIALOG_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_dlgEditConsignment
{
public:
    QGridLayout *gridLayout;
    QSpinBox *spnCost;
    QLabel *lblCost;
    QGroupBox *gbProducts;
    QHBoxLayout *horizontalLayout;
    QTableView *tvProducts;
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
    QHBoxLayout *ltGender;
    QRadioButton *rbtnUnknown;
    QRadioButton *rbtnMale;
    QRadioButton *rbtnFemale;
    QLabel *lblAddNewSizes;
    QHBoxLayout *ltAddNewSizes;
    QLineEdit *edtAddNewSizes;
    QPushButton *btnAddNewSizes;

    void setupUi(QDialog *dlgEditConsignment)
    {
        if (dlgEditConsignment->objectName().isEmpty())
            dlgEditConsignment->setObjectName(QStringLiteral("dlgEditConsignment"));
        dlgEditConsignment->resize(604, 492);
        gridLayout = new QGridLayout(dlgEditConsignment);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        spnCost = new QSpinBox(dlgEditConsignment);
        spnCost->setObjectName(QStringLiteral("spnCost"));
        spnCost->setMinimum(0);
        spnCost->setMaximum(100000);
        spnCost->setSingleStep(50);

        gridLayout->addWidget(spnCost, 3, 2, 1, 1);

        lblCost = new QLabel(dlgEditConsignment);
        lblCost->setObjectName(QStringLiteral("lblCost"));

        gridLayout->addWidget(lblCost, 3, 0, 1, 1);

        gbProducts = new QGroupBox(dlgEditConsignment);
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


        gridLayout->addWidget(gbProducts, 9, 0, 1, 3);

        btnBox = new QDialogButtonBox(dlgEditConsignment);
        btnBox->setObjectName(QStringLiteral("btnBox"));
        btnBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(btnBox, 11, 0, 1, 3);

        edtComment = new QLineEdit(dlgEditConsignment);
        edtComment->setObjectName(QStringLiteral("edtComment"));

        gridLayout->addWidget(edtComment, 7, 2, 1, 1);

        cbColor = new QComboBox(dlgEditConsignment);
        cbColor->setObjectName(QStringLiteral("cbColor"));
        cbColor->setEditable(true);

        gridLayout->addWidget(cbColor, 4, 2, 1, 1);

        cbType = new QComboBox(dlgEditConsignment);
        cbType->setObjectName(QStringLiteral("cbType"));
        cbType->setEditable(true);

        gridLayout->addWidget(cbType, 5, 2, 1, 1);

        lblCountry = new QLabel(dlgEditConsignment);
        lblCountry->setObjectName(QStringLiteral("lblCountry"));

        gridLayout->addWidget(lblCountry, 8, 0, 1, 1);

        lblComment = new QLabel(dlgEditConsignment);
        lblComment->setObjectName(QStringLiteral("lblComment"));

        gridLayout->addWidget(lblComment, 7, 0, 1, 1);

        lblColor = new QLabel(dlgEditConsignment);
        lblColor->setObjectName(QStringLiteral("lblColor"));

        gridLayout->addWidget(lblColor, 4, 0, 1, 1);

        cbCountry = new QComboBox(dlgEditConsignment);
        cbCountry->setObjectName(QStringLiteral("cbCountry"));
        cbCountry->setEditable(true);

        gridLayout->addWidget(cbCountry, 8, 2, 1, 1);

        lblType = new QLabel(dlgEditConsignment);
        lblType->setObjectName(QStringLiteral("lblType"));

        gridLayout->addWidget(lblType, 5, 0, 1, 1);

        lblGender = new QLabel(dlgEditConsignment);
        lblGender->setObjectName(QStringLiteral("lblGender"));

        gridLayout->addWidget(lblGender, 6, 0, 1, 1);

        edtName = new QLineEdit(dlgEditConsignment);
        edtName->setObjectName(QStringLiteral("edtName"));

        gridLayout->addWidget(edtName, 0, 2, 1, 1);

        lblModel = new QLabel(dlgEditConsignment);
        lblModel->setObjectName(QStringLiteral("lblModel"));

        gridLayout->addWidget(lblModel, 2, 0, 1, 1);

        edtModel = new QLineEdit(dlgEditConsignment);
        edtModel->setObjectName(QStringLiteral("edtModel"));

        gridLayout->addWidget(edtModel, 2, 2, 1, 1);

        lblName = new QLabel(dlgEditConsignment);
        lblName->setObjectName(QStringLiteral("lblName"));

        gridLayout->addWidget(lblName, 0, 0, 1, 1);

        ltGender = new QHBoxLayout();
        ltGender->setObjectName(QStringLiteral("ltGender"));
        rbtnUnknown = new QRadioButton(dlgEditConsignment);
        rbtnUnknown->setObjectName(QStringLiteral("rbtnUnknown"));

        ltGender->addWidget(rbtnUnknown);

        rbtnMale = new QRadioButton(dlgEditConsignment);
        rbtnMale->setObjectName(QStringLiteral("rbtnMale"));

        ltGender->addWidget(rbtnMale);

        rbtnFemale = new QRadioButton(dlgEditConsignment);
        rbtnFemale->setObjectName(QStringLiteral("rbtnFemale"));

        ltGender->addWidget(rbtnFemale);


        gridLayout->addLayout(ltGender, 6, 2, 1, 1);

        lblAddNewSizes = new QLabel(dlgEditConsignment);
        lblAddNewSizes->setObjectName(QStringLiteral("lblAddNewSizes"));

        gridLayout->addWidget(lblAddNewSizes, 10, 0, 1, 1);

        ltAddNewSizes = new QHBoxLayout();
        ltAddNewSizes->setObjectName(QStringLiteral("ltAddNewSizes"));
        ltAddNewSizes->setSizeConstraint(QLayout::SetDefaultConstraint);
        edtAddNewSizes = new QLineEdit(dlgEditConsignment);
        edtAddNewSizes->setObjectName(QStringLiteral("edtAddNewSizes"));

        ltAddNewSizes->addWidget(edtAddNewSizes);

        btnAddNewSizes = new QPushButton(dlgEditConsignment);
        btnAddNewSizes->setObjectName(QStringLiteral("btnAddNewSizes"));

        ltAddNewSizes->addWidget(btnAddNewSizes);


        gridLayout->addLayout(ltAddNewSizes, 10, 2, 1, 1);


        retranslateUi(dlgEditConsignment);

        QMetaObject::connectSlotsByName(dlgEditConsignment);
    } // setupUi

    void retranslateUi(QDialog *dlgEditConsignment)
    {
        dlgEditConsignment->setWindowTitle(QApplication::translate("dlgEditConsignment", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\264\320\260\320\275\320\275\321\213\321\205 \321\202\320\276\320\262\320\260\321\200\320\260", 0));
        lblCost->setText(QApplication::translate("dlgEditConsignment", "\320\246\320\265\320\275\320\260:", 0));
        gbProducts->setTitle(QApplication::translate("dlgEditConsignment", "\320\222 \320\275\320\260\320\273\320\270\321\207\320\270\320\270: ", 0));
        lblCountry->setText(QApplication::translate("dlgEditConsignment", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\214:", 0));
        lblComment->setText(QApplication::translate("dlgEditConsignment", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\270:", 0));
        lblColor->setText(QApplication::translate("dlgEditConsignment", "\320\246\320\262\320\265\321\202:", 0));
        lblType->setText(QApplication::translate("dlgEditConsignment", "\320\242\320\270\320\277:", 0));
        lblGender->setText(QApplication::translate("dlgEditConsignment", "\320\237\320\276\320\273:", 0));
        lblModel->setText(QApplication::translate("dlgEditConsignment", "\320\234\320\276\320\264\320\265\320\273\321\214:", 0));
        lblName->setText(QApplication::translate("dlgEditConsignment", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265:", 0));
        rbtnUnknown->setText(QApplication::translate("dlgEditConsignment", "\320\235\320\265\320\270\320\267\320\262.", 0));
        rbtnMale->setText(QApplication::translate("dlgEditConsignment", "\320\234\321\203\320\266.", 0));
        rbtnFemale->setText(QApplication::translate("dlgEditConsignment", "\320\226\320\265\320\275.", 0));
        lblAddNewSizes->setText(QApplication::translate("dlgEditConsignment", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\213\320\265 \321\200\320\260\320\267\320\274\320\265\321\200\321\213:", 0));
        btnAddNewSizes->setText(QApplication::translate("dlgEditConsignment", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgEditConsignment: public Ui_dlgEditConsignment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCONSIGNMENTDIALOG_H
