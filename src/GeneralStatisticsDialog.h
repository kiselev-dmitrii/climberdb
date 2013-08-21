#ifndef GENERALSTATISTICSDIALOG_H
#define GENERALSTATISTICSDIALOG_H

#include <QDialog>

namespace Ui {
        class GeneralStatisticsDialog;
}

/** Диалоговое окно, отображающее обшую статистику
 */
class GeneralStatisticsDialog : public QDialog {
public:
        /// Конструктор
        explicit        GeneralStatisticsDialog(QWidget *parent = nullptr);
        /// Виртуальный деструктор
                        ~GeneralStatisticsDialog();

private:
        /// Соединяет виджеты
        void            connectWidgets();

private slots:
        /// Получение статистики по заданному фильтру и промежутку
        void            onGetStatisticsButton();
        
private:
        Ui::GeneralStatisticsDialog*    m_ui;
        Q_OBJECT
};

#endif // GENERALSTATISTICSDIALOG_H
