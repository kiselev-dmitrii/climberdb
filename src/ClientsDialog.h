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
        /// Загружает таблицу данными
        void            loadClientsData();
        /// Соединяет сигналы и слоты
        void            connectWidgets();
        /// Обновляет верхнюю панель
        void            refreshAddingPanel(int row);

        /// Возвращает выделенный ClientID
        int             selectedClientID();

private slots:
        /// Добавляет клиента в таблицу
        void            addNewClient();
        /// Изменяет данные выбранного клиента
        void            changeClientData();
        /// Вызывается при выборе клиента
        void            onSelectClient(const QModelIndex& newIndex, const QModelIndex& oldIndex);

private:
        Ui::ClientsDialog*      m_ui;
        Q_OBJECT
};

#endif // CLIENTSDIALOG_H
