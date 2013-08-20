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
        /// Возвращаеn текущий выранный ProductID
        int             selectedProductID();
        /// Возвращает выбранную итоговую цену
        int             selectedSellingCost();

        /// Устанавливает текущий размер
        void            setCurrentSize(const QString& size);

private:
        /// Загружает доступные размеры в cbSizes
        void            loadAvailableSize();
        /// Загружает доступных клиентов в cbClients
        void            loadAvailableClients();
        /// Загружает цену без скидки
        void            loadDefaultCost();
        /// Соединяет виджеты
        void            connectWidgets();
        /// Возвращает скидку для выбранного клиента
        float           currentClientDiscount();

private slots:
        /// Выполняется при нажатии на кнопку "+"
        void            openClientsDialog();
        /// Выполняется при выборе клиента
        void            onChangeClient(int index);
        /// Выполняется при выборе размера
        void            onChangeSize(int index);
        /// Выполняется при клике на chbDiscount
        void            onDiscountClick();
        /// При изменении скидки
        void            onDiscountChange(int value);
        /// При изменении итоговой стоимости
        void            onSellingCostChange(int value);

private:
        Ui::saleProductDialog*  m_ui;
        int                     m_consignmentID;
        int                     m_selectedClientID;
        int                     m_selectedProductID;
        int                     m_defaultCost;

        Q_OBJECT
};

#endif // SALEPRODUCTDIALOG_H
