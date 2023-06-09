#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MainProductList.h"
#include "MainSoldList.h"

namespace Ui {
        class MainWindow;
}

class MainWindow : public QMainWindow {
public:
        /// Конструктор основного окна приложения
        explicit        MainWindow(QWidget *parent = 0);
        /// Виртуальный деструктор
                        ~MainWindow();

private:
        /// Создает основные таблицы
        void            createMainViews();
        /// Устанавливает горячие клавиши
        void            createShortcuts();
        /// Соединяет виджеты
        void            connectWidgets();

private slots:
        /// Обработка пунктов "База данных"
        void            processClientsAction();
        void            processSearchSoldAction();

        /// Обработка пунктов о ценниках
        void            processGeneratePricetagsAction();
        void            processClearPricetagsAction();

        /// Обработка пунктов "Анализ"
        void            processGeneralStatisticsAction();
        void            processSalesPlotAction();

        /// Открывает диалог SearchBarcodeDialog
        void            openSearchBarcodeDialog();

private:
        Ui::MainWindow*         m_ui;
        MainProductList*        m_mainProductList;
        MainSoldList*           m_mainSoldList;

        Q_OBJECT
};

#endif // MAINWINDOW_H
