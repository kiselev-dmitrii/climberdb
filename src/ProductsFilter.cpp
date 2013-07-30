#include "ProductsFilter.h"
#include <QHeaderView>
#include <QLineEdit>
#include <QShortcut>
#include <QKeyEvent>

ProductsFilter::ProductsFilter(const QVector<int>& fieldsWidth, QWidget *parent) : QTableWidget(parent) {
        createWidgets(fieldsWidth);
        initUiSettings();
        setShortcuts();

        //Инициализируем массив сдвигов
        m_offsetSize.fill(0, fieldsWidth.size());
}

void ProductsFilter::createWidgets(const QVector<int> &fieldsWidth) {
        //Создаем таблицу и виджеты в нем
        this->insertRow(0);
        for (int i = 0; i < fieldsWidth.size(); ++i) {
                this->insertColumn(i);
                this->setColumnWidth(i, fieldsWidth[i]);
                this->setCellWidget(0,i, new QLineEdit(this));
        }
}

void ProductsFilter::initUiSettings() {
        //Убираем скролбар и хедеры
        this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        this->horizontalHeader()->hide();
        this->verticalHeader()->hide();

        //Высота строки по высоте виджета в нем
        this->setRowHeight(0, this->cellWidget(0,0)->height());
        this->setFixedHeight(this->rowHeight(0)+1);

        //Растягиваем таблицу
        this->horizontalHeader()->setStretchLastSection(true);
}

void ProductsFilter::setShortcuts() {
        QString mod = "Alt";
        for (int i = 0; i < columnCount(); ++i) {
                QShortcut* shortcut = new QShortcut(QKeySequence(mod+"+"+QString::number(i+1)), this);
                qDebug() << shortcut->key().toString();
                auto slot = std::bind(&ProductsFilter::setFocusOnField, this, i);
                connect(shortcut, &QShortcut::activated , slot);

        }

}

void ProductsFilter::keyPressEvent(QKeyEvent *event) {
        if (event->key() == Qt::Key_Return) emit enterPressed();
        if (event->key() == Qt::Key_Escape) emit escapePressed();
}

void ProductsFilter::setColumnOffset(int index, int offset) {
        m_offsetSize[index] = offset;
        this->setColumnWidth(index, this->columnWidth(index) + offset);
}

QString ProductsFilter::columnText(int index) {
        QLineEdit* edit = (QLineEdit*) (this->cellWidget(0, index));
        return edit->text();
}

void ProductsFilter::setFocusOnField(int index) {
        this->cellWidget(0, index)->setFocus();
}

void ProductsFilter::columnResize(int index, int oldWidth, int newWidth) {
        newWidth += m_offsetSize[index];
        this->setColumnWidth(index, newWidth);
}
