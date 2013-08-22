#include "SalesPlotDialog.h"
#include "ui_SalesPlotDialog.h"
#include <QDebug>
#include <QGraphicsTextItem>

SalesPlotDialog::SalesPlotDialog(QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::SalesPlotDialog),
        m_scene(nullptr),
        m_scale(10.0, 1.0)
{
        m_ui->setupUi(this);
        initDates();
        initGraphicsScene();
        connectWidgets();
}

SalesPlotDialog::~SalesPlotDialog() {
        delete m_ui;
}

void SalesPlotDialog::initDates() {
        m_ui->deTo->setDate(QDate::currentDate());
        m_ui->deFrom->setDate(QDate::currentDate().addMonths(-3));
}

void SalesPlotDialog::initGraphicsScene() {
        QGraphicsView* view = m_ui->gvPlot;
        m_scene = new QGraphicsScene(view);
        view->setScene(m_scene);

}

void SalesPlotDialog::connectWidgets() {
        // При нажатии на кнопку построения графика
        connect(m_ui->btnPlot, SIGNAL(clicked()), SLOT(onPlotButton()));

        // При нажатии на чекбоксы нужно обновлять картинку
        connect(m_ui->chbSales, SIGNAL(toggled(bool)), SLOT(drawPlots()));
        connect(m_ui->chbDeliveries, SIGNAL(toggled(bool)), SLOT(drawPlots()));
        connect(m_ui->btnShowSums, SIGNAL(toggled(bool)), SLOT(drawPlots()));

}

void SalesPlotDialog::drawAxis(int blackInterval, int redInterval) {
        // Рисуем прямую
        QDate from = m_ui->deFrom->date();
        QDate to = m_ui->deTo->date();
        int days = to.toJulianDay() - from.toJulianDay();
        m_scene->addLine(0, 0, days*m_scale.x(), 0, QPen(Qt::DotLine));

        // Рисуем черные отметки каждый blackInterval дней
        for (int i = 0; i < days; i += blackInterval) {
                m_scene->addLine(i*m_scale.x(), -2, i*m_scale.x(), 2);
        }

        // Рисуем красные отметки каждые redInterval дней
        for (int i = 0; i < days; i+=redInterval) {
                m_scene->addLine(i*m_scale.x(), 0, i*m_scale.x(), 4, QPen(Qt::red));

                QGraphicsTextItem* text = new QGraphicsTextItem();
                text->setPos(i*m_scale.x() - 35, 2);
                text->setPlainText(from.addDays(i).toString("dd.MM.yyyy"));
                m_scene->addItem(text);
        }
}

void SalesPlotDialog::loadData() {
        QDate from = m_ui->deFrom->date();
        QDate to = m_ui->deTo->date();

        /// Грузим данные из БД
        m_salesCounts = Database::instance()->getCountsOfSales(from, to);
        m_salesSums = Database::instance()->getSumsOfSales(from, to);
        m_deliveriesCounts = Database::instance()->getCountsOfDeliveries(from, to);
        m_deliveriesSums = Database::instance()->getSumsOfDeliveries(from, to);

        /// Правим относительный индекс, так чтобы он шел с 0
        int offset;
        offset = m_salesCounts[0].relativeIndex;
        for (PointInfo &point: m_salesCounts) point.relativeIndex -= offset;

        offset = m_salesSums[0].relativeIndex;
        for (PointInfo &point: m_salesSums) point.relativeIndex -= offset;

        offset = m_deliveriesCounts[0].relativeIndex;
        for (PointInfo &point: m_deliveriesCounts) point.relativeIndex -= offset;

        offset = m_deliveriesSums[0].relativeIndex;
        for (PointInfo &point: m_deliveriesSums) point.relativeIndex -= offset;
}

void SalesPlotDialog::drawData(const QVector<PointInfo>& data, const QPen& pen, int valueThreshold) {
        QDate from = m_ui->deFrom->date();
        QDate to = m_ui->deTo->date();
        int countDays = to.toJulianDay() - from.toJulianDay();

        PointInfo cur, next;
        next = data[0];
        for (int i=0, j=0; i<countDays; ++i) {
                cur = next;

                if ((j+1 < data.size()) && (data[j+1].relativeIndex == cur.relativeIndex + 1)) {
                        next = data[j+1];
                        ++j;
                } else {
                        next.relativeIndex = cur.relativeIndex + 1;
                        next.date = cur.date.addDays(1);
                        next.value = 0;
                }

                m_scene->addLine(cur.relativeIndex*m_scale.x(), -cur.value*m_scale.y(),
                                 next.relativeIndex*m_scale.x(), -next.value*m_scale.y(), pen);

                if (cur.value > valueThreshold) {
                        QGraphicsTextItem* text = new QGraphicsTextItem();
                        text->setPos(cur.relativeIndex*m_scale.x() - 10, -cur.value*m_scale.y() - 20);
                        text->setPlainText(QString::number(cur.value));
                        text->setDefaultTextColor(pen.color());
                        m_scene->addItem(text);
                }
        }
}

void SalesPlotDialog::onPlotButton() {
        loadData();
        drawPlots();
}

void SalesPlotDialog::drawPlots() {
        if (m_salesCounts.size() == 0 || m_salesSums.size() == 0) return;
        if (m_deliveriesCounts.size() == 0 || m_deliveriesSums.size() == 0) return;

        m_scene->clear();
        m_ui->gvPlot->update();
        drawAxis(1, 7);

        if (m_ui->btnShowSums->isChecked()) {
                m_scale = QVector2D(10.0, 0.001);
                if (m_ui->chbSales->isChecked()) drawData(m_salesSums, QPen(Qt::darkBlue), 8000);
                if (m_ui->chbDeliveries->isChecked()) drawData(m_deliveriesSums, QPen(Qt::darkGreen), 10000);
        } else {
                m_scale = QVector2D(10.0, 1.0);
                if (m_ui->chbSales->isChecked()) drawData(m_salesCounts, QPen(Qt::darkBlue), 4);
                if (m_ui->chbDeliveries->isChecked()) drawData(m_deliveriesCounts, QPen(Qt::darkGreen), 10);
        }
}
