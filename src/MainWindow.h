#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MainProductList.h"

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
        Ui::MainWindow*         m_ui;
        MainProductList*        m_mainProductList;

        Q_OBJECT
};

#endif // MAINWINDOW_H
