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
        m_tagsFilename("tags.html"),
        m_fontName("font")
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

void PricetagGenerator::clearTags() {
        m_tags.clear();
}

const QVector<TagInfo>& PricetagGenerator::tags() {
        return m_tags;
}

void PricetagGenerator::removeTag(int i) {
        m_tags.remove(i);
}

QString PricetagGenerator::pathToTags() {
        return QDir(m_generatedDirectory).filePath(m_tagsFilename);
}

bool PricetagGenerator::generateTags() {
        // Если директории с шаблоном нет, то ругаемся
        if (!QFile::exists(m_templateDirectory)) {
                qDebug() << "Directory " << m_templateDirectory << " not exist";
                return false;
        }

        // Создаем директорию в которой будет ценник
        if (!QFile::exists(m_generatedDirectory)) QDir(".").mkdir(m_generatedDirectory);
        // Копируем лого и шрифты
        QFile::copy(QDir(m_templateDirectory).filePath(m_logoFilename), QDir(m_generatedDirectory).filePath(m_logoFilename));
        QFile::copy(QDir(m_templateDirectory).filePath(m_fontName+".eot"), QDir(m_generatedDirectory).filePath(m_fontName+".eot"));
        QFile::copy(QDir(m_templateDirectory).filePath(m_fontName+".svg"), QDir(m_generatedDirectory).filePath(m_fontName+".svg"));
        QFile::copy(QDir(m_templateDirectory).filePath(m_fontName+".ttf"), QDir(m_generatedDirectory).filePath(m_fontName+".ttf"));
        QFile::copy(QDir(m_templateDirectory).filePath(m_fontName+".woff"), QDir(m_generatedDirectory).filePath(m_fontName+".woff"));

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
                curTemplate.replace("$name$", m_tags[i].name);
                curTemplate.replace("$model$", m_tags[i].model);
                curTemplate.replace("$size$", m_tags[i].size);
                curTemplate.replace("$sizes$", m_tags[i].sizes.join(", "));
                curTemplate.replace("$cost$", QString::number(m_tags[i].cost));
                curTemplate.replace("$barcode$", generateSymbolCode(m_tags[i].barcode));

                html += "<td>\n" + curTemplate + "</td>\n";
                if ((i+1) % m_countCols == 0) html += "<tr></tr>";
        }
        html += "</tr>";
        html += "</table>";
        html += "</body>";

        return html;
}

QString PricetagGenerator::generateSymbolCode(const QString &digits) {
        char codes[][10] = {
                  {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'},
                  {'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'},
                  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}
        };
        char usingTable[][6] = {
                  {0, 0, 0, 0, 0, 0}, //0
                  {0, 0, 1, 0, 1, 1}, //1
                  {0, 0, 1, 1, 0, 1}, //2
                  {0, 0, 1, 1, 1, 0}, //3
                  {0, 1, 0, 0, 1, 1}, //4
                  {0, 1, 1, 0, 0, 1}, //5
                  {0, 1, 1, 1, 0, 0}, //6
                  {0, 1, 0, 1, 0, 1}, //7
                  {0, 1, 0, 1, 1, 0}, //8
                  {0, 1, 1, 0, 1, 0}  //9
        };

        QString result;
        // Нулевой символ неизменный
        result += digits[0];

        // Символы с 1-6 берутся из codes[0] или codes[1], в зависимости от unsingTable[firstNumber][digits[i]]
        int firstNumber = QString(digits[0]).toInt();
        for (int i = 1; i <= 6; ++i) {
                int number = QString(digits[i]).toInt();
                int table = usingTable[firstNumber][i-1];
                result += codes[table][number];
        }

        result += "*";  //серединный символ

        // Символы 7-12 берутся из codes[2]
        for (int i = 7; i <= 12; ++i) {
                int number = QString(digits[i]).toInt();
                result += codes[2][number];
        }

        result += "+";  //конечный символ

        return result;
}
