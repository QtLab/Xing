/****************************************************************************
** Meta object code from reading C++ file 'xareal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../XingLib/xareal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xareal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_XAReal_t {
    QByteArrayData data[18];
    char stringdata[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XAReal_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XAReal_t qt_meta_stringdata_XAReal = {
    {
QT_MOC_LITERAL(0, 0, 6), // "XAReal"
QT_MOC_LITERAL(1, 7, 15), // "ReceiveRealData"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "szTrCode"
QT_MOC_LITERAL(4, 33, 9), // "exception"
QT_MOC_LITERAL(5, 43, 4), // "code"
QT_MOC_LITERAL(6, 48, 6), // "source"
QT_MOC_LITERAL(7, 55, 4), // "disc"
QT_MOC_LITERAL(8, 60, 4), // "help"
QT_MOC_LITERAL(9, 65, 15), // "propertyChanged"
QT_MOC_LITERAL(10, 81, 4), // "name"
QT_MOC_LITERAL(11, 86, 6), // "signal"
QT_MOC_LITERAL(12, 93, 4), // "argc"
QT_MOC_LITERAL(13, 98, 4), // "argv"
QT_MOC_LITERAL(14, 103, 17), // "onReceiveRealData"
QT_MOC_LITERAL(15, 121, 11), // "onException"
QT_MOC_LITERAL(16, 133, 17), // "onPropertyChanged"
QT_MOC_LITERAL(17, 151, 8) // "onSignal"

    },
    "XAReal\0ReceiveRealData\0\0szTrCode\0"
    "exception\0code\0source\0disc\0help\0"
    "propertyChanged\0name\0signal\0argc\0argv\0"
    "onReceiveRealData\0onException\0"
    "onPropertyChanged\0onSignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XAReal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    4,   57,    2, 0x06 /* Public */,
       9,    1,   66,    2, 0x06 /* Public */,
      11,    3,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,   76,    2, 0x08 /* Private */,
      15,    4,   79,    2, 0x08 /* Private */,
      16,    1,   88,    2, 0x08 /* Private */,
      17,    3,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::VoidStar,   10,   12,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::VoidStar,   10,   12,   13,

       0        // eod
};

void XAReal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XAReal *_t = static_cast<XAReal *>(_o);
        switch (_id) {
        case 0: _t->ReceiveRealData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->exception((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 2: _t->propertyChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->signal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< void*(*)>(_a[3]))); break;
        case 4: _t->onReceiveRealData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onException((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 6: _t->onPropertyChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->onSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< void*(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (XAReal::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XAReal::ReceiveRealData)) {
                *result = 0;
            }
        }
        {
            typedef void (XAReal::*_t)(int , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XAReal::exception)) {
                *result = 1;
            }
        }
        {
            typedef void (XAReal::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XAReal::propertyChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (XAReal::*_t)(const QString & , int , void * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XAReal::signal)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject XAReal::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_XAReal.data,
      qt_meta_data_XAReal,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XAReal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XAReal::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XAReal.stringdata))
        return static_cast<void*>(const_cast< XAReal*>(this));
    return QObject::qt_metacast(_clname);
}

int XAReal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void XAReal::ReceiveRealData(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void XAReal::exception(int _t1, const QString & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void XAReal::propertyChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void XAReal::signal(const QString & _t1, int _t2, void * _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
