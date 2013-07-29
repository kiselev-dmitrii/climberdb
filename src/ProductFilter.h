#ifndef PRODUCTFILTER_H
#define PRODUCTFILTER_H
#include <QTableWidget>
#include <QDebug>

class ProductFilter : public QTableWidget {
public:
        ProductFilter(const QVector<int>& fieldsWidth, QWidget* parent = nullptr);

public slots:
        void    columnResize(int index, int oldWidth, int newWidth) {
                qDebug() << " " << oldWidth << " " << newWidth << " " << index;
                if (index==0) newWidth += 40;
                this->setColumnWidth(index, newWidth);
        }

private:
        Q_OBJECT
};

#endif // PRODUCTFILTER_H
