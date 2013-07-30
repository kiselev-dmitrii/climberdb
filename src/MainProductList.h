#ifndef MAINPRODUCTLIST_H
#define MAINPRODUCTLIST_H

#include <QVBoxLayout>
#include <ProductsView.h>
#include <ProductsFilter.h>

/** Список продуктов - таблица + фильтр, для поиска
 */
class MainProductList : public QVBoxLayout {
public:
        /// Конструктор
        MainProductList(QWidget* parent = nullptr);

private:
        void            createWidgets();
        void            connectWidgets();

private slots:
        void            applyFilter();

private:
        ProductsView*   m_productsView;
        ProductsFilter* m_productsFilter;
        Q_OBJECT
};

#endif // MAINPRODUCTLIST_H
