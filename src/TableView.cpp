#include "TableView.h"
#include <QHeaderView>
#include <QScrollBar>

TableView::TableView(QSqlQueryModel *model, const QString& settingsName, QWidget *parent) :
        QTableView(parent),
        m_settingsName(settingsName)
{
        this->setModel(model);
        applyUiSettings();
}

TableView::~TableView() {
        saveUiSettings();
}

void TableView::applyUiSettings() {
        applyCommonSettings();
        applyCellSettings();
        applyHeaderSettings();
        applyFontSettings();
}

void TableView::applyCommonSettings() {
        //Разворачиваем таблицу на всю view
        this->horizontalHeader()->setStretchLastSection(true);
        //Уюираем скрол, ширина вертикального хедера, выделяем строчками
        this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        this->verticalHeader()->setFixedWidth(40);
        this->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void TableView::applyHeaderSettings() {
        QHeaderView* header = this->horizontalHeader();

        //Устанавливаем ширину калонок из настроек (по дефолту колонки равны)
        QList<QVariant> defaultWidth;
        for (int i = 0; i < columnCount(); ++i) defaultWidth.append(width()/columnCount());

        QList<QVariant> columnsWidth = m_settings.value("/"+m_settingsName+"/ColumnsWidth", defaultWidth).toList();

        for (int i = 0; i < columnsWidth.size(); ++i) {
                header->resizeSection(i, columnsWidth[i].toInt());
        }
}

void TableView::applyCellSettings() {
        int defaultHeight = 20;
        int cellHeight = m_settings.value("/Views/CellHeight", defaultHeight).toInt();

        this->verticalHeader()->setDefaultSectionSize(cellHeight);
}

void TableView::applyFontSettings() {
        int defaultSize = 8;
        int fontSize = m_settings.value("/Views/FontSize", defaultSize).toInt();

        QFont font;
        font.setPointSize(fontSize);
        this->setFont(font);
}

void TableView::saveUiSettings() {
        QHeaderView* header = this->horizontalHeader();

        QList<QVariant> columnsWidth;
        for (int i = 0; i < columnCount(); ++i) columnsWidth.append(header->sectionSize(i));
        m_settings.setValue("/"+m_settingsName+"/ColumnsWidth", columnsWidth);
}

QVector<int> TableView::columnsWidth() {
        QHeaderView* header = this->horizontalHeader();
        QVector<int> columnsWidth;
        for (int i = 0; i < columnCount(); ++i) columnsWidth.append(header->sectionSize(i));
        return columnsWidth;
}

int TableView::columnCount() {
       return this->horizontalHeader()->count();
}
