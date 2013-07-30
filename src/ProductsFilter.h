#ifndef PRODUCTSFILTER_H
#define PRODUCTSFILTER_H
#include <QTableWidget>
#include <QDebug>

/** Фильтр, состоит из полей ввода.
 *  Предназначен для фильтрования записей в модели
 */
class ProductsFilter : public QTableWidget {
public:
        /// Конструктор
        explicit ProductsFilter(const QVector<int>& fieldsWidth, QWidget* parent = nullptr);

        /// Устанавливает смещение на колонку
        void    setColumnOffset(int index, int offset);

        /// Возвращает текст колонки
        QString columnText(int index);

public slots:
        /// Устанавливает фокус на поле ввода index
        void    setFocusOnField(int index);

        /// Изменяет размер колонки index с oldWidth на newWidth
        void    columnResize(int index, int oldWidth, int newWidth);

signals:
        void    enterPressed();
        void    escapePressed();

private:
        void    createWidgets(const QVector<int>& fieldsWidth);
        void    initUiSettings();
        void    setShortcuts();

private:
        void    keyPressEvent(QKeyEvent *event);

private:
        QVector<int>    m_offsetSize;   //смещения в размере колонок

        Q_OBJECT
};

#endif // PRODUCTSFILTER_H
