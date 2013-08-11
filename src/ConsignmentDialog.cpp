#include "ConsignmentDialog.h"
#include "ui_ConsignmentDialog.h"
#include "Database.h"

ConsignmentDialog::ConsignmentDialog(int consignmentID, QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::dlgConsignment),
        m_consignmentID(consignmentID),
        m_currentProducts(nullptr)
{
        m_ui->setupUi(this);
        connectWidgets();
        loadData();

}

ConsignmentDialog::~ConsignmentDialog() {
        delete m_ui;
}

void ConsignmentDialog::loadData() {
        m_currentConsignment = Database::instance()->getConsignmentByID(m_consignmentID);
        m_currentProducts = Database::instance()->getDialogSizesModel(m_consignmentID);

        // Загружаем списки для combobox
        m_ui->cbType->addItems(Database::instance()->getAvailableTypes());
        m_ui->cbColor->addItems(Database::instance()->getAvailableColors());
        m_ui->cbCountry->addItems(Database::instance()->getAvailableCountries());

        // Устанавливаем текущее состояние партии
        m_ui->edtName->setText(m_currentConsignment.name);
        m_ui->edtModel->setText(m_currentConsignment.model);
        m_ui->spnCost->setValue(m_currentConsignment.cost);
        m_ui->cbColor->setCurrentIndex(m_ui->cbColor->findText(m_currentConsignment.color));
        m_ui->cbType->setCurrentIndex(m_ui->cbType->findText(m_currentConsignment.type));

        if (m_currentConsignment.gender == "Муж.") m_ui->rbtnMale->setChecked(true);
        else if (m_currentConsignment.gender == "Жен.") m_ui->rbtnFemale->setChecked(true);
        else m_ui->rbtnUnknown->setChecked(true);

        m_ui->edtComment->setText(m_currentConsignment.comment);
        m_ui->cbCountry->setCurrentIndex(m_ui->cbCountry->findText(m_currentConsignment.country));

        // Устанавливаем доступные размеры
        m_ui->tvProducts->setModel(m_currentProducts);
        m_ui->tvProducts->resizeColumnsToContents();
}

void ConsignmentDialog::updateConsignment() {
        m_currentConsignment.name = m_ui->edtName->text();
        m_currentConsignment.model = m_ui->edtModel->text();
        m_currentConsignment.color = m_ui->cbColor->currentText();
        m_currentConsignment.type = m_ui->cbType->currentText();

        if (m_ui->rbtnMale->isChecked()) m_currentConsignment.gender = "Муж.";
        else if (m_ui->rbtnFemale->isChecked()) m_currentConsignment.gender = "Жен.";
        else if (m_ui->rbtnUnknown->isChecked()) m_currentConsignment.gender = "";

        m_currentConsignment.comment = m_ui->edtComment->text();
        m_currentConsignment.cost = m_ui->spnCost->value();
        m_currentConsignment.country = m_ui->cbCountry->currentText();

        Database::instance()->updateConsignment(m_consignmentID, m_currentConsignment);
}

void ConsignmentDialog::connectWidgets() {
        connect(m_ui->btnBox, SIGNAL(accepted()), this, SLOT(accept()));
        connect(m_ui->btnBox, SIGNAL(accepted()), this, SLOT(updateConsignment()));

        connect(m_ui->btnBox, SIGNAL(rejected()), this, SLOT(reject()));
}
