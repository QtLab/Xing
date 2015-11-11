/****************************************************************************
** Meta object code from reading C++ file 'stockchartdatamanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Src/service/chart/stockchartdatamanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stockchartdatamanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StockChartDataManager_t {
    QByteArrayData data[13];
    char stringdata[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StockChartDataManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StockChartDataManager_t qt_meta_stringdata_StockChartDataManager = {
    {
QT_MOC_LITERAL(0, 0, 21), // "StockChartDataManager"
QT_MOC_LITERAL(1, 22, 17), // "responseStockData"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 15), // "StockPriceData*"
QT_MOC_LITERAL(4, 57, 7), // "history"
QT_MOC_LITERAL(5, 65, 16), // "requestStockData"
QT_MOC_LITERAL(6, 82, 6), // "shcode"
QT_MOC_LITERAL(7, 89, 9), // "TIME_UNIT"
QT_MOC_LITERAL(8, 99, 8), // "timeUnit"
QT_MOC_LITERAL(9, 108, 9), // "startDate"
QT_MOC_LITERAL(10, 118, 7), // "endDate"
QT_MOC_LITERAL(11, 126, 14), // "modified_price"
QT_MOC_LITERAL(12, 141, 19) // "onReceivedStockData"

    },
    "StockChartDataManager\0responseStockData\0"
    "\0StockPriceData*\0history\0requestStockData\0"
    "shcode\0TIME_UNIT\0timeUnit\0startDate\0"
    "endDate\0modified_price\0onReceivedStockData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StockChartDataManager[] = {

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
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    5,   37,    2, 0x0a /* Public */,
       5,    3,   48,    2, 0x0a /* Public */,
      12,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7, QMetaType::QDate, QMetaType::QDate, QMetaType::Bool,    6,    8,    9,   10,   11,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7, QMetaType::Bool,    6,    8,   11,
    QMetaType::Void,

       0        // eod
};

void StockChartDataManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StockChartDataManager *_t = static_cast<StockChartDataManager *>(_o);
        switch (_id) {
        case 0: _t->responseStockData((*reinterpret_cast< StockPriceData*(*)>(_a[1]))); break;
        case 1: _t->requestStockData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< TIME_UNIT(*)>(_a[2])),(*reinterpret_cast< const QDate(*)>(_a[3])),(*reinterpret_cast< const QDate(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 2: _t->requestStockData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< TIME_UNIT(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->onReceivedStockData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StockChartDataManager::*_t)(StockPriceData * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StockChartDataManager::responseStockData)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject StockChartDataManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StockChartDataManager.data,
      qt_meta_data_StockChartDataManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StockChartDataManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StockChartDataManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StockChartDataManager.stringdata))
        return static_cast<void*>(const_cast< StockChartDataManager*>(this));
    return QObject::qt_metacast(_clname);
}

int StockChartDataManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void StockChartDataManager::responseStockData(StockPriceData * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
