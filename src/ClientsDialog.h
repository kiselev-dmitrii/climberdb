#ifndef CLIENTSDIALOG_H
#define CLIENTSDIALOG_H

#include <QDialog>

namespace Ui {
        class ClientsDialog;
}

class ClientsDialog : public QDialog {
public:
        /// Конструктор
        explicit        ClientsDialog(QWidget *parent = nullptr);
        /// Виртуальный дестуктор
                        ~ClientsDialog();
        
private:
        Ui::ClientsDialog*      m_ui;
        Q_OBJECT
};

#endif // CLIENTSDIALOG_H
