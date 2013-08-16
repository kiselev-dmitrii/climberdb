/****************************************************************************
** Meta object code from reading C++ file 'ProductsView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/ProductsView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ProductsView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ProductsView_t {
    QByteArrayData data[11];
    char stringdata[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ProductsView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ProductsView_t qt_meta_stringdata_ProductsView = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 18),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 8),
QT_MOC_LITERAL(4, 42, 6),
QT_MOC_LITERAL(5, 49, 17),
QT_MOC_LITERAL(6, 67, 13),
QT_MOC_LITERAL(7, 81, 17),
QT_MOC_LITERAL(8, 99, 2),
QT_MOC_LITERAL(9, 102, 16),
QT_MOC_LITERAL(10, 119, 24)
    },
    "ProductsView\0processMenuActions\0\0"
    "QAction*\0action\0processSaleAction\0"
    "consignmentID\0processEditAction\0id\0"
    "processAddAction\0processGeneratePricetags\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProductsView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08,
       5,    1,   42,    2, 0x08,
       7,    1,   45,    2, 0x08,
       9,    0,   48,    2, 0x08,
      10,    1,   49,    2, 0x08,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void ProductsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProductsView *_t = static_cast<ProductsView *>(_o);
        switch (_id) {
        case 0: _t->processMenuActions((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 1: _t->processSaleAction((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->processEditAction((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->processAddAction(); break;
        case 4: _t->processGeneratePricetags((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ProductsView::staticMetaObject = {
    { &TableView::staticMetaObject, qt_meta_stringdata_ProductsView.data,
      qt_meta_data_ProductsView,  qt_static_metacall, 0, 0}
};


const QMetaObject *ProductsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProductsView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProductsView.stringdata))
        return static_cast<void*>(const_cast< ProductsView*>(this));
    return TableView::qt_metacast(_clname);
}

int ProductsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TableView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
