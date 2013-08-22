#ifndef SALESPLOTDIALOG_H
#define SALESPLOTDIALOG_H

#include <QDialog>

namespace Ui {
        class SalesPlotDialog;
}

/** Класс, представляющий собой диалог для отображения
 *  динамики продаж и получения товаров
 */
class SalesPlotDialog : public QDialog {
public:
        /// Конструктор
        explicit        SalesPlotDialog(QWidget *parent = nullptr);
        /// Виртуальный деструктор
                        ~SalesPlotDialog();
        
private:
        Ui::SalesPlotDialog*    m_ui;
        Q_OBJECT
};

#endif // SALESPLOTDIALOG_H
