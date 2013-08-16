#include "PricetagGenerator.h"
#include "Database.h"
#include <QFile>
#include <QDir>
#include <cmath>
#include <QDebug>

PricetagGenerator::PricetagGenerator() :
        m_tagsPerPage(16),
        m_countCols(4),
        m_templateDirectory("tagTemplate"),
        m_generatedDirectory("generatedTags"),
        m_logoFilename("logo.jpg"),
        m_templateFilename("template.html"),
        m_headerFlename("header.html"),
        m_tagsFilename("tags.html")
{
}

PricetagGenerator* PricetagGenerator::instance() {
        static PricetagGenerator instance;
        return  &instance;
}

int PricetagGenerator::tagsPerPage() {
        return m_tagsPerPage;
}

void PricetagGenerator::addNewProduct(int productID) {
        Product product = Database::instance()->getProductByID(productID);
        Consignment consignment = Database::instance()->getConsignmentByID(product.consignmentID);
        QStringList sizeList = Database::instance()->getSizeListFromConsignment(product.consignmentID);

        TagInfo tag;
        tag.name = consignment.name;
        tag.model = consignment.model;
        tag.size = product.size;
        tag.sizes = sizeList;
        tag.cost = consignment.cost;
        tag.barcode = product.barcode;

        m_tags.append(tag);
}

void PricetagGenerator::addNewConsignment(int consignmentID) {
        QVector<Product> products = Database::instance()->getProductListFromConsignment(consignmentID);
        Consignment consignment = Database::instance()->getConsignmentByID(consignmentID);
        QStringList sizeList = Database::instance()->getSizeListFromConsignment(consignmentID);

        for (Product &product: products) {
                TagInfo tag;
                tag.name = consignment.name;
                tag.model = consignment.model;
                tag.size = product.size;
                tag.sizes = sizeList;
                tag.cost = consignment.cost;
                tag.barcode = product.barcode;

                m_tags.append(tag);
        }
}

int PricetagGenerator::countOfTags() {
        return m_tags.size();
}

int PricetagGenerator::countOfPages() {
        return ceil(float(countOfTags())/16);
}

int PricetagGenerator::restOfTags() {
        return countOfPages()*16 - countOfTags();
}

bool PricetagGenerator::generateTags() {
        // Если директории с шаблоном нет, то ругаемся
        if (!QFile::exists(m_templateDirectory)) {
                qDebug() << "Directory " << m_templateDirectory << " not exist";
                return false;
        }

        // Создаем директорию в которой будет ценник и копируем туда лого
        if (!QFile::exists(m_generatedDirectory)) QDir(".").mkdir(m_generatedDirectory);
        QFile::copy(QDir(m_generatedDirectory).filePath(m_logoFilename), QDir(m_templateDirectory).filePath(m_logoFilename));

        // Открываем header
        QString header;
        QFile headerFile(QDir(m_templateDirectory).filePath(m_headerFlename));
        if (!headerFile.open(QIODevice::ReadOnly)) {
                qDebug() << "File " + m_headerFlename + " not exist";
                return false;
        }
        header = headerFile.readAll();
        headerFile.close();

        // Открываем шаблон
        QString tagTemplate;
        QFile templateFile(QDir(m_templateDirectory).filePath(m_templateFilename));
        if (!templateFile.open(QIODevice::ReadOnly)) {
                qDebug() << "File " + m_templateFilename + " not exist";
                return false;
        }
        tagTemplate = templateFile.readAll();
        templateFile.close();

        // Генерируем html-код ценников
        QString html = generateHtml(header, tagTemplate);

        // Записываем html код в файл
        QFile tags(QDir(m_generatedDirectory).filePath(m_tagsFilename));
        if (!tags.open(QIODevice::WriteOnly)) {
                qDebug() << "File " + m_tagsFilename + " cannot be created";
                return false;
        }
        tags.write(html.toUtf8());
        tags.close();

        return true;
}

QString PricetagGenerator::generateHtml(const QString& header, const QString& tagTemplate) {
        QString html = "<!DOCTYPE HTML>\n<html>\n" + header;
        html += "<body>";

        // Генерируем таблицы
        html += "<table>";
        html += "<tr>";
        for (int i = 0; i < m_tags.size(); ++i) {
                QString curTemplate = tagTemplate;
                curTemplate.replace("$name", m_tags[i].name);
                curTemplate.replace("$model", m_tags[i].model);
                curTemplate.replace("$size", m_tags[i].size);
                curTemplate.replace("$sizes", m_tags[i].sizes.join(", "));
                curTemplate.replace("$cost", QString::number(m_tags[i].cost));
                curTemplate.replace("$barcode", m_tags[i].barcode);

                html += "<td>\n" + curTemplate + "</td>\n";
                if ((i+1) % m_countCols == 0) html += "<tr></tr>";
        }
        html += "</tr>";
        html += "</table>";
        html += "</body>";

        return html;
}
