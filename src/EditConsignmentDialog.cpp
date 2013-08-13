#include "EditConsignmentDialog.h"
#include "ui_EditConsignmentDialog.h"
#include "Database.h"
#include <QContextMenuEvent>
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>
#include <QDateEdit>

EditConsignmentDialog::EditConsignmentDialog(int consignmentID, QWidget *parent) :
        QDialog(parent),
        m_ui(new Ui::dlgEditConsignment),
        m_consignmentID(consignmentID),
        m_currentProducts(nullptr),
        m_contextMenu(nullptr)
{
        m_ui->setupUi(this);
        loadItemsForComboboxes();
        loadConsignmentData();
        loadProductsData();
        createContextMenu();
        connectWidgets();
}

EditConsignmentDialog::~EditConsignmentDialog() {
        delete m_ui;
}

void EditConsignmentDialog::loadItemsForComboboxes() {
        m_ui->cbType->addItems(Database::instance()->getAvailableTypes());
        m_ui->cbColor->addItems(Database::instance()->getAvailableColors());
        m_ui->cbCountry->addItems(Database::instance()->getAvailableCountries());
}

void EditConsignmentDialog::loadConsignmentData() {
        m_currentConsignment = Database::instance()->getConsignmentByID(m_consignmentID);

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
}

void EditConsignmentDialog::loadProductsData() {
        m_currentProducts = Database::instance()->refreshDialogSizesModel(m_consignmentID);

        m_ui->tvProducts->setModel(m_currentProducts);
        m_ui->tvProducts->resizeColumnsToContents();
        m_ui->tvProducts->horizontalHeader()->hideSection(0);
}

void EditConsignmentDialog::createContextMenu() {
        m_contextMenu = new QMenu(this);
        m_contextMenu->addAction("Редактировать дату добавления");
        m_contextMenu->addAction("Редактировать размер");
        m_contextMenu->addSeparator();
        m_contextMenu->addAction("Удалить");
}

void EditConsignmentDialog::connectWidgets() {
        /// Кнопки Ok, Cancel
        connect(m_ui->btnBox, SIGNAL(accepted()), this, SLOT(accept()));
        connect(m_ui->btnBox, SIGNAL(accepted()), this, SLOT(saveConsignmentData()));
        connect(m_ui->btnBox, SIGNAL(rejected()), this, SLOT(reject()));

        // Кнопка добавления и меню
        connect(m_ui->btnAddNewSizes, SIGNAL(clicked()), this, SLOT(addNewProducts()));
        connect(m_contextMenu, SIGNAL(triggered(QAction*)), SLOT(processMenuActions(QAction*)));
}

void EditConsignmentDialog::saveConsignmentData() {
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

void EditConsignmentDialog::addNewProducts() {
        if (m_ui->edtAddNewSizes->text().size() != 0) {
                QStringList sizes = m_ui->edtAddNewSizes->text().split(",");
                for (QString &size: sizes) size = size.trimmed();

                Database::instance()->addNewProducts(m_consignmentID, sizes);
                m_ui->edtAddNewSizes->clear();
                Database::instance()->refreshDialogSizesModel();
                Database::instance()->refreshMainProductsModel();
        }
}

void EditConsignmentDialog::processMenuActions(QAction *action) {
        // Получаем текущий размер, ID, дату добавления
        QModelIndex index = m_ui->tvProducts->currentIndex();
        index = m_ui->tvProducts->model()->index(index.row(), 0);
        int productID = m_ui->tvProducts->model()->data(index).toInt();
        index = m_ui->tvProducts->model()->index(index.row(), 1);
        QString oldSize =  m_ui->tvProducts->model()->data(index).toString();
        index = m_ui->tvProducts->model()->index(index.row(), 2);
        QDateTime oldDeliveryDate =  m_ui->tvProducts->model()->data(index).toDateTime();

        if (action->text() == "Редактировать дату добавления") processEditDateAction(productID, oldDeliveryDate);
        else if (action->text() == "Редактировать размер") processEditSizeAction(productID, oldSize);
        else if (action->text() == "Удалить") processRemoveSizeAction(productID);
}

void EditConsignmentDialog::processEditSizeAction(int productID, const QString& oldSize) {
        bool ok;
        QString newSize = QInputDialog::getText(this, "Редактирование размера", "Введите новый размер\n Изменение размера не влечет к изменению штрихкода", QLineEdit::Normal, oldSize, &ok);
        if (ok) {
                Database::instance()->editProductSize(productID, newSize);
                Database::instance()->refreshDialogSizesModel();
                Database::instance()->refreshMainProductsModel();
        }
}

void EditConsignmentDialog::processEditDateAction(int productID, const QDateTime& oldDate) {
        qDebug() << "TODO THIS";
}

void EditConsignmentDialog::processRemoveSizeAction(int productID) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Удаление размера");
        msgBox.setText("Удалить размер?");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        if(msgBox.exec() == QMessageBox::Ok) {
                Database::instance()->removeProduct(productID);
                Database::instance()->refreshDialogSizesModel();
                Database::instance()->refreshMainProductsModel();
        }
}

void EditConsignmentDialog::contextMenuEvent(QContextMenuEvent *ev) {
        Q_ASSERT(m_contextMenu != nullptr);
        m_contextMenu->exec(ev->globalPos());
}
