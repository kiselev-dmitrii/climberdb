#ifndef SALESPLOTDIALOG_H
#define SALESPLOTDIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <QVector2D>
#include "Database.h"

namespace Ui {
        class SalesPlotDialog;
}

/** Класс, представляющий собой диалог для отображения
 *  динамики продаж и получения товаров
 */
class SalesPlotDialog : public QDialog {
public:
        /// Конструктор
        explicit        SalesPlotDialog(QWidget *parent = nullptr);
        /// Виртуальный деструктор
                        ~SalesPlotDialog();

private:
        /// Инициализирует дату
        void            initDates();
        /// Инициализирует график
        void            initGraphicsScene();
        /// Соединяет виджеты
        void            connectWidgets();

        /// Рисует ось X по дате
        void            drawAxis(int blackInterval, int redInterval);
        /// Загружает данные для графиков
        void            loadData();
        /// Отрисовывает график
        void            drawData(const QVector<PointInfo>& data, const QPen& pen, int valueThreshold);

private slots:
        /// Вызывается при нажатии на кнопку btnPlot
        void            onPlotButton();
        /// Рисует графики
        void            drawPlots();
        
private:
        Ui::SalesPlotDialog*    m_ui;
        QGraphicsScene*         m_scene;
        QVector<PointInfo>      m_salesCounts;
        QVector<PointInfo>      m_salesSums;
        QVector<PointInfo>      m_deliveriesCounts;
        QVector<PointInfo>      m_deliveriesSums;

        QVector2D               m_scale;

        Q_OBJECT
};

#endif // SALESPLOTDIALOG_H
