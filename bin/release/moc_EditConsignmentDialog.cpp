/****************************************************************************
** Meta object code from reading C++ file 'EditConsignmentDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/EditConsignmentDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EditConsignmentDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EditConsignmentDialog_t {
    QByteArrayData data[8];
    char stringdata[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_EditConsignmentDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_EditConsignmentDialog_t qt_meta_stringdata_EditConsignmentDialog = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 19),
QT_MOC_LITERAL(2, 42, 0),
QT_MOC_LITERAL(3, 43, 14),
QT_MOC_LITERAL(4, 58, 18),
QT_MOC_LITERAL(5, 77, 8),
QT_MOC_LITERAL(6, 86, 6),
QT_MOC_LITERAL(7, 93, 14)
    },
    "EditConsignmentDialog\0saveConsignmentData\0"
    "\0addNewProducts\0processMenuActions\0"
    "QAction*\0action\0validateFields\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditConsignmentDialog[] = {

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
       7,    0,   39,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

       0        // eod
};

void EditConsignmentDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EditConsignmentDialog *_t = static_cast<EditConsignmentDialog *>(_o);
        switch (_id) {
        case 0: _t->saveConsignmentData(); break;
        case 1: _t->addNewProducts(); break;
        case 2: _t->processMenuActions((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 3: _t->validateFields(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject EditConsignmentDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EditConsignmentDialog.data,
      qt_meta_data_EditConsignmentDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *EditConsignmentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditConsignmentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditConsignmentDialog.stringdata))
        return static_cast<void*>(const_cast< EditConsignmentDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int EditConsignmentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
