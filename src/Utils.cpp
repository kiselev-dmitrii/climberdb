#include "Utils.h"
#include <cmath>
#include <QStringList>
#include <QDebug>
#include "Database.h"

int generateCheckDigit(const QString &significantDigits);

namespace Utils {

QMap<QString, QString> generateBarcodes(int consignmentID, const QStringList &newSizes) {
        // Для генерирования штрихкода нужен список всех предыдущих штрихкодов в партии
        auto products = Database::instance()->getProductListFromConsignment(consignmentID);
        QMap<QString, QString> barcodes;                                        // size -> barcode
        for (auto &product: products) barcodes[product.size] = product.barcode;

        // Вычисляем наибольший порядковый номер
        int max = 0;
        for (QString &barcode: barcodes.values()) {
                int current = barcode.mid(6, 6).toInt();
                if (current > max) max = current;
        }

        /// Генерируем новые коды для новых размеров
        int i = max + 1;
        for (QString size: newSizes) {
                if (barcodes.find(size) == barcodes.end()) {
                        QString firstPart = QString::number(consignmentID).rightJustified(6, '0');
                        QString secondPart = QString::number(i).rightJustified(6, '0');
                        int checkDigit = generateCheckDigit(firstPart + secondPart);
                        barcodes[size] = firstPart + secondPart + QString::number(checkDigit);
                        ++i;
                }
        }

        return barcodes;
}

} //namepsace Utils


int generateCheckDigit(const QString& significantDigits) {
        if (significantDigits.size() != 12) {
                qDebug() << significantDigits << " barcode has size not equal 12";
                return -1;
        }

        int sumEven = 0;
        for (int i = 1; i < significantDigits.size(); i += 2) sumEven += QString(significantDigits.at(i)).toInt();
        int sumOdd = 0;
        for (int i = 0; i < significantDigits.size(); i += 2) sumOdd += QString(significantDigits.at(i)).toInt();

        int result = 3*sumEven + sumOdd;
        result = int(ceil(double(result)/10)*10) - result;
        return result;
}
