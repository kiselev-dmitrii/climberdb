/********************************************************************************
** Form generated from reading UI file 'ClientsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTSDIALOG_H
#define UI_CLIENTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ClientsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gltAddNew;
    QSpacerItem *spacer2;
    QLineEdit *edtAddress;
    QLineEdit *edtMobile;
    QLabel *lblMobile;
    QPushButton *btnAdd;
    QLabel *lblName;
    QLabel *lblSurname;
    QLineEdit *edtName;
    QLineEdit *edtSurname;
    QLabel *lblAddress;
    QSpacerItem *spacer1;
    QPushButton *btnChange;
    QLabel *lblDiscount;
    QSpinBox *spnDiscount;
    QTableView *tvClients;
    QDialogButtonBox *btnBox;

    void setupUi(QDialog *ClientsDialog)
    {
        if (ClientsDialog->objectName().isEmpty())
            ClientsDialog->setObjectName(QStringLiteral("ClientsDialog"));
        ClientsDialog->resize(676, 351);
        verticalLayout = new QVBoxLayout(ClientsDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gltAddNew = new QGridLayout();
        gltAddNew->setObjectName(QStringLiteral("gltAddNew"));
        spacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gltAddNew->addItem(spacer2, 1, 5, 1, 1);

        edtAddress = new QLineEdit(ClientsDialog);
        edtAddress->setObjectName(QStringLiteral("edtAddress"));
        edtAddress->setMinimumSize(QSize(200, 0));
        edtAddress->setMaximumSize(QSize(250, 16777215));

        gltAddNew->addWidget(edtAddress, 1, 4, 1, 1);

        edtMobile = new QLineEdit(ClientsDialog);
        edtMobile->setObjectName(QStringLiteral("edtMobile"));
        edtMobile->setMinimumSize(QSize(200, 0));
        edtMobile->setMaximumSize(QSize(250, 16777215));

        gltAddNew->addWidget(edtMobile, 2, 4, 1, 1);

        lblMobile = new QLabel(ClientsDialog);
        lblMobile->setObjectName(QStringLiteral("lblMobile"));

        gltAddNew->addWidget(lblMobile, 2, 3, 1, 1);

        btnAdd = new QPushButton(ClientsDialog);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));

        gltAddNew->addWidget(btnAdd, 2, 6, 1, 1);

        lblName = new QLabel(ClientsDialog);
        lblName->setObjectName(QStringLiteral("lblName"));

        gltAddNew->addWidget(lblName, 1, 0, 1, 1);

        lblSurname = new QLabel(ClientsDialog);
        lblSurname->setObjectName(QStringLiteral("lblSurname"));

        gltAddNew->addWidget(lblSurname, 2, 0, 1, 1);

        edtName = new QLineEdit(ClientsDialog);
        edtName->setObjectName(QStringLiteral("edtName"));
        edtName->setMaximumSize(QSize(140, 16777215));

        gltAddNew->addWidget(edtName, 1, 1, 1, 1);

        edtSurname = new QLineEdit(ClientsDialog);
        edtSurname->setObjectName(QStringLiteral("edtSurname"));
        edtSurname->setMaximumSize(QSize(140, 16777215));

        gltAddNew->addWidget(edtSurname, 2, 1, 1, 1);

        lblAddress = new QLabel(ClientsDialog);
        lblAddress->setObjectName(QStringLiteral("lblAddress"));

        gltAddNew->addWidget(lblAddress, 1, 3, 1, 1);

        spacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gltAddNew->addItem(spacer1, 1, 2, 1, 1);

        btnChange = new QPushButton(ClientsDialog);
        btnChange->setObjectName(QStringLiteral("btnChange"));

        gltAddNew->addWidget(btnChange, 2, 7, 1, 1);

        lblDiscount = new QLabel(ClientsDialog);
        lblDiscount->setObjectName(QStringLiteral("lblDiscount"));
        lblDiscount->setAlignment(Qt::AlignCenter);

        gltAddNew->addWidget(lblDiscount, 1, 6, 1, 1);

        spnDiscount = new QSpinBox(ClientsDialog);
        spnDiscount->setObjectName(QStringLiteral("spnDiscount"));
        spnDiscount->setMaximum(100);

        gltAddNew->addWidget(spnDiscount, 1, 7, 1, 1);


        verticalLayout->addLayout(gltAddNew);

        tvClients = new QTableView(ClientsDialog);
        tvClients->setObjectName(QStringLiteral("tvClients"));
        tvClients->setSelectionMode(QAbstractItemView::SingleSelection);
        tvClients->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvClients->horizontalHeader()->setStretchLastSection(true);
        tvClients->verticalHeader()->setDefaultSectionSize(19);

        verticalLayout->addWidget(tvClients);

        btnBox = new QDialogButtonBox(ClientsDialog);
        btnBox->setObjectName(QStringLiteral("btnBox"));
        btnBox->setOrientation(Qt::Horizontal);
        btnBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(btnBox);

        QWidget::setTabOrder(edtName, edtSurname);
        QWidget::setTabOrder(edtSurname, edtAddress);
        QWidget::setTabOrder(edtAddress, edtMobile);
        QWidget::setTabOrder(edtMobile, spnDiscount);
        QWidget::setTabOrder(spnDiscount, btnAdd);
        QWidget::setTabOrder(btnAdd, btnChange);
        QWidget::setTabOrder(btnChange, tvClients);
        QWidget::setTabOrder(tvClients, btnBox);

        retranslateUi(ClientsDialog);
        QObject::connect(btnBox, SIGNAL(accepted()), ClientsDialog, SLOT(accept()));
        QObject::connect(btnBox, SIGNAL(rejected()), ClientsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ClientsDialog);
    } // setupUi

    void retranslateUi(QDialog *ClientsDialog)
    {
        ClientsDialog->setWindowTitle(QApplication::translate("ClientsDialog", "\320\232\320\273\320\270\320\265\320\275\321\202\321\213", 0));
        lblMobile->setText(QApplication::translate("ClientsDialog", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275:", 0));
        btnAdd->setText(QApplication::translate("ClientsDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        lblName->setText(QApplication::translate("ClientsDialog", "\320\230\320\274\321\217:", 0));
        lblSurname->setText(QApplication::translate("ClientsDialog", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217:", 0));
        lblAddress->setText(QApplication::translate("ClientsDialog", "\320\220\320\264\321\200\320\265\321\201:", 0));
        btnChange->setText(QApplication::translate("ClientsDialog", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        lblDiscount->setText(QApplication::translate("ClientsDialog", "\320\241\320\272\320\270\320\264\320\272\320\260:", 0));
        spnDiscount->setSuffix(QApplication::translate("ClientsDialog", " %", 0));
    } // retranslateUi

};

namespace Ui {
    class ClientsDialog: public Ui_ClientsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTSDIALOG_H
