/****************************************************************************
** Meta object code from reading C++ file 't1702item.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Src/core/tr/t1702/t1702item.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 't1702item.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_T1702Item_t {
    QByteArrayData data[22];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_T1702Item_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_T1702Item_t qt_meta_stringdata_T1702Item = {
    {
QT_MOC_LITERAL(0, 0, 9), // "T1702Item"
QT_MOC_LITERAL(1, 10, 4), // "date"
QT_MOC_LITERAL(2, 15, 5), // "close"
QT_MOC_LITERAL(3, 21, 4), // "sign"
QT_MOC_LITERAL(4, 26, 6), // "change"
QT_MOC_LITERAL(5, 33, 4), // "diff"
QT_MOC_LITERAL(6, 38, 6), // "volume"
QT_MOC_LITERAL(7, 45, 7), // "amt0000"
QT_MOC_LITERAL(8, 53, 7), // "amt0001"
QT_MOC_LITERAL(9, 61, 7), // "amt0002"
QT_MOC_LITERAL(10, 69, 7), // "amt0003"
QT_MOC_LITERAL(11, 77, 7), // "amt0004"
QT_MOC_LITERAL(12, 85, 7), // "amt0005"
QT_MOC_LITERAL(13, 93, 7), // "amt0006"
QT_MOC_LITERAL(14, 101, 7), // "amt0007"
QT_MOC_LITERAL(15, 109, 7), // "amt0008"
QT_MOC_LITERAL(16, 117, 7), // "amt0009"
QT_MOC_LITERAL(17, 125, 7), // "amt0010"
QT_MOC_LITERAL(18, 133, 7), // "amt0011"
QT_MOC_LITERAL(19, 141, 7), // "amt0018"
QT_MOC_LITERAL(20, 149, 7), // "amt0088"
QT_MOC_LITERAL(21, 157, 7) // "amt0099"

    },
    "T1702Item\0date\0close\0sign\0change\0diff\0"
    "volume\0amt0000\0amt0001\0amt0002\0amt0003\0"
    "amt0004\0amt0005\0amt0006\0amt0007\0amt0008\0"
    "amt0009\0amt0010\0amt0011\0amt0018\0amt0088\0"
    "amt0099"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_T1702Item[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      21,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QDate, 0x00095103,
       2, QMetaType::Long, 0x00095103,
       3, QMetaType::QString, 0x00095103,
       4, QMetaType::Long, 0x00095103,
       5, QMetaType::Float, 0x00095103,
       6, QMetaType::Long, 0x00095103,
       7, QMetaType::Long, 0x00095103,
       8, QMetaType::Long, 0x00095103,
       9, QMetaType::Long, 0x00095103,
      10, QMetaType::Long, 0x00095103,
      11, QMetaType::Long, 0x00095103,
      12, QMetaType::Long, 0x00095103,
      13, QMetaType::Long, 0x00095103,
      14, QMetaType::Long, 0x00095103,
      15, QMetaType::Long, 0x00095103,
      16, QMetaType::Long, 0x00095103,
      17, QMetaType::Long, 0x00095103,
      18, QMetaType::Long, 0x00095103,
      19, QMetaType::Long, 0x00095103,
      20, QMetaType::Long, 0x00095103,
      21, QMetaType::Long, 0x00095103,

       0        // eod
};

void T1702Item::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        T1702Item *_t = static_cast<T1702Item *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QDate*>(_v) = _t->date(); break;
        case 1: *reinterpret_cast< long*>(_v) = _t->close(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->sign(); break;
        case 3: *reinterpret_cast< long*>(_v) = _t->change(); break;
        case 4: *reinterpret_cast< float*>(_v) = _t->diff(); break;
        case 5: *reinterpret_cast< long*>(_v) = _t->volume(); break;
        case 6: *reinterpret_cast< long*>(_v) = _t->amt0000(); break;
        case 7: *reinterpret_cast< long*>(_v) = _t->amt0001(); break;
        case 8: *reinterpret_cast< long*>(_v) = _t->amt0002(); break;
        case 9: *reinterpret_cast< long*>(_v) = _t->amt0003(); break;
        case 10: *reinterpret_cast< long*>(_v) = _t->amt0004(); break;
        case 11: *reinterpret_cast< long*>(_v) = _t->amt0005(); break;
        case 12: *reinterpret_cast< long*>(_v) = _t->amt0006(); break;
        case 13: *reinterpret_cast< long*>(_v) = _t->amt0007(); break;
        case 14: *reinterpret_cast< long*>(_v) = _t->amt0008(); break;
        case 15: *reinterpret_cast< long*>(_v) = _t->amt0009(); break;
        case 16: *reinterpret_cast< long*>(_v) = _t->amt0010(); break;
        case 17: *reinterpret_cast< long*>(_v) = _t->amt0011(); break;
        case 18: *reinterpret_cast< long*>(_v) = _t->amt0018(); break;
        case 19: *reinterpret_cast< long*>(_v) = _t->amt0088(); break;
        case 20: *reinterpret_cast< long*>(_v) = _t->amt0099(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        T1702Item *_t = static_cast<T1702Item *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDate(*reinterpret_cast< QDate*>(_v)); break;
        case 1: _t->setClose(*reinterpret_cast< long*>(_v)); break;
        case 2: _t->setSign(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setChange(*reinterpret_cast< long*>(_v)); break;
        case 4: _t->setDiff(*reinterpret_cast< float*>(_v)); break;
        case 5: _t->setVolume(*reinterpret_cast< long*>(_v)); break;
        case 6: _t->setAmt0000(*reinterpret_cast< long*>(_v)); break;
        case 7: _t->setAmt0001(*reinterpret_cast< long*>(_v)); break;
        case 8: _t->setAmt0002(*reinterpret_cast< long*>(_v)); break;
        case 9: _t->setAmt0003(*reinterpret_cast< long*>(_v)); break;
        case 10: _t->setAmt0004(*reinterpret_cast< long*>(_v)); break;
        case 11: _t->setAmt0005(*reinterpret_cast< long*>(_v)); break;
        case 12: _t->setAmt0006(*reinterpret_cast< long*>(_v)); break;
        case 13: _t->setAmt0007(*reinterpret_cast< long*>(_v)); break;
        case 14: _t->setAmt0008(*reinterpret_cast< long*>(_v)); break;
        case 15: _t->setAmt0009(*reinterpret_cast< long*>(_v)); break;
        case 16: _t->setAmt0010(*reinterpret_cast< long*>(_v)); break;
        case 17: _t->setAmt0011(*reinterpret_cast< long*>(_v)); break;
        case 18: _t->setAmt0018(*reinterpret_cast< long*>(_v)); break;
        case 19: _t->setAmt0088(*reinterpret_cast< long*>(_v)); break;
        case 20: _t->setAmt0099(*reinterpret_cast< long*>(_v)); break;
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

const QMetaObject T1702Item::staticMetaObject = {
    { &TrItem::staticMetaObject, qt_meta_stringdata_T1702Item.data,
      qt_meta_data_T1702Item,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *T1702Item::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *T1702Item::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_T1702Item.stringdata0))
        return static_cast<void*>(const_cast< T1702Item*>(this));
    return TrItem::qt_metacast(_clname);
}

int T1702Item::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TrItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 21;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
