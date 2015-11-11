/****************************************************************************
** Meta object code from reading C++ file 't1537item.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Src/core/tr/t1537/t1537item.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 't1537item.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_T1537Item_t {
    QByteArrayData data[15];
    char stringdata[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_T1537Item_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_T1537Item_t qt_meta_stringdata_T1537Item = {
    {
QT_MOC_LITERAL(0, 0, 9), // "T1537Item"
QT_MOC_LITERAL(1, 10, 5), // "hname"
QT_MOC_LITERAL(2, 16, 5), // "price"
QT_MOC_LITERAL(3, 22, 4), // "sign"
QT_MOC_LITERAL(4, 27, 6), // "change"
QT_MOC_LITERAL(5, 34, 4), // "diff"
QT_MOC_LITERAL(6, 39, 6), // "volume"
QT_MOC_LITERAL(7, 46, 8), // "jniltime"
QT_MOC_LITERAL(8, 55, 6), // "shcode"
QT_MOC_LITERAL(9, 62, 7), // "yeprice"
QT_MOC_LITERAL(10, 70, 4), // "open"
QT_MOC_LITERAL(11, 75, 4), // "high"
QT_MOC_LITERAL(12, 80, 3), // "low"
QT_MOC_LITERAL(13, 84, 5), // "value"
QT_MOC_LITERAL(14, 90, 9) // "marketcap"

    },
    "T1537Item\0hname\0price\0sign\0change\0"
    "diff\0volume\0jniltime\0shcode\0yeprice\0"
    "open\0high\0low\0value\0marketcap"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_T1537Item[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      14,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095103,
       2, QMetaType::Long, 0x00095103,
       3, QMetaType::QString, 0x00095103,
       4, QMetaType::Long, 0x00095103,
       5, QMetaType::Float, 0x00095103,
       6, QMetaType::Long, 0x00095103,
       7, QMetaType::QTime, 0x00095103,
       8, QMetaType::QString, 0x00095103,
       9, QMetaType::Long, 0x00095103,
      10, QMetaType::Long, 0x00095103,
      11, QMetaType::Long, 0x00095103,
      12, QMetaType::Long, 0x00095103,
      13, QMetaType::Long, 0x00095103,
      14, QMetaType::Long, 0x00095103,

       0        // eod
};

void T1537Item::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject T1537Item::staticMetaObject = {
    { &TrItem::staticMetaObject, qt_meta_stringdata_T1537Item.data,
      qt_meta_data_T1537Item,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *T1537Item::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *T1537Item::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_T1537Item.stringdata))
        return static_cast<void*>(const_cast< T1537Item*>(this));
    return TrItem::qt_metacast(_clname);
}

int T1537Item::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TrItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = hname(); break;
        case 1: *reinterpret_cast< long*>(_v) = price(); break;
        case 2: *reinterpret_cast< QString*>(_v) = sign(); break;
        case 3: *reinterpret_cast< long*>(_v) = change(); break;
        case 4: *reinterpret_cast< float*>(_v) = diff(); break;
        case 5: *reinterpret_cast< long*>(_v) = volume(); break;
        case 6: *reinterpret_cast< QTime*>(_v) = jniltime(); break;
        case 7: *reinterpret_cast< QString*>(_v) = shcode(); break;
        case 8: *reinterpret_cast< long*>(_v) = yeprice(); break;
        case 9: *reinterpret_cast< long*>(_v) = open(); break;
        case 10: *reinterpret_cast< long*>(_v) = high(); break;
        case 11: *reinterpret_cast< long*>(_v) = low(); break;
        case 12: *reinterpret_cast< long*>(_v) = value(); break;
        case 13: *reinterpret_cast< long*>(_v) = marketcap(); break;
        default: break;
        }
        _id -= 14;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setHname(*reinterpret_cast< QString*>(_v)); break;
        case 1: setPrice(*reinterpret_cast< long*>(_v)); break;
        case 2: setSign(*reinterpret_cast< QString*>(_v)); break;
        case 3: setChange(*reinterpret_cast< long*>(_v)); break;
        case 4: setDiff(*reinterpret_cast< float*>(_v)); break;
        case 5: setVolume(*reinterpret_cast< long*>(_v)); break;
        case 6: setJniltime(*reinterpret_cast< QTime*>(_v)); break;
        case 7: setShcode(*reinterpret_cast< QString*>(_v)); break;
        case 8: setYeprice(*reinterpret_cast< long*>(_v)); break;
        case 9: setOpen(*reinterpret_cast< long*>(_v)); break;
        case 10: setHigh(*reinterpret_cast< long*>(_v)); break;
        case 11: setLow(*reinterpret_cast< long*>(_v)); break;
        case 12: setValue(*reinterpret_cast< long*>(_v)); break;
        case 13: setMarketcap(*reinterpret_cast< long*>(_v)); break;
        default: break;
        }
        _id -= 14;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 14;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
