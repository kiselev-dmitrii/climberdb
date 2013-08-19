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
        Ui::SearchBarcodeDialog*        m_ui;
        Q_OBJECT
};

#endif // SEARCHBARCODEDIALOG_H
