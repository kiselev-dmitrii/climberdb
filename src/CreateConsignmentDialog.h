#ifndef CREATECONSIGNMENTDIALOG_H
#define CREATECONSIGNMENTDIALOG_H

#include <QDialog>

namespace Ui {
        class dlgCreateConsignment;
}

class CreateConsignmentDialog : public QDialog {
public:
        /// Конструктор
        explicit        CreateConsignmentDialog(QWidget* parent = nullptr);
        /// Виртуальный деструктор
                        ~CreateConsignmentDialog();

private:
        /// Загрузка содержимого Combobox
        void            loadItemsForComboboxes();
        /// Соединение виджетов
        void            connectWidgets();

private slots:
        /// Сохранение данных в БД. Возвращает ConsignmentID добавленной записи
        int             saveData();
        int             saveConsignmentData();
        void            saveProductsData(int consignmentID);

        /// Проверяет поля на правильность запролнения
        void            validateFields();

private:
        Ui::dlgCreateConsignment*     m_ui;

        Q_OBJECT
};

#endif // CREATECONSIGNMENTDIALOG_H
