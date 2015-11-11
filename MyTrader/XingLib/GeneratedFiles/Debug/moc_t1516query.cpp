/****************************************************************************
** Meta object code from reading C++ file 't1516query.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Src/core/tr/t1516/t1516query.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 't1516query.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_T1516Query_t {
    QByteArrayData data[8];
    char stringdata[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_T1516Query_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_T1516Query_t qt_meta_stringdata_T1516Query = {
    {
QT_MOC_LITERAL(0, 0, 10), // "T1516Query"
QT_MOC_LITERAL(1, 11, 6), // "upcode"
QT_MOC_LITERAL(2, 18, 5), // "gubun"
QT_MOC_LITERAL(3, 24, 6), // "shcode"
QT_MOC_LITERAL(4, 31, 9), // "pricejisu"
QT_MOC_LITERAL(5, 41, 4), // "sign"
QT_MOC_LITERAL(6, 46, 6), // "change"
QT_MOC_LITERAL(7, 53, 5) // "jdiff"

    },
    "T1516Query\0upcode\0gubun\0shcode\0pricejisu\0"
    "sign\0change\0jdiff"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_T1516Query[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       7,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095103,
       2, QMetaType::QString, 0x00095103,
       3, QMetaType::QString, 0x00095103,
       4, QMetaType::Float, 0x00095103,
       5, QMetaType::QString, 0x00095103,
       6, QMetaType::Float, 0x00095103,
       7, QMetaType::Float, 0x00095103,

       0        // eod
};

void T1516Query::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject T1516Query::staticMetaObject = {
    { &CtsTrQuery::staticMetaObject, qt_meta_stringdata_T1516Query.data,
      qt_meta_data_T1516Query,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *T1516Query::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *T1516Query::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_T1516Query.stringdata))
        return static_cast<void*>(const_cast< T1516Query*>(this));
    return CtsTrQuery::qt_metacast(_clname);
}

int T1516Query::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CtsTrQuery::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = upcode(); break;
        case 1: *reinterpret_cast< QString*>(_v) = gubun(); break;
        case 2: *reinterpret_cast< QString*>(_v) = shcode(); break;
        case 3: *reinterpret_cast< float*>(_v) = pricejisu(); break;
        case 4: *reinterpret_cast< QString*>(_v) = sign(); break;
        case 5: *reinterpret_cast< float*>(_v) = change(); break;
        case 6: *reinterpret_cast< float*>(_v) = jdiff(); break;
        default: break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setUpcode(*reinterpret_cast< QString*>(_v)); break;
        case 1: setGubun(*reinterpret_cast< QString*>(_v)); break;
        case 2: setShcode(*reinterpret_cast< QString*>(_v)); break;
        case 3: setPricejisu(*reinterpret_cast< float*>(_v)); break;
        case 4: setSign(*reinterpret_cast< QString*>(_v)); break;
        case 5: setChange(*reinterpret_cast< float*>(_v)); break;
        case 6: setJdiff(*reinterpret_cast< float*>(_v)); break;
        default: break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
