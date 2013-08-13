/********************************************************************************
** Form generated from reading UI file 'CreateConsignmentDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECONSIGNMENTDIALOG_H
#define UI_CREATECONSIGNMENTDIALOG_H

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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_dlgCreateConsignment
{
public:
    QGridLayout *gridLayout;
    QComboBox *cbType;
    QLabel *lblCountry;
    QLabel *lblComment;
    QLineEdit *edtModel;
    QSpinBox *spnCost;
    QLabel *lblColor;
    QComboBox *cbColor;
    QLabel *lblGender;
    QLabel *lblCost;
    QDialogButtonBox *btnBox;
    QLineEdit *edtComment;
    QHBoxLayout *ltGender;
    QRadioButton *rbtnUnknown;
    QRadioButton *rbtnMale;
    QRadioButton *rbtnFemale;
    QLabel *lblName;
    QLabel *lblModel;
    QLineEdit *edtName;
    QLabel *lblType;
    QComboBox *cbCountry;
    QLabel *lblAddNewSizes;
    QLineEdit *edtAddNewSizes;

    void setupUi(QDialog *dlgCreateConsignment)
    {
        if (dlgCreateConsignment->objectName().isEmpty())
            dlgCreateConsignment->setObjectName(QStringLiteral("dlgCreateConsignment"));
        dlgCreateConsignment->resize(461, 289);
        gridLayout = new QGridLayout(dlgCreateConsignment);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        cbType = new QComboBox(dlgCreateConsignment);
        cbType->setObjectName(QStringLiteral("cbType"));
        cbType->setEditable(true);

        gridLayout->addWidget(cbType, 6, 1, 1, 1);

        lblCountry = new QLabel(dlgCreateConsignment);
        lblCountry->setObjectName(QStringLiteral("lblCountry"));

        gridLayout->addWidget(lblCountry, 9, 0, 1, 1);

        lblComment = new QLabel(dlgCreateConsignment);
        lblComment->setObjectName(QStringLiteral("lblComment"));

        gridLayout->addWidget(lblComment, 8, 0, 1, 1);

        edtModel = new QLineEdit(dlgCreateConsignment);
        edtModel->setObjectName(QStringLiteral("edtModel"));

        gridLayout->addWidget(edtModel, 2, 1, 1, 1);

        spnCost = new QSpinBox(dlgCreateConsignment);
        spnCost->setObjectName(QStringLiteral("spnCost"));
        spnCost->setMinimum(0);
        spnCost->setMaximum(100000);
        spnCost->setSingleStep(50);

        gridLayout->addWidget(spnCost, 3, 1, 1, 1);

        lblColor = new QLabel(dlgCreateConsignment);
        lblColor->setObjectName(QStringLiteral("lblColor"));

        gridLayout->addWidget(lblColor, 5, 0, 1, 1);

        cbColor = new QComboBox(dlgCreateConsignment);
        cbColor->setObjectName(QStringLiteral("cbColor"));
        cbColor->setEditable(true);

        gridLayout->addWidget(cbColor, 5, 1, 1, 1);

        lblGender = new QLabel(dlgCreateConsignment);
        lblGender->setObjectName(QStringLiteral("lblGender"));

        gridLayout->addWidget(lblGender, 7, 0, 1, 1);

        lblCost = new QLabel(dlgCreateConsignment);
        lblCost->setObjectName(QStringLiteral("lblCost"));

        gridLayout->addWidget(lblCost, 3, 0, 1, 1);

        btnBox = new QDialogButtonBox(dlgCreateConsignment);
        btnBox->setObjectName(QStringLiteral("btnBox"));
        btnBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(btnBox, 11, 0, 1, 2);

        edtComment = new QLineEdit(dlgCreateConsignment);
        edtComment->setObjectName(QStringLiteral("edtComment"));

        gridLayout->addWidget(edtComment, 8, 1, 1, 1);

        ltGender = new QHBoxLayout();
        ltGender->setObjectName(QStringLiteral("ltGender"));
        rbtnUnknown = new QRadioButton(dlgCreateConsignment);
        rbtnUnknown->setObjectName(QStringLiteral("rbtnUnknown"));

        ltGender->addWidget(rbtnUnknown);

        rbtnMale = new QRadioButton(dlgCreateConsignment);
        rbtnMale->setObjectName(QStringLiteral("rbtnMale"));

        ltGender->addWidget(rbtnMale);

        rbtnFemale = new QRadioButton(dlgCreateConsignment);
        rbtnFemale->setObjectName(QStringLiteral("rbtnFemale"));

        ltGender->addWidget(rbtnFemale);


        gridLayout->addLayout(ltGender, 7, 1, 1, 1);

        lblName = new QLabel(dlgCreateConsignment);
        lblName->setObjectName(QStringLiteral("lblName"));

        gridLayout->addWidget(lblName, 0, 0, 1, 1);

        lblModel = new QLabel(dlgCreateConsignment);
        lblModel->setObjectName(QStringLiteral("lblModel"));

        gridLayout->addWidget(lblModel, 2, 0, 1, 1);

        edtName = new QLineEdit(dlgCreateConsignment);
        edtName->setObjectName(QStringLiteral("edtName"));

        gridLayout->addWidget(edtName, 0, 1, 1, 1);

        lblType = new QLabel(dlgCreateConsignment);
        lblType->setObjectName(QStringLiteral("lblType"));

        gridLayout->addWidget(lblType, 6, 0, 1, 1);

        cbCountry = new QComboBox(dlgCreateConsignment);
        cbCountry->setObjectName(QStringLiteral("cbCountry"));
        cbCountry->setEditable(true);

        gridLayout->addWidget(cbCountry, 9, 1, 1, 1);

        lblAddNewSizes = new QLabel(dlgCreateConsignment);
        lblAddNewSizes->setObjectName(QStringLiteral("lblAddNewSizes"));

        gridLayout->addWidget(lblAddNewSizes, 4, 0, 1, 1);

        edtAddNewSizes = new QLineEdit(dlgCreateConsignment);
        edtAddNewSizes->setObjectName(QStringLiteral("edtAddNewSizes"));

        gridLayout->addWidget(edtAddNewSizes, 4, 1, 1, 1);

        QWidget::setTabOrder(edtName, edtModel);
        QWidget::setTabOrder(edtModel, spnCost);
        QWidget::setTabOrder(spnCost, edtAddNewSizes);
        QWidget::setTabOrder(edtAddNewSizes, cbColor);
        QWidget::setTabOrder(cbColor, cbType);
        QWidget::setTabOrder(cbType, rbtnUnknown);
        QWidget::setTabOrder(rbtnUnknown, rbtnMale);
        QWidget::setTabOrder(rbtnMale, rbtnFemale);
        QWidget::setTabOrder(rbtnFemale, edtComment);
        QWidget::setTabOrder(edtComment, cbCountry);
        QWidget::setTabOrder(cbCountry, btnBox);

        retranslateUi(dlgCreateConsignment);

        QMetaObject::connectSlotsByName(dlgCreateConsignment);
    } // setupUi

    void retranslateUi(QDialog *dlgCreateConsignment)
    {
        dlgCreateConsignment->setWindowTitle(QApplication::translate("dlgCreateConsignment", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\213\320\271 \321\202\320\276\320\262\320\260\321\200", 0));
        lblCountry->setText(QApplication::translate("dlgCreateConsignment", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\214:", 0));
        lblComment->setText(QApplication::translate("dlgCreateConsignment", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\270:", 0));
        lblColor->setText(QApplication::translate("dlgCreateConsignment", "\320\246\320\262\320\265\321\202:", 0));
        lblGender->setText(QApplication::translate("dlgCreateConsignment", "\320\237\320\276\320\273:", 0));
        lblCost->setText(QApplication::translate("dlgCreateConsignment", "\320\246\320\265\320\275\320\260:", 0));
        rbtnUnknown->setText(QApplication::translate("dlgCreateConsignment", "\320\235\320\265\320\270\320\267\320\262.", 0));
        rbtnMale->setText(QApplication::translate("dlgCreateConsignment", "\320\234\321\203\320\266.", 0));
        rbtnFemale->setText(QApplication::translate("dlgCreateConsignment", "\320\226\320\265\320\275.", 0));
        lblName->setText(QApplication::translate("dlgCreateConsignment", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265:", 0));
        lblModel->setText(QApplication::translate("dlgCreateConsignment", "\320\234\320\276\320\264\320\265\320\273\321\214:", 0));
        lblType->setText(QApplication::translate("dlgCreateConsignment", "\320\242\320\270\320\277:", 0));
        lblAddNewSizes->setText(QApplication::translate("dlgCreateConsignment", "\320\240\320\260\320\267\320\274\320\265\321\200\321\213:", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgCreateConsignment: public Ui_dlgCreateConsignment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECONSIGNMENTDIALOG_H
