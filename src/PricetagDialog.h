#ifndef PRICETAGDIALOG_H
#define PRICETAGDIALOG_H

#include <QDialog>
#include "PricetagGenerator.h"

namespace Ui {
        class PricetagDialog;
}

class PricetagDialog : public QDialog {
public:
        /// Явный конструктор
        explicit                PricetagDialog(QWidget *parent = 0);
        /// Виртуальный деструктор
                                ~PricetagDialog();

private:
        /// Загружает таблицу ценников данными
        void            loadPricetagsTable();
        /// Соединяет виджеты
        void            connectWidgets();

private slots:
        /// Кнопка "Очистить"
        void            clearTags();
        /// Обновляет количество страниц
        void            updateCountOfPages();
        /// Удаляет выделенные ценник
        void            deleteSelectedTag();
        /// Генерирует ценники и открывает браузер
        void            generateTags();

private:
        Ui::PricetagDialog *m_ui;
        Q_OBJECT
};

#endif // PRICETAGDIALOG_H
