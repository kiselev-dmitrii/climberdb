#ifndef CREATECONSIGNMENTDIALOG_H
#define CREATECONSIGNMENTDIALOG_H

#include <QDialog>

namespace Ui {
        class dlgConsignment;
}

class CreateConsignmentDialog : public QDialog {
public:
        /// Конструктор
        explicit        CreateConsignmentDialog(QWidget* parent = nullptr);
        /// Виртуальный деструктор
                        ~CreateConsignmentDialog();

private:
        Ui::dlgConsignment*     m_ui;

        Q_OBJECT
};

#endif // CREATECONSIGNMENTDIALOG_H
