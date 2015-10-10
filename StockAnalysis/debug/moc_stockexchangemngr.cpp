/****************************************************************************
** Meta object code from reading C++ file 'stockexchangemngr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../function/sad/stockexchangemngr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stockexchangemngr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StockExchangeMngr_t {
    QByteArrayData data[11];
    char stringdata[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StockExchangeMngr_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StockExchangeMngr_t qt_meta_stringdata_StockExchangeMngr = {
    {
QT_MOC_LITERAL(0, 0, 17), // "StockExchangeMngr"
QT_MOC_LITERAL(1, 18, 24), // "responseWarehouseHistory"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 14), // "WarehouseInfo*"
QT_MOC_LITERAL(4, 59, 10), // "historyMap"
QT_MOC_LITERAL(5, 70, 25), // "responseStockExchangeInfo"
QT_MOC_LITERAL(6, 96, 18), // "StockExchangeInfo*"
QT_MOC_LITERAL(7, 115, 17), // "stockExchangeInfo"
QT_MOC_LITERAL(8, 133, 20), // "makeWarehouseHistory"
QT_MOC_LITERAL(9, 154, 6), // "shcode"
QT_MOC_LITERAL(10, 161, 21) // "makeStockExchangeInfo"

    },
    "StockExchangeMngr\0responseWarehouseHistory\0"
    "\0WarehouseInfo*\0historyMap\0"
    "responseStockExchangeInfo\0StockExchangeInfo*\0"
    "stockExchangeInfo\0makeWarehouseHistory\0"
    "shcode\0makeStockExchangeInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StockExchangeMngr[] = {

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
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   40,    2, 0x08 /* Private */,
      10,    1,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void StockExchangeMngr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StockExchangeMngr *_t = static_cast<StockExchangeMngr *>(_o);
        switch (_id) {
        case 0: _t->responseWarehouseHistory((*reinterpret_cast< WarehouseInfo*(*)>(_a[1]))); break;
        case 1: _t->responseStockExchangeInfo((*reinterpret_cast< StockExchangeInfo*(*)>(_a[1]))); break;
        case 2: _t->makeWarehouseHistory((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->makeStockExchangeInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StockExchangeMngr::*_t)(WarehouseInfo * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StockExchangeMngr::responseWarehouseHistory)) {
                *result = 0;
            }
        }
        {
            typedef void (StockExchangeMngr::*_t)(StockExchangeInfo * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StockExchangeMngr::responseStockExchangeInfo)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject StockExchangeMngr::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StockExchangeMngr.data,
      qt_meta_data_StockExchangeMngr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StockExchangeMngr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StockExchangeMngr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StockExchangeMngr.stringdata))
        return static_cast<void*>(const_cast< StockExchangeMngr*>(this));
    return QObject::qt_metacast(_clname);
}

int StockExchangeMngr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void StockExchangeMngr::responseWarehouseHistory(WarehouseInfo * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StockExchangeMngr::responseStockExchangeInfo(StockExchangeInfo * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
