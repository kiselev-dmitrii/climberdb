#ifndef CONSIGNMENTDIALOG_H
#define CONSIGNMENTDIALOG_H

#include <QDialog>
#include <QMenu>
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
        /// Загрузка данных в виджеты
        void                    loadData();
        /// Соединение виджетов
        void                    connectWidgets();
        /// Создание контекстного меню
        void                    createContextMenu();
        /// Собитие на нажатие правой кнопки мыши
        void                    contextMenuEvent(QContextMenuEvent *ev);
        /// Удаление размера
        void                    processRemoveSizeAction(int productID);
        /// Редактирование размера
        void                    processEditSizeAction(int productID, const QString& oldSize);
        /// Редактирование даты
        void                    processEditDateAction(int productID, const QDateTime& oldDate);

private slots:
        void                    updateConsignment();
        void                    addNewSizes();
        void                    processMenuActions(QAction* action);

private:
        Ui::dlgConsignment*     m_ui;

        int                     m_consignmentID;
        Consignment             m_currentConsignment;
        QSqlQueryModel*         m_currentProducts;
        QMenu*                  m_contextMenu;

        Q_OBJECT
};

#endif // CONSIGNMENTDIALOG_H
