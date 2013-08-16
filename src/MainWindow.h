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
        /// Соединяет виджеты
        void            connectWidgets();

private slots:
        /// Обработка пунктов о ценниках
        void            processGeneratePricetagsAction();
        void            processClearPricetagsAction();

private:
        Ui::MainWindow*         m_ui;
        MainProductList*        m_mainProductList;
        MainSoldList*           m_mainSoldList;

        Q_OBJECT
};

#endif // MAINWINDOW_H
