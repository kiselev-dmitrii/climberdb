#include "ProductFilter.h"
#include <QHeaderView>
#include <QLineEdit>

ProductFilter::ProductFilter(const QVector<int>& fieldsWidth, QWidget *parent) : QTableWidget(parent) {
        this->insertColumn(0);
        this->insertColumn(1);
        this->insertColumn(2);
        this->insertColumn(3);
        this->insertColumn(4);
        this->insertColumn(5);
        this->insertColumn(6);
        this->insertColumn(7);
        this->insertColumn(8);
        this->insertRow(0);

        this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        this->setRowHeight(0, 20);
        this->setFixedHeight(this->rowHeight(0)+1);
        this->horizontalHeader()->hide();
        this->verticalHeader()->hide();
        this->horizontalHeader()->setStretchLastSection(true);

        for (int i = 0; i < this->columnCount(); ++i) {
                this->setCellWidget(0,i, new QLineEdit());
                this->setColumnWidth(i, fieldsWidth[i]);
        }

}
