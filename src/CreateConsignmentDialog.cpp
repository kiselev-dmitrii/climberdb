#include "CreateConsignmentDialog.h"
#include "ui_CreateConsignmentDialog.h"
#include "Database.h"
#include <QPushButton>

CreateConsignmentDialog::CreateConsignmentDialog(QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::dlgCreateConsignment)

{
        m_ui->setupUi(this);
        m_ui->btnBox->button(QDialogButtonBox::Ok)->setEnabled(false);

        loadItemsForComboboxes();
        connectWidgets();
}

CreateConsignmentDialog::~CreateConsignmentDialog() {
        delete m_ui;
}

void CreateConsignmentDialog::loadItemsForComboboxes() {
        m_ui->cbType->addItems(Database::instance()->getAvailableTypes());
        m_ui->cbColor->addItems(Database::instance()->getAvailableColors());
        m_ui->cbCountry->addItems(Database::instance()->getAvailableCountries());
}

void CreateConsignmentDialog::connectWidgets() {
        /// Кнопки Ok, Cancel
        connect(m_ui->btnBox, SIGNAL(accepted()), this, SLOT(accept()));
        connect(m_ui->btnBox, SIGNAL(rejected()), this, SLOT(reject()));
        connect(m_ui->btnBox, SIGNAL(accepted()), this, SLOT(saveData()));

        /// Проверка полей при изменении содержимого
        connect(m_ui->edtName, SIGNAL(textChanged(QString)), SLOT(validateFields()));
        connect(m_ui->edtModel, SIGNAL(textChanged(QString)), SLOT(validateFields()));
        connect(m_ui->edtAddNewSizes, SIGNAL(textChanged(QString)), SLOT(validateFields()));
        connect(m_ui->spnCost, SIGNAL(valueChanged(int)), SLOT(validateFields()));

}

int CreateConsignmentDialog::saveData() {
        int consignmentID = saveConsignmentData();
        saveProductsData(consignmentID);;

        Database::instance()->refreshMainProductsModel();

        return consignmentID;
}

int CreateConsignmentDialog::saveConsignmentData() {
        Consignment consignment;
        consignment.name = m_ui->edtName->text();
        consignment.model = m_ui->edtModel->text();
        consignment.color = m_ui->cbColor->currentText();
        consignment.type = m_ui->cbType->currentText();

        if (m_ui->rbtnMale->isChecked()) consignment.gender = "Муж.";
        else if (m_ui->rbtnFemale->isChecked()) consignment.gender = "Жен.";
        else if (m_ui->rbtnUnknown->isChecked()) consignment.gender = "";

        consignment.comment = m_ui->edtComment->text();
        consignment.cost = m_ui->spnCost->value();
        consignment.country = m_ui->cbCountry->currentText();

        return Database::instance()->addNewConsignment(consignment);
}

void CreateConsignmentDialog::saveProductsData(int consignmentID) {
        QStringList sizes = m_ui->edtAddNewSizes->text().split(",");
        for (QString &size: sizes) size = size.trimmed();

        Database::instance()->addNewProducts(consignmentID, sizes);
}

void CreateConsignmentDialog::validateFields() {
        if (m_ui->edtName->text().size() == 0 ||  m_ui->edtModel->text().size() == 0 ||
        m_ui->edtAddNewSizes->text().size() == 0 || m_ui->spnCost->value() == 0) {
                m_ui->btnBox->button(QDialogButtonBox::Ok)->setEnabled(false);
        } else {
                m_ui->btnBox->button(QDialogButtonBox::Ok)->setEnabled(true);
        }
}
