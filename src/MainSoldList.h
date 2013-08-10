#ifndef MAINSOLDLIST_H
#define MAINSOLDLIST_H

#include <QVBoxLayout>
#include <QPushButton>
#include <QDateEdit>
#include <QHBoxLayout>
#include "SoldProductsView.h"

/** Сипсок проданного товара.
 *  По умолчанию показывает список проданного за сегодня,
 *  но имеет элементы управления для изменения даты
 */
class MainSoldList : public QVBoxLayout {
public:
        /// Конструктор
        MainSoldList(QWidget* parent = nullptr);

private:
        void            createDatePanel();
        void            createView();
        void            connectWidgets();

private slots:
        void            setTableDate(const QDate& date);
        void            setNextDate();
        void            setPrevDate();

private:
        SoldProductsView*       m_soldView;
        QHBoxLayout*            m_panelLayout;
        QDateEdit*              m_dateEdit;
        QPushButton*            m_prevBtn;
        QPushButton*            m_nextBtn;
        Q_OBJECT
};

#endif // MAINSOLDLIST_H
