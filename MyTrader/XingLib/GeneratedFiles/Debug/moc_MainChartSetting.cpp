/****************************************************************************
** Meta object code from reading C++ file 'MainChartSetting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Src/service/chart/setting/MainChartSetting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainChartSetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainChartSetting_t {
    QByteArrayData data[13];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainChartSetting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainChartSetting_t qt_meta_stringdata_MainChartSetting = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MainChartSetting"
QT_MOC_LITERAL(1, 17, 8), // "logScale"
QT_MOC_LITERAL(2, 26, 15), // "percentageScale"
QT_MOC_LITERAL(3, 42, 13), // "candleUpColor"
QT_MOC_LITERAL(4, 56, 13), // "candleDnColor"
QT_MOC_LITERAL(5, 70, 9), // "lineColor"
QT_MOC_LITERAL(6, 80, 15), // "MAIN_CHART_TYPE"
QT_MOC_LITERAL(7, 96, 12), // "CANDLE_STICK"
QT_MOC_LITERAL(8, 109, 13), // "CLOSING_PRICE"
QT_MOC_LITERAL(9, 123, 12), // "MEDIAN_PRICE"
QT_MOC_LITERAL(10, 136, 4), // "OHLC"
QT_MOC_LITERAL(11, 141, 13), // "TYPICAL_PRICE"
QT_MOC_LITERAL(12, 155, 14) // "WEIGHTED_CLOSE"

    },
    "MainChartSetting\0logScale\0percentageScale\0"
    "candleUpColor\0candleDnColor\0lineColor\0"
    "MAIN_CHART_TYPE\0CANDLE_STICK\0CLOSING_PRICE\0"
    "MEDIAN_PRICE\0OHLC\0TYPICAL_PRICE\0"
    "WEIGHTED_CLOSE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainChartSetting[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       5,   14, // properties
       1,   29, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Bool, 0x00095103,
       2, QMetaType::Bool, 0x00095103,
       3, QMetaType::Long, 0x00095103,
       4, QMetaType::Long, 0x00095103,
       5, QMetaType::Long, 0x00095103,

 // enums: name, flags, count, data
       6, 0x0,    6,   33,

 // enum data: key, value
       7, uint(MainChartSetting::CANDLE_STICK),
       8, uint(MainChartSetting::CLOSING_PRICE),
       9, uint(MainChartSetting::MEDIAN_PRICE),
      10, uint(MainChartSetting::OHLC),
      11, uint(MainChartSetting::TYPICAL_PRICE),
      12, uint(MainChartSetting::WEIGHTED_CLOSE),

       0        // eod
};

void MainChartSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        MainChartSetting *_t = static_cast<MainChartSetting *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->logScale(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->percentageScale(); break;
        case 2: *reinterpret_cast< long*>(_v) = _t->candleUpColor(); break;
        case 3: *reinterpret_cast< long*>(_v) = _t->candleDnColor(); break;
        case 4: *reinterpret_cast< long*>(_v) = _t->lineColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        MainChartSetting *_t = static_cast<MainChartSetting *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLogScale(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setPercentageScale(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setCandleUpColor(*reinterpret_cast< long*>(_v)); break;
        case 3: _t->setCandleDnColor(*reinterpret_cast< long*>(_v)); break;
        case 4: _t->setLineColor(*reinterpret_cast< long*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MainChartSetting::staticMetaObject = {
    { &ChartSetting::staticMetaObject, qt_meta_stringdata_MainChartSetting.data,
      qt_meta_data_MainChartSetting,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainChartSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainChartSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainChartSetting.stringdata0))
        return static_cast<void*>(const_cast< MainChartSetting*>(this));
    return ChartSetting::qt_metacast(_clname);
}

int MainChartSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ChartSetting::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
