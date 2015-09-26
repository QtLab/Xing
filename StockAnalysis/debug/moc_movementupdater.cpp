/****************************************************************************
** Meta object code from reading C++ file 'movementupdater.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../updater/movementupdater.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'movementupdater.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MovementUpdater_t {
    QByteArrayData data[13];
    char stringdata[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MovementUpdater_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MovementUpdater_t qt_meta_stringdata_MovementUpdater = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MovementUpdater"
QT_MOC_LITERAL(1, 16, 10), // "updateDone"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "updateByShcode"
QT_MOC_LITERAL(4, 43, 6), // "shcode"
QT_MOC_LITERAL(5, 50, 18), // "updateByShcodeList"
QT_MOC_LITERAL(6, 69, 14), // "QList<QString>"
QT_MOC_LITERAL(7, 84, 10), // "shcodeList"
QT_MOC_LITERAL(8, 95, 14), // "updateByUpcode"
QT_MOC_LITERAL(9, 110, 6), // "upcode"
QT_MOC_LITERAL(10, 117, 14), // "t1702QueryDone"
QT_MOC_LITERAL(11, 132, 14), // "t1516QueryDone"
QT_MOC_LITERAL(12, 147, 11) // "updateStart"

    },
    "MovementUpdater\0updateDone\0\0updateByShcode\0"
    "shcode\0updateByShcodeList\0QList<QString>\0"
    "shcodeList\0updateByUpcode\0upcode\0"
    "t1702QueryDone\0t1516QueryDone\0updateStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MovementUpdater[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   50,    2, 0x0a /* Public */,
       5,    1,   53,    2, 0x0a /* Public */,
       8,    1,   56,    2, 0x0a /* Public */,
      10,    0,   59,    2, 0x0a /* Public */,
      11,    0,   60,    2, 0x0a /* Public */,
      12,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MovementUpdater::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MovementUpdater *_t = static_cast<MovementUpdater *>(_o);
        switch (_id) {
        case 0: _t->updateDone(); break;
        case 1: _t->updateByShcode((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->updateByShcodeList((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 3: _t->updateByUpcode((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->t1702QueryDone(); break;
        case 5: _t->t1516QueryDone(); break;
        case 6: _t->updateStart(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MovementUpdater::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MovementUpdater::updateDone)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MovementUpdater::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MovementUpdater.data,
      qt_meta_data_MovementUpdater,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MovementUpdater::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MovementUpdater::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MovementUpdater.stringdata))
        return static_cast<void*>(const_cast< MovementUpdater*>(this));
    return QObject::qt_metacast(_clname);
}

int MovementUpdater::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MovementUpdater::updateDone()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
