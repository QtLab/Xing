/****************************************************************************
** Meta object code from reading C++ file 't8430item.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Src/core/tr/t8430/t8430item.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 't8430item.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_T8430Item_t {
    QByteArrayData data[11];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_T8430Item_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_T8430Item_t qt_meta_stringdata_T8430Item = {
    {
QT_MOC_LITERAL(0, 0, 9), // "T8430Item"
QT_MOC_LITERAL(1, 10, 5), // "hname"
QT_MOC_LITERAL(2, 16, 6), // "shcode"
QT_MOC_LITERAL(3, 23, 7), // "expcode"
QT_MOC_LITERAL(4, 31, 8), // "etfgubun"
QT_MOC_LITERAL(5, 40, 10), // "uplmtprice"
QT_MOC_LITERAL(6, 51, 10), // "dnlmtprice"
QT_MOC_LITERAL(7, 62, 9), // "jnilclose"
QT_MOC_LITERAL(8, 72, 7), // "memedan"
QT_MOC_LITERAL(9, 80, 8), // "recprice"
QT_MOC_LITERAL(10, 89, 5) // "gubun"

    },
    "T8430Item\0hname\0shcode\0expcode\0etfgubun\0"
    "uplmtprice\0dnlmtprice\0jnilclose\0memedan\0"
    "recprice\0gubun"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_T8430Item[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      10,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095103,
       2, QMetaType::QString, 0x00095103,
       3, QMetaType::QString, 0x00095103,
       4, QMetaType::QString, 0x00095103,
       5, QMetaType::Long, 0x00095103,
       6, QMetaType::Long, 0x00095103,
       7, QMetaType::Long, 0x00095103,
       8, QMetaType::QString, 0x00095103,
       9, QMetaType::Long, 0x00095103,
      10, QMetaType::QString, 0x00095103,

       0        // eod
};

void T8430Item::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        T8430Item *_t = static_cast<T8430Item *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->hname(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->shcode(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->expcode(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->etfgubun(); break;
        case 4: *reinterpret_cast< long*>(_v) = _t->uplmtprice(); break;
        case 5: *reinterpret_cast< long*>(_v) = _t->dnlmtprice(); break;
        case 6: *reinterpret_cast< long*>(_v) = _t->jnilclose(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->memedan(); break;
        case 8: *reinterpret_cast< long*>(_v) = _t->recprice(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->gubun(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        T8430Item *_t = static_cast<T8430Item *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setHname(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setShcode(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setExpcode(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setEtfgubun(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setUplmtprice(*reinterpret_cast< long*>(_v)); break;
        case 5: _t->setDnlmtprice(*reinterpret_cast< long*>(_v)); break;
        case 6: _t->setJnilclose(*reinterpret_cast< long*>(_v)); break;
        case 7: _t->setMemedan(*reinterpret_cast< QString*>(_v)); break;
        case 8: _t->setRecprice(*reinterpret_cast< long*>(_v)); break;
        case 9: _t->setGubun(*reinterpret_cast< QString*>(_v)); break;
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

const QMetaObject T8430Item::staticMetaObject = {
    { &TrItem::staticMetaObject, qt_meta_stringdata_T8430Item.data,
      qt_meta_data_T8430Item,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *T8430Item::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *T8430Item::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_T8430Item.stringdata0))
        return static_cast<void*>(const_cast< T8430Item*>(this));
    return TrItem::qt_metacast(_clname);
}

int T8430Item::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TrItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
