#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ProductsView.h"
#include "ProductFilter.h"

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
        Ui::MainWindow* m_ui;
        ProductsView*   m_productsView;         //Qt автоматические чистит память обходя дерево виджетов
        ProductFilter*  m_productsFilter;


        Q_OBJECT
};

#endif // MAINWINDOW_H
