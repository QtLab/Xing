/****************************************************************************
** Meta object code from reading C++ file 'UpjongCodeUpdater.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../function/info/UpjongCodeUpdater.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UpjongCodeUpdater.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UpjongCodeUpdater_t {
    QByteArrayData data[6];
    char stringdata[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UpjongCodeUpdater_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UpjongCodeUpdater_t qt_meta_stringdata_UpjongCodeUpdater = {
    {
QT_MOC_LITERAL(0, 0, 17), // "UpjongCodeUpdater"
QT_MOC_LITERAL(1, 18, 20), // "updateUpjongCodeDone"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 16), // "updateUpjongCode"
QT_MOC_LITERAL(4, 57, 14), // "t8424QueryDone"
QT_MOC_LITERAL(5, 72, 14) // "t1516QueryDone"

    },
    "UpjongCodeUpdater\0updateUpjongCodeDone\0"
    "\0updateUpjongCode\0t8424QueryDone\0"
    "t1516QueryDone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UpjongCodeUpdater[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UpjongCodeUpdater::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UpjongCodeUpdater *_t = static_cast<UpjongCodeUpdater *>(_o);
        switch (_id) {
        case 0: _t->updateUpjongCodeDone(); break;
        case 1: _t->updateUpjongCode(); break;
        case 2: _t->t8424QueryDone(); break;
        case 3: _t->t1516QueryDone(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UpjongCodeUpdater::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UpjongCodeUpdater::updateUpjongCodeDone)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject UpjongCodeUpdater::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UpjongCodeUpdater.data,
      qt_meta_data_UpjongCodeUpdater,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UpjongCodeUpdater::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UpjongCodeUpdater::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UpjongCodeUpdater.stringdata))
        return static_cast<void*>(const_cast< UpjongCodeUpdater*>(this));
    return QObject::qt_metacast(_clname);
}

int UpjongCodeUpdater::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void UpjongCodeUpdater::updateUpjongCodeDone()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
