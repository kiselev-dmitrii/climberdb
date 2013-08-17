/********************************************************************************
** Form generated from reading UI file 'SearchSoldDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHSOLDDIALOG_H
#define UI_SEARCHSOLDDIALOG_H

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
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SearchSoldDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gltFields;
    QLabel *lblType;
    QLabel *lblModel;
    QLabel *lblName;
    QLineEdit *edtName;
    QLineEdit *edtModel;
    QLabel *lblSize;
    QLineEdit *edtSize;
    QLineEdit *edtType;
    QTableView *tableView;
    QHBoxLayout *ltPeriod;
    QLabel *lblFrom;
    QDateEdit *deFrom;
    QLabel *lblTo;
    QDateEdit *deTo;
    QSpacerItem *spacer;
    QPushButton *btnFind;

    void setupUi(QDialog *SearchSoldDialog)
    {
        if (SearchSoldDialog->objectName().isEmpty())
            SearchSoldDialog->setObjectName(QStringLiteral("SearchSoldDialog"));
        SearchSoldDialog->resize(696, 368);
        verticalLayout = new QVBoxLayout(SearchSoldDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gltFields = new QGridLayout();
        gltFields->setObjectName(QStringLiteral("gltFields"));
        lblType = new QLabel(SearchSoldDialog);
        lblType->setObjectName(QStringLiteral("lblType"));

        gltFields->addWidget(lblType, 1, 2, 1, 1);

        lblModel = new QLabel(SearchSoldDialog);
        lblModel->setObjectName(QStringLiteral("lblModel"));

        gltFields->addWidget(lblModel, 1, 0, 1, 1);

        lblName = new QLabel(SearchSoldDialog);
        lblName->setObjectName(QStringLiteral("lblName"));

        gltFields->addWidget(lblName, 0, 0, 1, 1);

        edtName = new QLineEdit(SearchSoldDialog);
        edtName->setObjectName(QStringLiteral("edtName"));

        gltFields->addWidget(edtName, 0, 1, 1, 1);

        edtModel = new QLineEdit(SearchSoldDialog);
        edtModel->setObjectName(QStringLiteral("edtModel"));

        gltFields->addWidget(edtModel, 1, 1, 1, 1);

        lblSize = new QLabel(SearchSoldDialog);
        lblSize->setObjectName(QStringLiteral("lblSize"));

        gltFields->addWidget(lblSize, 0, 2, 1, 1);

        edtSize = new QLineEdit(SearchSoldDialog);
        edtSize->setObjectName(QStringLiteral("edtSize"));

        gltFields->addWidget(edtSize, 0, 3, 1, 1);

        edtType = new QLineEdit(SearchSoldDialog);
        edtType->setObjectName(QStringLiteral("edtType"));

        gltFields->addWidget(edtType, 1, 3, 1, 1);


        verticalLayout->addLayout(gltFields);

        tableView = new QTableView(SearchSoldDialog);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setDefaultSectionSize(19);

        verticalLayout->addWidget(tableView);

        ltPeriod = new QHBoxLayout();
        ltPeriod->setObjectName(QStringLiteral("ltPeriod"));
        lblFrom = new QLabel(SearchSoldDialog);
        lblFrom->setObjectName(QStringLiteral("lblFrom"));

        ltPeriod->addWidget(lblFrom);

        deFrom = new QDateEdit(SearchSoldDialog);
        deFrom->setObjectName(QStringLiteral("deFrom"));

        ltPeriod->addWidget(deFrom);

        lblTo = new QLabel(SearchSoldDialog);
        lblTo->setObjectName(QStringLiteral("lblTo"));

        ltPeriod->addWidget(lblTo);

        deTo = new QDateEdit(SearchSoldDialog);
        deTo->setObjectName(QStringLiteral("deTo"));
        deTo->setCalendarPopup(true);

        ltPeriod->addWidget(deTo);

        spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ltPeriod->addItem(spacer);

        btnFind = new QPushButton(SearchSoldDialog);
        btnFind->setObjectName(QStringLiteral("btnFind"));

        ltPeriod->addWidget(btnFind);


        verticalLayout->addLayout(ltPeriod);


        retranslateUi(SearchSoldDialog);

        QMetaObject::connectSlotsByName(SearchSoldDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchSoldDialog)
    {
        SearchSoldDialog->setWindowTitle(QApplication::translate("SearchSoldDialog", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\277\321\200\320\276\320\264\320\260\320\275\320\275\320\276\320\274\321\203 \321\202\320\276\320\262\320\260\321\200\321\203", 0));
        lblType->setText(QApplication::translate("SearchSoldDialog", "\320\242\320\270\320\277:", 0));
        lblModel->setText(QApplication::translate("SearchSoldDialog", "\320\234\320\276\320\264\320\265\320\273\321\214:", 0));
        lblName->setText(QApplication::translate("SearchSoldDialog", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265:", 0));
        lblSize->setText(QApplication::translate("SearchSoldDialog", "\320\240\320\260\320\267\320\274\320\265\321\200:", 0));
        lblFrom->setText(QApplication::translate("SearchSoldDialog", "\320\230\321\201\320\272\320\260\321\202\321\214 \321\201 ", 0));
        lblTo->setText(QApplication::translate("SearchSoldDialog", " \320\277\320\276 ", 0));
        btnFind->setText(QApplication::translate("SearchSoldDialog", "\320\237\320\276\320\270\321\201\320\272", 0));
    } // retranslateUi

};

namespace Ui {
    class SearchSoldDialog: public Ui_SearchSoldDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHSOLDDIALOG_H
