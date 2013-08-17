#include "PricetagDialog.h"
#include "ui_PricetagDialog.h"
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>

PricetagDialog::PricetagDialog(QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::PricetagDialog)
{
        m_ui->setupUi(this);
        loadPricetagsTable();
        updateCountOfPages();
        onRemoveTag();
        connectWidgets();
}

PricetagDialog::~PricetagDialog() {
        delete m_ui;
}

void PricetagDialog::loadPricetagsTable() {
        QTableWidget* table = m_ui->twTags;
        QVector<TagInfo> tags = PricetagGenerator::instance()->tags();
        table->setColumnCount(3);
        table->setRowCount(tags.size());

        table->setHorizontalHeaderLabels({"Наименование", "Модель", "Размер"});

        for (int i = 0; i < tags.size(); ++i) {
                table->setItem(i, 0, new QTableWidgetItem(tags[i].name));
                table->setItem(i, 1, new QTableWidgetItem(tags[i].model));
                table->setItem(i, 2, new QTableWidgetItem(tags[i].size));
        }
}

void PricetagDialog::connectWidgets() {
        // Кнопка очистки
        connect(m_ui->btnClearTags, SIGNAL(clicked()), SLOT(clearTags()));

        // Кнопка удаления
        connect(m_ui->btnRemoveTag, SIGNAL(clicked()), SLOT(deleteSelectedTag()));

        // Кнопка Ok
        connect(m_ui->btnBox, SIGNAL(accepted()), SLOT(generateTags()));
}

void PricetagDialog::clearTags() {
        m_ui->twTags->setRowCount(0);
        PricetagGenerator::instance()->clearTags();
        m_ui->lblCountOfPages->setText("0");

        onRemoveTag();
}

void PricetagDialog::updateCountOfPages() {
        m_ui->lblCountOfPages->setText(QString::number(m_ui->twTags->rowCount()));
}

void PricetagDialog::deleteSelectedTag() {
        int selected = m_ui->twTags->currentIndex().row();
        if (selected >= 0) {
                PricetagGenerator::instance()->removeTag(selected);
                m_ui->twTags->removeRow(selected);
                updateCountOfPages();

                onRemoveTag();
        }
}

void PricetagDialog::generateTags() {
        PricetagGenerator::instance()->generateTags();
        QString path = PricetagGenerator::instance()->pathToTags();
        QDesktopServices::openUrl(QUrl(path));
}

void PricetagDialog::onRemoveTag() {
        if (m_ui->twTags->rowCount() > 0) m_ui->btnBox->button(QDialogButtonBox::Ok)->setEnabled(true);
        else m_ui->btnBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}
