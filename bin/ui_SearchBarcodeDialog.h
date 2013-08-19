/********************************************************************************
** Form generated from reading UI file 'SearchBarcodeDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHBARCODEDIALOG_H
#define UI_SEARCHBARCODEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SearchBarcodeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *ltBarcode;
    QLabel *lblBarcode;
    QLineEdit *edtBarcode;
    QTableWidget *twProduct;
    QSpacerItem *spacer;
    QHBoxLayout *ltButtons;
    QPushButton *btnSellProduct;
    QPushButton *btnOpenConsignment;
    QDialogButtonBox *btnBox;

    void setupUi(QDialog *SearchBarcodeDialog)
    {
        if (SearchBarcodeDialog->objectName().isEmpty())
            SearchBarcodeDialog->setObjectName(QStringLiteral("SearchBarcodeDialog"));
        SearchBarcodeDialog->resize(561, 138);
        verticalLayout = new QVBoxLayout(SearchBarcodeDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ltBarcode = new QHBoxLayout();
        ltBarcode->setObjectName(QStringLiteral("ltBarcode"));
        lblBarcode = new QLabel(SearchBarcodeDialog);
        lblBarcode->setObjectName(QStringLiteral("lblBarcode"));

        ltBarcode->addWidget(lblBarcode);

        edtBarcode = new QLineEdit(SearchBarcodeDialog);
        edtBarcode->setObjectName(QStringLiteral("edtBarcode"));

        ltBarcode->addWidget(edtBarcode);


        verticalLayout->addLayout(ltBarcode);

        twProduct = new QTableWidget(SearchBarcodeDialog);
        twProduct->setObjectName(QStringLiteral("twProduct"));
        QFont font;
        font.setPointSize(12);
        twProduct->setFont(font);
        twProduct->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        twProduct->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        twProduct->setAutoScroll(false);
        twProduct->setSelectionMode(QAbstractItemView::SingleSelection);
        twProduct->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(twProduct);

        spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(spacer);

        ltButtons = new QHBoxLayout();
        ltButtons->setObjectName(QStringLiteral("ltButtons"));
        btnSellProduct = new QPushButton(SearchBarcodeDialog);
        btnSellProduct->setObjectName(QStringLiteral("btnSellProduct"));

        ltButtons->addWidget(btnSellProduct);

        btnOpenConsignment = new QPushButton(SearchBarcodeDialog);
        btnOpenConsignment->setObjectName(QStringLiteral("btnOpenConsignment"));

        ltButtons->addWidget(btnOpenConsignment);

        btnBox = new QDialogButtonBox(SearchBarcodeDialog);
        btnBox->setObjectName(QStringLiteral("btnBox"));
        btnBox->setOrientation(Qt::Horizontal);
        btnBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        ltButtons->addWidget(btnBox);


        verticalLayout->addLayout(ltButtons);


        retranslateUi(SearchBarcodeDialog);
        QObject::connect(btnBox, SIGNAL(accepted()), SearchBarcodeDialog, SLOT(accept()));
        QObject::connect(btnBox, SIGNAL(rejected()), SearchBarcodeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SearchBarcodeDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchBarcodeDialog)
    {
        SearchBarcodeDialog->setWindowTitle(QApplication::translate("SearchBarcodeDialog", "\320\237\320\276\320\270\321\201\320\272 \321\202\320\276\320\262\320\260\321\200\320\260 \320\277\320\276 \321\210\321\202\321\200\320\270\321\205\320\272\320\276\320\264\321\203", 0));
        lblBarcode->setText(QApplication::translate("SearchBarcodeDialog", "\320\250\321\202\321\200\320\270\321\205\320\272\320\276\320\264:", 0));
        btnSellProduct->setText(QApplication::translate("SearchBarcodeDialog", "\320\237\321\200\320\276\320\264\320\260\321\202\321\214", 0));
        btnOpenConsignment->setText(QApplication::translate("SearchBarcodeDialog", "\320\222\321\201\320\265 \321\202\320\276\320\262\320\260\321\200\321\213 \320\270\320\267 \320\277\320\260\321\200\321\202\320\270\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class SearchBarcodeDialog: public Ui_SearchBarcodeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHBARCODEDIALOG_H
