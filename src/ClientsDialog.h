#ifndef CLIENTSDIALOG_H
#define CLIENTSDIALOG_H

#include <QDialog>
#include <QMenu>

namespace Ui {
        class ClientsDialog;
}

class ClientsDialog : public QDialog {
public:
        /// Конструктор. Если clientID > 0, то запись с таким ID становится текущей при открытии
        explicit        ClientsDialog(QWidget *parent = nullptr, int clientID = -1);
        /// Виртуальный дестуктор
                        ~ClientsDialog();
        
private:
        /// Загружает таблицу данными
        void            loadClientsData();
        /// Создает контекстное меню
        void            createContextMenu();
        /// Соединяет сигналы и слоты
        void            connectWidgets();
        /// Выделяет заданного клиента по его ID
        void            setCurrentClient(int clientID);
        /// Обновляет верхнюю панель
        void            refreshAddingPanel(int row);

        /// Возвращает выделенный ClientID
        int             selectedClientID();
        /// Удаляет клиента по ClientID
        void            removeSelectedClient();

private:
        /// Событие, на нажатие правой кнопки мыши
        void            contextMenuEvent(QContextMenuEvent *event);

private slots:
        /// Добавляет клиента в таблицу
        void            addNewClient();
        /// Изменяет данные выбранного клиента
        void            changeClientData();
        /// Вызывается при выборе клиента
        void            onSelectClient(const QModelIndex& newIndex, const QModelIndex& oldIndex);
        /// Обработка нажатий на пункты меню
        void            processMenuActions(QAction* action);

private:
        Ui::ClientsDialog*      m_ui;
        QMenu*                  m_contextMenu;
        Q_OBJECT
};

#endif // CLIENTSDIALOG_H
