/****************************************************************************
** Meta object code from reading C++ file 'SoldProductsView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/SoldProductsView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SoldProductsView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SoldProductsView_t {
    QByteArrayData data[11];
    char stringdata[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SoldProductsView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SoldProductsView_t qt_meta_stringdata_SoldProductsView = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 18),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 8),
QT_MOC_LITERAL(4, 46, 6),
QT_MOC_LITERAL(5, 53, 26),
QT_MOC_LITERAL(6, 80, 9),
QT_MOC_LITERAL(7, 90, 24),
QT_MOC_LITERAL(8, 115, 8),
QT_MOC_LITERAL(9, 124, 16),
QT_MOC_LITERAL(10, 141, 13)
    },
    "SoldProductsView\0processMenuActions\0"
    "\0QAction*\0action\0processReturnProductAction\0"
    "productID\0processAboutClientAction\0"
    "clientID\0processOtherSize\0consignmentID\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SoldProductsView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08,
       5,    1,   37,    2, 0x08,
       7,    1,   40,    2, 0x08,
       9,    1,   43,    2, 0x08,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void SoldProductsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SoldProductsView *_t = static_cast<SoldProductsView *>(_o);
        switch (_id) {
        case 0: _t->processMenuActions((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 1: _t->processReturnProductAction((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->processAboutClientAction((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->processOtherSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject SoldProductsView::staticMetaObject = {
    { &TableView::staticMetaObject, qt_meta_stringdata_SoldProductsView.data,
      qt_meta_data_SoldProductsView,  qt_static_metacall, 0, 0}
};


const QMetaObject *SoldProductsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SoldProductsView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SoldProductsView.stringdata))
        return static_cast<void*>(const_cast< SoldProductsView*>(this));
    return TableView::qt_metacast(_clname);
}

int SoldProductsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TableView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
