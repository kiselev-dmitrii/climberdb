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
        /// Создание таблицы
        void            createView();
        /// Создание информационной панели с отображением сумм проданных и выделенных товаров
        void            createInfoPanel();
        /// Создание панели с виджетами изменения даты
        void            createDatePanel();
        /// Обновляет сумму проданных товаров
        void            updateSumSoldProducts();
        /// Соединения виджетов
        void            connectWidgets();

private slots:
        /// Устанавливает текущую дату в date
        void            setTableDate(const QDate& date);
        /// Устанавливает предыдущую дату
        void            setNextDate();
        /// Устанавливает следующую дату
        void            setPrevDate();
        /// Устанавилвает сумму выделенных товаров
        void            setSumSelected();

private:
        SoldProductsView*       m_soldView;
        QHBoxLayout*            m_ltInfoPanel;
        QHBoxLayout*            m_ltDatePanel;

        QLineEdit*              m_edtSumSelected;
        QLineEdit*              m_edtSumSoldProducts;

        QDateEdit*              m_dateEdit;
        QPushButton*            m_prevBtn;
        QPushButton*            m_nextBtn;
        Q_OBJECT
};

#endif // MAINSOLDLIST_H
