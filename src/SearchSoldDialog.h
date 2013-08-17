#ifndef SEARCHSOLDDIALOG_H
#define SEARCHSOLDDIALOG_H

#include <QDialog>

namespace Ui {
        class SearchSoldDialog;
}

/** Диалог поиска по проданному товару
 */
class SearchSoldDialog : public QDialog {
public:
        /// Конструктор.
        explicit        SearchSoldDialog(QWidget *parent = nullptr);
        /// Виртуальный деструктор
                        ~SearchSoldDialog();

private:
        /// Инициализирует даты виджетов
        void            initDates();
        /// Загружает таблицу моделью
        void            loadTableData();
        /// Соединяет виджеты
        void            connectWidgets();

private slots:
        /// Выполняется при нажатии на кнопку поиск
        void            find();

private:
        Ui::SearchSoldDialog*   m_ui;
        Q_OBJECT
};

#endif // SEARCHSOLDDIALOG_H
