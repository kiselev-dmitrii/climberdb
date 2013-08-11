#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QMap>

namespace Utils {

/// Добавляет в словарь barcodes (size->barcode) новые штрихкоды для новых размеров.
void    generateBarcodes(QMap<QString, QString>& barcodes, int consignmentID, const QStringList& newSizes);

} //namespace Utils

#endif // UTILS_H
