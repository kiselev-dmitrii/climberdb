/****************************************************************************
** Meta object code from reading C++ file 'CreateConsignmentDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CreateConsignmentDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateConsignmentDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateConsignmentDialog_t {
    QByteArrayData data[7];
    char stringdata[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CreateConsignmentDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CreateConsignmentDialog_t qt_meta_stringdata_CreateConsignmentDialog = {
    {
QT_MOC_LITERAL(0, 0, 23),
QT_MOC_LITERAL(1, 24, 8),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 19),
QT_MOC_LITERAL(4, 54, 16),
QT_MOC_LITERAL(5, 71, 13),
QT_MOC_LITERAL(6, 85, 14)
    },
    "CreateConsignmentDialog\0saveData\0\0"
    "saveConsignmentData\0saveProductsData\0"
    "consignmentID\0validateFields\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateConsignmentDialog[] = {

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
       1,    0,   34,    2, 0x08,
       3,    0,   35,    2, 0x08,
       4,    1,   36,    2, 0x08,
       6,    0,   39,    2, 0x08,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

       0        // eod
};

void CreateConsignmentDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateConsignmentDialog *_t = static_cast<CreateConsignmentDialog *>(_o);
        switch (_id) {
        case 0: { int _r = _t->saveData();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->saveConsignmentData();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: _t->saveProductsData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->validateFields(); break;
        default: ;
        }
    }
}

const QMetaObject CreateConsignmentDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateConsignmentDialog.data,
      qt_meta_data_CreateConsignmentDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *CreateConsignmentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateConsignmentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CreateConsignmentDialog.stringdata))
        return static_cast<void*>(const_cast< CreateConsignmentDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateConsignmentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
