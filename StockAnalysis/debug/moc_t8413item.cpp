/****************************************************************************
** Meta object code from reading C++ file 't8413item.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tr/t8413/t8413item.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 't8413item.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_T8413Item_t {
    QByteArrayData data[13];
    char stringdata[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_T8413Item_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_T8413Item_t qt_meta_stringdata_T8413Item = {
    {
QT_MOC_LITERAL(0, 0, 9), // "T8413Item"
QT_MOC_LITERAL(1, 10, 4), // "date"
QT_MOC_LITERAL(2, 15, 4), // "open"
QT_MOC_LITERAL(3, 20, 4), // "high"
QT_MOC_LITERAL(4, 25, 3), // "low"
QT_MOC_LITERAL(5, 29, 5), // "close"
QT_MOC_LITERAL(6, 35, 9), // "jdiff_vol"
QT_MOC_LITERAL(7, 45, 5), // "value"
QT_MOC_LITERAL(8, 51, 7), // "jongchk"
QT_MOC_LITERAL(9, 59, 4), // "rate"
QT_MOC_LITERAL(10, 64, 8), // "pricechk"
QT_MOC_LITERAL(11, 73, 9), // "ratevalue"
QT_MOC_LITERAL(12, 83, 4) // "sign"

    },
    "T8413Item\0date\0open\0high\0low\0close\0"
    "jdiff_vol\0value\0jongchk\0rate\0pricechk\0"
    "ratevalue\0sign"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_T8413Item[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      12,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QDate, 0x00095103,
       2, QMetaType::Long, 0x00095103,
       3, QMetaType::Long, 0x00095103,
       4, QMetaType::Long, 0x00095103,
       5, QMetaType::Long, 0x00095103,
       6, QMetaType::Long, 0x00095003,
       7, QMetaType::Long, 0x00095103,
       8, QMetaType::Long, 0x00095103,
       9, QMetaType::Double, 0x00095103,
      10, QMetaType::Long, 0x00095103,
      11, QMetaType::Long, 0x00095103,
      12, QMetaType::QString, 0x00095103,

       0        // eod
};

void T8413Item::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject T8413Item::staticMetaObject = {
    { &TrItem::staticMetaObject, qt_meta_stringdata_T8413Item.data,
      qt_meta_data_T8413Item,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *T8413Item::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *T8413Item::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_T8413Item.stringdata))
        return static_cast<void*>(const_cast< T8413Item*>(this));
    return TrItem::qt_metacast(_clname);
}

int T8413Item::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TrItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QDate*>(_v) = date(); break;
        case 1: *reinterpret_cast< long*>(_v) = open(); break;
        case 2: *reinterpret_cast< long*>(_v) = high(); break;
        case 3: *reinterpret_cast< long*>(_v) = low(); break;
        case 4: *reinterpret_cast< long*>(_v) = close(); break;
        case 5: *reinterpret_cast< long*>(_v) = jdiff_vol(); break;
        case 6: *reinterpret_cast< long*>(_v) = value(); break;
        case 7: *reinterpret_cast< long*>(_v) = jongchk(); break;
        case 8: *reinterpret_cast< double*>(_v) = rate(); break;
        case 9: *reinterpret_cast< long*>(_v) = pricechk(); break;
        case 10: *reinterpret_cast< long*>(_v) = ratevalue(); break;
        case 11: *reinterpret_cast< QString*>(_v) = sign(); break;
        default: break;
        }
        _id -= 12;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setDate(*reinterpret_cast< QDate*>(_v)); break;
        case 1: setOpen(*reinterpret_cast< long*>(_v)); break;
        case 2: setHigh(*reinterpret_cast< long*>(_v)); break;
        case 3: setLow(*reinterpret_cast< long*>(_v)); break;
        case 4: setClose(*reinterpret_cast< long*>(_v)); break;
        case 5: setJdiff_Vol(*reinterpret_cast< long*>(_v)); break;
        case 6: setValue(*reinterpret_cast< long*>(_v)); break;
        case 7: setJongchk(*reinterpret_cast< long*>(_v)); break;
        case 8: setRate(*reinterpret_cast< double*>(_v)); break;
        case 9: setPricechk(*reinterpret_cast< long*>(_v)); break;
        case 10: setRatevalue(*reinterpret_cast< long*>(_v)); break;
        case 11: setSign(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
        _id -= 12;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 12;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
