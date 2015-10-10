/****************************************************************************
** Meta object code from reading C++ file 'stockinfoupdater.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../function/info/stockinfoupdater.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stockinfoupdater.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StockInfoUpdater_t {
    QByteArrayData data[6];
    char stringdata[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StockInfoUpdater_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StockInfoUpdater_t qt_meta_stringdata_StockInfoUpdater = {
    {
QT_MOC_LITERAL(0, 0, 16), // "StockInfoUpdater"
QT_MOC_LITERAL(1, 17, 19), // "updateStockInfoDone"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 15), // "updateStockInfo"
QT_MOC_LITERAL(4, 54, 14), // "t8430QueryDone"
QT_MOC_LITERAL(5, 69, 14) // "t1102QueryDone"

    },
    "StockInfoUpdater\0updateStockInfoDone\0"
    "\0updateStockInfo\0t8430QueryDone\0"
    "t1102QueryDone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StockInfoUpdater[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StockInfoUpdater::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StockInfoUpdater *_t = static_cast<StockInfoUpdater *>(_o);
        switch (_id) {
        case 0: _t->updateStockInfoDone(); break;
        case 1: _t->updateStockInfo(); break;
        case 2: _t->t8430QueryDone(); break;
        case 3: _t->t1102QueryDone(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StockInfoUpdater::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StockInfoUpdater::updateStockInfoDone)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject StockInfoUpdater::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StockInfoUpdater.data,
      qt_meta_data_StockInfoUpdater,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StockInfoUpdater::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StockInfoUpdater::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StockInfoUpdater.stringdata))
        return static_cast<void*>(const_cast< StockInfoUpdater*>(this));
    return QObject::qt_metacast(_clname);
}

int StockInfoUpdater::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void StockInfoUpdater::updateStockInfoDone()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
