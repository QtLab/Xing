/****************************************************************************
** Meta object code from reading C++ file 't1702query.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tr/t1702/t1702query.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 't1702query.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_T1702Query_t {
    QByteArrayData data[12];
    char stringdata[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_T1702Query_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_T1702Query_t qt_meta_stringdata_T1702Query = {
    {
QT_MOC_LITERAL(0, 0, 10), // "T1702Query"
QT_MOC_LITERAL(1, 11, 13), // "onReceiveData"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 6), // "trCode"
QT_MOC_LITERAL(4, 33, 22), // "onReceiveChartRealData"
QT_MOC_LITERAL(5, 56, 6), // "shcode"
QT_MOC_LITERAL(6, 63, 4), // "todt"
QT_MOC_LITERAL(7, 68, 8), // "volvalgb"
QT_MOC_LITERAL(8, 77, 6), // "msmdgb"
QT_MOC_LITERAL(9, 84, 7), // "cumulgb"
QT_MOC_LITERAL(10, 92, 7), // "cts_idx"
QT_MOC_LITERAL(11, 100, 8) // "cts_date"

    },
    "T1702Query\0onReceiveData\0\0trCode\0"
    "onReceiveChartRealData\0shcode\0todt\0"
    "volvalgb\0msmdgb\0cumulgb\0cts_idx\0"
    "cts_date"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_T1702Query[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       7,   30, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       4,    1,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // properties: name, type, flags
       5, QMetaType::QString, 0x00095003,
       6, QMetaType::QDate, 0x00095003,
       7, QMetaType::QString, 0x00095003,
       8, QMetaType::QString, 0x00095003,
       9, QMetaType::QString, 0x00095003,
      10, QMetaType::Long, 0x00095003,
      11, QMetaType::QString, 0x00095003,

       0        // eod
};

void T1702Query::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        T1702Query *_t = static_cast<T1702Query *>(_o);
        switch (_id) {
        case 0: _t->onReceiveData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onReceiveChartRealData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject T1702Query::staticMetaObject = {
    { &TrQuery::staticMetaObject, qt_meta_stringdata_T1702Query.data,
      qt_meta_data_T1702Query,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *T1702Query::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *T1702Query::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_T1702Query.stringdata))
        return static_cast<void*>(const_cast< T1702Query*>(this));
    return TrQuery::qt_metacast(_clname);
}

int T1702Query::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TrQuery::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = shcode(); break;
        case 1: *reinterpret_cast< QDate*>(_v) = todt(); break;
        case 2: *reinterpret_cast< QString*>(_v) = volvalgb(); break;
        case 3: *reinterpret_cast< QString*>(_v) = msmdgb(); break;
        case 4: *reinterpret_cast< QString*>(_v) = cumulgb(); break;
        case 5: *reinterpret_cast< long*>(_v) = cts_idx(); break;
        case 6: *reinterpret_cast< QString*>(_v) = cts_date(); break;
        default: break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_shcode != *reinterpret_cast< QString*>(_v)) {
                _shcode = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 1:
            if (_todt != *reinterpret_cast< QDate*>(_v)) {
                _todt = *reinterpret_cast< QDate*>(_v);
            }
            break;
        case 2:
            if (_volvalgb != *reinterpret_cast< QString*>(_v)) {
                _volvalgb = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 3:
            if (_msmdgb != *reinterpret_cast< QString*>(_v)) {
                _msmdgb = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 4:
            if (_cumulgb != *reinterpret_cast< QString*>(_v)) {
                _cumulgb = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 5:
            if (_cts_idx != *reinterpret_cast< long*>(_v)) {
                _cts_idx = *reinterpret_cast< long*>(_v);
            }
            break;
        case 6:
            if (_cts_date != *reinterpret_cast< QString*>(_v)) {
                _cts_date = *reinterpret_cast< QString*>(_v);
            }
            break;
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
