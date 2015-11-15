/****************************************************************************
** Meta object code from reading C++ file 'chartwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Src/service/chart/ui/chartwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chartwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChartWidget_t {
    QByteArrayData data[13];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChartWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChartWidget_t qt_meta_stringdata_ChartWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ChartWidget"
QT_MOC_LITERAL(1, 12, 24), // "onStockPriceDataReceived"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 15), // "StockPriceData*"
QT_MOC_LITERAL(4, 54, 9), // "stockData"
QT_MOC_LITERAL(5, 64, 17), // "onViewPortChanged"
QT_MOC_LITERAL(6, 82, 26), // "on_shcodeSearchBtn_clicked"
QT_MOC_LITERAL(7, 109, 14), // "onChartClicked"
QT_MOC_LITERAL(8, 124, 12), // "QMouseEvent*"
QT_MOC_LITERAL(9, 137, 22), // "onMainChartTypeChanged"
QT_MOC_LITERAL(10, 160, 2), // "id"
QT_MOC_LITERAL(11, 163, 7), // "checked"
QT_MOC_LITERAL(12, 171, 20) // "onChannelTypeChanged"

    },
    "ChartWidget\0onStockPriceDataReceived\0"
    "\0StockPriceData*\0stockData\0onViewPortChanged\0"
    "on_shcodeSearchBtn_clicked\0onChartClicked\0"
    "QMouseEvent*\0onMainChartTypeChanged\0"
    "id\0checked\0onChannelTypeChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChartWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    1,   49,    2, 0x08 /* Private */,
       9,    2,   52,    2, 0x08 /* Private */,
      12,    2,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   10,   11,

       0        // eod
};

void ChartWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChartWidget *_t = static_cast<ChartWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onStockPriceDataReceived((*reinterpret_cast< StockPriceData*(*)>(_a[1]))); break;
        case 1: _t->onViewPortChanged(); break;
        case 2: _t->on_shcodeSearchBtn_clicked(); break;
        case 3: _t->onChartClicked((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->onMainChartTypeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->onChannelTypeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject ChartWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChartWidget.data,
      qt_meta_data_ChartWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChartWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChartWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChartWidget.stringdata0))
        return static_cast<void*>(const_cast< ChartWidget*>(this));
    if (!strcmp(_clname, "ChartInfo"))
        return static_cast< ChartInfo*>(const_cast< ChartWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChartWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
