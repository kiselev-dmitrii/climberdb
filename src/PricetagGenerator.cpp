#include "PricetagGenerator.h"
#include "Database.h"
#include <cmath>

PricetagGenerator::PricetagGenerator() :
        m_tagsPerPage(16)
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
        QVector<QString> sizeList = Database::instance()->getSizeListFromConsignment(product.consignmentID);

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
        QVector<QString> sizeList = Database::instance()->getSizeListFromConsignment(consignmentID);

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
        countOfPages()*16 - countOfTags();
}
