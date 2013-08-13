#ifndef EDITCONSIGNMENTDIALOG_H
#define EDITCONSIGNMENTDIALOG_H

#include <QDialog>
#include <QMenu>
#include "Database.h"

namespace Ui {
        class dlgEditConsignment;
}

class EditConsignmentDialog : public QDialog {
public:
        /// Конструктор диалога
        explicit                EditConsignmentDialog(int consignmentID, QWidget* parent = nullptr);
        /// Виртуальный деструктор
                                ~EditConsignmentDialog();

private:
        /// Загрузка содержимого комбобоксов
        void                    loadItemsForComboboxes();
        /// Загрузка данных в виджеты
        void                    loadConsignmentData();
        void                    loadProductsData();
        /// Создание контекстного меню
        void                    createContextMenu();
        /// Соединение виджетов
        void                    connectWidgets();

private:
        /// Собитие на нажатие правой кнопки мыши
        void                    contextMenuEvent(QContextMenuEvent *ev);
        /// Удаление размера
        void                    processRemoveSizeAction(int productID);
        /// Редактирование размера
        void                    processEditSizeAction(int productID, const QString& oldSize);
        /// Редактирование даты
        void                    processEditDateAction(int productID, const QDateTime& oldDate);

private slots:
        /// Выполняется при нажатии на Ok
        void                    saveConsignmentData();
        /// Обработка нажатия на кнопку btnAddNewSizes
        void                    addNewProducts();
        /// Обработка нажатий на пункты в меню
        void                    processMenuActions(QAction* action);

private:
        Ui::dlgEditConsignment* m_ui;

        int                     m_consignmentID;
        Consignment             m_currentConsignment;
        QSqlQueryModel*         m_currentProducts;
        QMenu*                  m_contextMenu;

        Q_OBJECT
};

#endif // EDITCONSIGNMENTDIALOG_H
