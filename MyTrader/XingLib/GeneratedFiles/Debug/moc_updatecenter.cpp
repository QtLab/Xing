/****************************************************************************
** Meta object code from reading C++ file 'updatecenter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Src/service/info/updatecenter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'updatecenter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UpdateCenter_t {
    QByteArrayData data[9];
    char stringdata[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UpdateCenter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UpdateCenter_t qt_meta_stringdata_UpdateCenter = {
    {
QT_MOC_LITERAL(0, 0, 12), // "UpdateCenter"
QT_MOC_LITERAL(1, 13, 19), // "updateStockInfoDone"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 19), // "updateCodeTableDone"
QT_MOC_LITERAL(4, 54, 23), // "updateMovementTableDone"
QT_MOC_LITERAL(5, 78, 15), // "updateStockInfo"
QT_MOC_LITERAL(6, 94, 15), // "updateCodeTable"
QT_MOC_LITERAL(7, 110, 19), // "updateMovementTable"
QT_MOC_LITERAL(8, 130, 6) // "upcode"

    },
    "UpdateCenter\0updateStockInfoDone\0\0"
    "updateCodeTableDone\0updateMovementTableDone\0"
    "updateStockInfo\0updateCodeTable\0"
    "updateMovementTable\0upcode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UpdateCenter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    1,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void UpdateCenter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UpdateCenter *_t = static_cast<UpdateCenter *>(_o);
        switch (_id) {
        case 0: _t->updateStockInfoDone(); break;
        case 1: _t->updateCodeTableDone(); break;
        case 2: _t->updateMovementTableDone(); break;
        case 3: _t->updateStockInfo(); break;
        case 4: _t->updateCodeTable(); break;
        case 5: _t->updateMovementTable((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UpdateCenter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UpdateCenter::updateStockInfoDone)) {
                *result = 0;
            }
        }
        {
            typedef void (UpdateCenter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UpdateCenter::updateCodeTableDone)) {
                *result = 1;
            }
        }
        {
            typedef void (UpdateCenter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UpdateCenter::updateMovementTableDone)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject UpdateCenter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UpdateCenter.data,
      qt_meta_data_UpdateCenter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UpdateCenter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UpdateCenter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UpdateCenter.stringdata))
        return static_cast<void*>(const_cast< UpdateCenter*>(this));
    return QObject::qt_metacast(_clname);
}

int UpdateCenter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void UpdateCenter::updateStockInfoDone()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void UpdateCenter::updateCodeTableDone()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void UpdateCenter::updateMovementTableDone()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
