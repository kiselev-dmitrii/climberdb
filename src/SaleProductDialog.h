#ifndef SALEPRODUCTDIALOG_H
#define SALEPRODUCTDIALOG_H

#include <QDialog>
#include "Database.h"

namespace Ui {
        class saleProductDialog;
}

/** Диалог продажи товара
 */
class SaleProductDialog : public QDialog {
public:
        /// Конструктор
        explicit        SaleProductDialog(int consignmentID, QWidget *parent = 0);
        /// Виртуальный деструктор
                        ~SaleProductDialog();

private:
        void            loadAvailableSize();
        void            loadAvailableClients();
        void            connectWidgets();

private slots:
        void            openClientsDialog();
        
private:
        Ui::saleProductDialog*  m_ui;
        QVector<Product>        m_availableProducts;
        int                     m_consignmentID;

        Q_OBJECT
};

#endif // SALEPRODUCTDIALOG_H
