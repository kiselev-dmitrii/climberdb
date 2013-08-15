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

        /// Возвращает текущий выбранный clientID
        int             selectedClientID();
        /// Возвращаеn текущий выранный размер
        int             selectedProductID();

private:
        /// Загружает доступные размеры в cbSizes
        void            loadAvailableSize();
        /// Загружает доступных клиентов в cbClients
        void            loadAvailableClients();
        /// Соединяет виджеты
        void            connectWidgets();

private slots:
        /// Выполняется при нажатии на кнопку "+"
        void            openClientsDialog();
        /// Выполняется при выборе клиента
        void            onChangeClient(int index);
        /// Выполняется при выборе размера
        void            onChangeSize(int index);

private:
        Ui::saleProductDialog*  m_ui;
        int                     m_consignmentID;
        int                     m_selectedClientID;
        int                     m_selectedProductID;

        Q_OBJECT
};

#endif // SALEPRODUCTDIALOG_H
