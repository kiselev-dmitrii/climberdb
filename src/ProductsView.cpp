#include "ProductsView.h"
#include "Database.h"
#include <QHeaderView>
#include <QMenu>
#include <QContextMenuEvent>
#include <QScrollBar>

ProductsView::ProductsView(QWidget *parent) :
        QTableView(parent),
        m_contextMenu(nullptr),
        m_model(nullptr)
{
        loadModel();
        applyUiSettings();
        createContextMenu();
}

ProductsView::~ProductsView() {
        saveUiSettings();
}

void ProductsView::loadModel() {
        m_model = Database::instance()->getAllProductsModel("","","",
                                                            "","","",
                                                            "","","");
        this->setModel(m_model);
}


void ProductsView::applyUiSettings() {
        applyCommonSettings();
        applyCellSettings();
        applyHeaderSettings();
        applyFontSettings();
}

void ProductsView::applyCommonSettings() {
        //Разворачиваем таблицу на всю view
        this->horizontalHeader()->setStretchLastSection(true);
        //Уюираем скрол, ширина вертикального хедера, выделяем строчками
        this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        this->verticalHeader()->setFixedWidth(40);
        this->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void ProductsView::applyHeaderSettings() {
        QHeaderView* header = this->horizontalHeader();

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

        QList<QVariant> columnsWidth;
        for (int i = 0; i < columnCount(); ++i) columnsWidth.append(header->sectionSize(i));
        m_settings.setValue("/ProductView/ColumnsWidth", columnsWidth);
}

void ProductsView::createContextMenu() {
        m_contextMenu = new QMenu(this);
        m_contextMenu->addAction("&Продать");
        m_contextMenu->addAction("Распечатать ценник");
        m_contextMenu->addSeparator();
        m_contextMenu->addAction("&Редактировать");
        m_contextMenu->addAction("Удалить");
}

void ProductsView::contextMenuEvent(QContextMenuEvent *ev) {
        m_contextMenu->exec(ev->globalPos());
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
       return this->horizontalHeader()->count();
}
