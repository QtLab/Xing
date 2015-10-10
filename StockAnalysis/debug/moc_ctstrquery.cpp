/****************************************************************************
** Meta object code from reading C++ file 'ctstrquery.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tr/ctstrquery.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ctstrquery.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CtsTrQuery_t {
    QByteArrayData data[5];
    char stringdata[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CtsTrQuery_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CtsTrQuery_t qt_meta_stringdata_CtsTrQuery = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CtsTrQuery"
QT_MOC_LITERAL(1, 11, 13), // "onReceiveData"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 6), // "trCode"
QT_MOC_LITERAL(4, 33, 22) // "onReceiveChartRealData"

    },
    "CtsTrQuery\0onReceiveData\0\0trCode\0"
    "onReceiveChartRealData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CtsTrQuery[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
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

       0        // eod
};

void CtsTrQuery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CtsTrQuery *_t = static_cast<CtsTrQuery *>(_o);
        switch (_id) {
        case 0: _t->onReceiveData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onReceiveChartRealData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CtsTrQuery::staticMetaObject = {
    { &TrQuery::staticMetaObject, qt_meta_stringdata_CtsTrQuery.data,
      qt_meta_data_CtsTrQuery,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CtsTrQuery::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CtsTrQuery::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CtsTrQuery.stringdata))
        return static_cast<void*>(const_cast< CtsTrQuery*>(this));
    return TrQuery::qt_metacast(_clname);
}

int CtsTrQuery::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}
QT_END_MOC_NAMESPACE
