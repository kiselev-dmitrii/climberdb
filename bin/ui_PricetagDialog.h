/********************************************************************************
** Form generated from reading UI file 'PricetagDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRICETAGDIALOG_H
#define UI_PRICETAGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_PricetagDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *lblInfo;
    QGroupBox *gbPricetags;
    QGridLayout *gridLayout_2;
    QPushButton *btnRemoveTag;
    QPushButton *btnClearTags;
    QTableWidget *twTags;
    QLabel *lblInfoPages;
    QDialogButtonBox *btnBox;
    QLabel *lblCountOfPages;

    void setupUi(QDialog *PricetagDialog)
    {
        if (PricetagDialog->objectName().isEmpty())
            PricetagDialog->setObjectName(QStringLiteral("PricetagDialog"));
        PricetagDialog->resize(304, 358);
        gridLayout = new QGridLayout(PricetagDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lblInfo = new QLabel(PricetagDialog);
        lblInfo->setObjectName(QStringLiteral("lblInfo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblInfo->sizePolicy().hasHeightForWidth());
        lblInfo->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lblInfo, 0, 0, 1, 3);

        gbPricetags = new QGroupBox(PricetagDialog);
        gbPricetags->setObjectName(QStringLiteral("gbPricetags"));
        gridLayout_2 = new QGridLayout(gbPricetags);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(3, 1, 3, 3);
        btnRemoveTag = new QPushButton(gbPricetags);
        btnRemoveTag->setObjectName(QStringLiteral("btnRemoveTag"));

        gridLayout_2->addWidget(btnRemoveTag, 1, 0, 1, 1);

        btnClearTags = new QPushButton(gbPricetags);
        btnClearTags->setObjectName(QStringLiteral("btnClearTags"));

        gridLayout_2->addWidget(btnClearTags, 1, 1, 1, 1);

        twTags = new QTableWidget(gbPricetags);
        twTags->setObjectName(QStringLiteral("twTags"));
        twTags->setSelectionMode(QAbstractItemView::SingleSelection);
        twTags->setSelectionBehavior(QAbstractItemView::SelectRows);
        twTags->horizontalHeader()->setStretchLastSection(true);
        twTags->verticalHeader()->setDefaultSectionSize(19);

        gridLayout_2->addWidget(twTags, 0, 0, 1, 2);


        gridLayout->addWidget(gbPricetags, 1, 0, 1, 4);

        lblInfoPages = new QLabel(PricetagDialog);
        lblInfoPages->setObjectName(QStringLiteral("lblInfoPages"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblInfoPages->sizePolicy().hasHeightForWidth());
        lblInfoPages->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lblInfoPages, 3, 0, 1, 1);

        btnBox = new QDialogButtonBox(PricetagDialog);
        btnBox->setObjectName(QStringLiteral("btnBox"));
        btnBox->setOrientation(Qt::Horizontal);
        btnBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(btnBox, 4, 1, 1, 3);

        lblCountOfPages = new QLabel(PricetagDialog);
        lblCountOfPages->setObjectName(QStringLiteral("lblCountOfPages"));
        sizePolicy1.setHeightForWidth(lblCountOfPages->sizePolicy().hasHeightForWidth());
        lblCountOfPages->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lblCountOfPages, 3, 1, 1, 3);


        retranslateUi(PricetagDialog);
        QObject::connect(btnBox, SIGNAL(accepted()), PricetagDialog, SLOT(accept()));
        QObject::connect(btnBox, SIGNAL(rejected()), PricetagDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PricetagDialog);
    } // setupUi

    void retranslateUi(QDialog *PricetagDialog)
    {
        PricetagDialog->setWindowTitle(QApplication::translate("PricetagDialog", "\320\223\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \321\206\320\265\320\275\320\275\320\270\320\272\320\276\320\262", 0));
        lblInfo->setText(QApplication::translate("PricetagDialog", "\320\221\321\203\320\264\321\203\321\202 \321\201\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\320\275\321\213 \321\206\320\265\320\275\320\275\320\270\320\272\320\270 \320\275\320\260 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\265 \321\202\320\276\320\262\320\260\321\200\321\213.", 0));
        gbPricetags->setTitle(QApplication::translate("PricetagDialog", "\320\246\320\265\320\275\320\275\320\270\320\272\320\270:", 0));
        btnRemoveTag->setText(QApplication::translate("PricetagDialog", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        btnClearTags->setText(QApplication::translate("PricetagDialog", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\262\320\265\321\201\321\214 \321\201\320\277\320\270\321\201\320\276\320\272", 0));
        lblInfoPages->setText(QApplication::translate("PricetagDialog", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\321\202\321\200\320\260\320\275\320\275\320\270\321\206:", 0));
        lblCountOfPages->setText(QApplication::translate("PricetagDialog", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class PricetagDialog: public Ui_PricetagDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRICETAGDIALOG_H
