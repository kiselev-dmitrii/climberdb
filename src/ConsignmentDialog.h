#ifndef CONSIGNMENTDIALOG_H
#define CONSIGNMENTDIALOG_H

#include <QDialog>
#include "Database.h"

namespace Ui {
        class dlgConsignment;
}

class ConsignmentDialog : public QDialog {
public:
        /// Конструктор диалога
        explicit                ConsignmentDialog(int consignmentID, QWidget* parent = nullptr);
        /// Виртуальный деструктор
                                ~ConsignmentDialog();

private:
        void                    loadData();
        void                    connectWidgets();
        void                    refreshData();

private slots:
        void                    updateConsignment();
        void                    addNewSizes();

private:
        Ui::dlgConsignment*     m_ui;

        int                     m_consignmentID;
        Consignment             m_currentConsignment;
        QSqlQueryModel*         m_currentProducts;

        Q_OBJECT
};

#endif // CONSIGNMENTDIALOG_H
