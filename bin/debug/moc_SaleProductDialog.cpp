/****************************************************************************
** Meta object code from reading C++ file 'SaleProductDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/SaleProductDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SaleProductDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SaleProductDialog_t {
    QByteArrayData data[10];
    char stringdata[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SaleProductDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SaleProductDialog_t qt_meta_stringdata_SaleProductDialog = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 17),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 14),
QT_MOC_LITERAL(4, 52, 5),
QT_MOC_LITERAL(5, 58, 12),
QT_MOC_LITERAL(6, 71, 15),
QT_MOC_LITERAL(7, 87, 16),
QT_MOC_LITERAL(8, 104, 5),
QT_MOC_LITERAL(9, 110, 19)
    },
    "SaleProductDialog\0openClientsDialog\0"
    "\0onChangeClient\0index\0onChangeSize\0"
    "onDiscountClick\0onDiscountChange\0value\0"
    "onSellingCostChange\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SaleProductDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08,
       3,    1,   45,    2, 0x08,
       5,    1,   48,    2, 0x08,
       6,    0,   51,    2, 0x08,
       7,    1,   52,    2, 0x08,
       9,    1,   55,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void SaleProductDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SaleProductDialog *_t = static_cast<SaleProductDialog *>(_o);
        switch (_id) {
        case 0: _t->openClientsDialog(); break;
        case 1: _t->onChangeClient((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onChangeSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onDiscountClick(); break;
        case 4: _t->onDiscountChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onSellingCostChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SaleProductDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SaleProductDialog.data,
      qt_meta_data_SaleProductDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *SaleProductDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SaleProductDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SaleProductDialog.stringdata))
        return static_cast<void*>(const_cast< SaleProductDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SaleProductDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
