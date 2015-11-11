/****************************************************************************
** Meta object code from reading C++ file 't1537query.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Src/core/tr/t1537/t1537query.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 't1537query.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_T1537Query_t {
    QByteArrayData data[6];
    char stringdata[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_T1537Query_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_T1537Query_t qt_meta_stringdata_T1537Query = {
    {
QT_MOC_LITERAL(0, 0, 10), // "T1537Query"
QT_MOC_LITERAL(1, 11, 6), // "tmcode"
QT_MOC_LITERAL(2, 18, 5), // "upcnt"
QT_MOC_LITERAL(3, 24, 5), // "tmcnt"
QT_MOC_LITERAL(4, 30, 6), // "uprate"
QT_MOC_LITERAL(5, 37, 6) // "tmname"

    },
    "T1537Query\0tmcode\0upcnt\0tmcnt\0uprate\0"
    "tmname"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_T1537Query[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       5,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095103,
       2, QMetaType::Long, 0x00095003,
       3, QMetaType::Long, 0x00095003,
       4, QMetaType::Long, 0x00095003,
       5, QMetaType::QString, 0x00095003,

       0        // eod
};

void T1537Query::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject T1537Query::staticMetaObject = {
    { &CtsTrQuery::staticMetaObject, qt_meta_stringdata_T1537Query.data,
      qt_meta_data_T1537Query,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *T1537Query::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *T1537Query::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_T1537Query.stringdata))
        return static_cast<void*>(const_cast< T1537Query*>(this));
    return CtsTrQuery::qt_metacast(_clname);
}

int T1537Query::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CtsTrQuery::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = tmcode(); break;
        case 1: *reinterpret_cast< long*>(_v) = upcnt(); break;
        case 2: *reinterpret_cast< long*>(_v) = tmcnt(); break;
        case 3: *reinterpret_cast< long*>(_v) = uprate(); break;
        case 4: *reinterpret_cast< QString*>(_v) = tmname(); break;
        default: break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setTmcode(*reinterpret_cast< QString*>(_v)); break;
        case 1: setUpCnt(*reinterpret_cast< long*>(_v)); break;
        case 2: setTmCnt(*reinterpret_cast< long*>(_v)); break;
        case 3: setUpRate(*reinterpret_cast< long*>(_v)); break;
        case 4: setTmName(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
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
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
