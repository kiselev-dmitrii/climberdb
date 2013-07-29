#include "ProductsView.h"
#include "Database.h"
#include <QHeaderView>
#include <QMenu>
#include <QContextMenuEvent>
#include <QScrollBar>
#include <assert.h>

ProductsView::ProductsView(QWidget *parent) :
        QTableView(parent),
        m_contextMenu(nullptr)
{
        loadView();
        applyUiSettings();
        createContextMenu();
        this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        this->verticalHeader()->setFixedWidth(40);
}

ProductsView::~ProductsView() {
        saveUiSettings();
}

QVector<int> ProductsView::columnsWidth() {
        QHeaderView* header = this->horizontalHeader();
        QVector<int> columnsWidth;
        for (int i = 0; i < columnCount(); ++i) {
                auto size = header->sectionSize(i);
                if (size != 0) columnsWidth.append(header->sectionSize(i));
        }
        return columnsWidth;
}

int ProductsView::columnCount() {
        return m_model->columnCount();
}

void ProductsView::createContextMenu() {
        m_contextMenu = new QMenu(this);
        m_contextMenu->addAction("&Редактировать");
        m_contextMenu->addAction("&Продать");
        m_contextMenu->addAction("Распечатать ценник");
}

void ProductsView::applyUiSettings() {
        applyCellSettings();
        applyHeaderSettings();
        applyFontSettings();
}

void ProductsView::applyHeaderSettings() {
        QHeaderView* header = this->horizontalHeader();

        //Разворачиваем таблицу на всю view
        header->setStretchLastSection(true);

        //Устанавливаем ширину калонок из настроек
        QList<QVariant> defaultWidth = {100, 100, 100, 50, 100, 50, 100, 100, 100};
        QList<QVariant> columnsWidth = m_settings.value("/ProductView/ColumnsWidth", defaultWidth).toList();

        for (int i = 0; i < columnsWidth.size(); ++i) {
                if (columnsWidth[i] == 0) header->hideSection(i);
                else header->resizeSection(i, columnsWidth[i].toInt());
        }
}

void ProductsView::applyCellSettings() {
        int defaultHeight = 20;
        int cellHeight = m_settings.value("/Views/CellHeight", defaultHeight).toInt();

        this->setSelectionBehavior(QAbstractItemView::SelectRows);
        this->verticalHeader()->setDefaultSectionSize(cellHeight);
}

void ProductsView::applyFontSettings() {
        int defaultSize = 8;
        int fontSize = m_settings.value("/Views/FontSize", defaultSize).toInt();

        QFont font;
        font.setPointSize(fontSize);
        this->setFont(font);
}

void ProductsView::saveUiSettings() {
        QHeaderView* header = this->horizontalHeader();
        int countSections = 9;

        QList<QVariant> columnsWidth;
        for (int i = 0; i < countSections; ++i) columnsWidth.append(header->sectionSize(i));
        m_settings.setValue("/ProductView/ColumnsWidth", columnsWidth);
}

void ProductsView::loadView() {
        m_model = Database::instance()->getProductsViewModel();
        this->setModel(m_model);
}

void ProductsView::contextMenuEvent(QContextMenuEvent *ev) {
        m_contextMenu->exec(ev->globalPos());
        this->setModel(Database::instance()->getProductsViewModel());
}
