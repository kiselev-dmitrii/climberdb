#ifndef SEARCHBARCODEDIALOG_H
#define SEARCHBARCODEDIALOG_H

#include <QDialog>

namespace Ui {
        class SearchBarcodeDialog;
}

class SearchBarcodeDialog : public QDialog {
public:
        /// Конструктор
        explicit        SearchBarcodeDialog(QWidget *parent = nullptr);
        /// Виртуальный деструктор
                        ~SearchBarcodeDialog();
        
private:
        /// Устанавливает модель для tvProduct
        void            loadTable();
        /// Соединяет виджеты
        void            connectWidgets();

        /// Выполняет поиск по штрихкоду
        void            findProductByBarcode(const QString& barcode);

private slots:
        /// Выполняется при изменении edtBarcode
        void            onEdtBarcodeChange();
        /// Выполняет продажу товара
        void            sellProduct();
        /// Открывает партию товара
        void            openConsignmentDialog();

private:
        Ui::SearchBarcodeDialog*        m_ui;
        Q_OBJECT
};

#endif // SEARCHBARCODEDIALOG_H
