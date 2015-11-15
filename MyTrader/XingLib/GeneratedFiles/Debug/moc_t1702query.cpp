/****************************************************************************
** Meta object code from reading C++ file 't1702query.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Src/core/tr/t1702/t1702query.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 't1702query.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_T1702Query_t {
    QByteArrayData data[11];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_T1702Query_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_T1702Query_t qt_meta_stringdata_T1702Query = {
    {
QT_MOC_LITERAL(0, 0, 10), // "T1702Query"
QT_MOC_LITERAL(1, 11, 13), // "onReceiveData"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 6), // "trCode"
QT_MOC_LITERAL(4, 33, 6), // "shcode"
QT_MOC_LITERAL(5, 40, 4), // "todt"
QT_MOC_LITERAL(6, 45, 8), // "volvalgb"
QT_MOC_LITERAL(7, 54, 6), // "msmdgb"
QT_MOC_LITERAL(8, 61, 7), // "cumulgb"
QT_MOC_LITERAL(9, 69, 7), // "cts_idx"
QT_MOC_LITERAL(10, 77, 8) // "cts_date"

    },
    "T1702Query\0onReceiveData\0\0trCode\0"
    "shcode\0todt\0volvalgb\0msmdgb\0cumulgb\0"
    "cts_idx\0cts_date"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_T1702Query[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       7,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // properties: name, type, flags
       4, QMetaType::QString, 0x00095003,
       5, QMetaType::QDate, 0x00095003,
       6, QMetaType::QString, 0x00095003,
       7, QMetaType::QString, 0x00095003,
       8, QMetaType::QString, 0x00095003,
       9, QMetaType::Long, 0x00095003,
      10, QMetaType::QString, 0x00095003,

       0        // eod
};

void T1702Query::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        T1702Query *_t = static_cast<T1702Query *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onReceiveData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        T1702Query *_t = static_cast<T1702Query *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->shcode(); break;
        case 1: *reinterpret_cast< QDate*>(_v) = _t->todt(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->volvalgb(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->msmdgb(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->cumulgb(); break;
        case 5: *reinterpret_cast< long*>(_v) = _t->cts_idx(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->cts_date(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        T1702Query *_t = static_cast<T1702Query *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->_shcode != *reinterpret_cast< QString*>(_v)) {
                _t->_shcode = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 1:
            if (_t->_todt != *reinterpret_cast< QDate*>(_v)) {
                _t->_todt = *reinterpret_cast< QDate*>(_v);
            }
            break;
        case 2:
            if (_t->_volvalgb != *reinterpret_cast< QString*>(_v)) {
                _t->_volvalgb = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 3:
            if (_t->_msmdgb != *reinterpret_cast< QString*>(_v)) {
                _t->_msmdgb = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 4:
            if (_t->_cumulgb != *reinterpret_cast< QString*>(_v)) {
                _t->_cumulgb = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 5:
            if (_t->_cts_idx != *reinterpret_cast< long*>(_v)) {
                _t->_cts_idx = *reinterpret_cast< long*>(_v);
            }
            break;
        case 6:
            if (_t->_cts_date != *reinterpret_cast< QString*>(_v)) {
                _t->_cts_date = *reinterpret_cast< QString*>(_v);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject T1702Query::staticMetaObject = {
    { &CtsTrQuery::staticMetaObject, qt_meta_stringdata_T1702Query.data,
      qt_meta_data_T1702Query,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *T1702Query::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *T1702Query::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_T1702Query.stringdata0))
        return static_cast<void*>(const_cast< T1702Query*>(this));
    return CtsTrQuery::qt_metacast(_clname);
}

int T1702Query::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CtsTrQuery::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
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
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
