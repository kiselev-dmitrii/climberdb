/****************************************************************************
** Meta object code from reading C++ file 'ProductsFilter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/ProductsFilter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ProductsFilter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ProductsFilter_t {
    QByteArrayData data[9];
    char stringdata[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ProductsFilter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ProductsFilter_t qt_meta_stringdata_ProductsFilter = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 12),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 13),
QT_MOC_LITERAL(4, 43, 15),
QT_MOC_LITERAL(5, 59, 5),
QT_MOC_LITERAL(6, 65, 12),
QT_MOC_LITERAL(7, 78, 8),
QT_MOC_LITERAL(8, 87, 8)
    },
    "ProductsFilter\0enterPressed\0\0escapePressed\0"
    "setFocusOnField\0index\0columnResize\0"
    "oldWidth\0newWidth\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProductsFilter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x05,
       3,    0,   35,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    1,   36,    2, 0x0a,
       6,    3,   39,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    7,    8,

       0        // eod
};

void ProductsFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProductsFilter *_t = static_cast<ProductsFilter *>(_o);
        switch (_id) {
        case 0: _t->enterPressed(); break;
        case 1: _t->escapePressed(); break;
        case 2: _t->setFocusOnField((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->columnResize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ProductsFilter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProductsFilter::enterPressed)) {
                *result = 0;
            }
        }
        {
            typedef void (ProductsFilter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProductsFilter::escapePressed)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ProductsFilter::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_ProductsFilter.data,
      qt_meta_data_ProductsFilter,  qt_static_metacall, 0, 0}
};


const QMetaObject *ProductsFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProductsFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProductsFilter.stringdata))
        return static_cast<void*>(const_cast< ProductsFilter*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int ProductsFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ProductsFilter::enterPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ProductsFilter::escapePressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
