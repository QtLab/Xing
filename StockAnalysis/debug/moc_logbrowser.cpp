/****************************************************************************
** Meta object code from reading C++ file 'logbrowser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../util/logbrowser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logbrowser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LogBrowser_t {
    QByteArrayData data[10];
    char stringdata[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LogBrowser_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LogBrowser_t qt_meta_stringdata_LogBrowser = {
    {
QT_MOC_LITERAL(0, 0, 10), // "LogBrowser"
QT_MOC_LITERAL(1, 11, 11), // "sendMessage"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "QtMsgType"
QT_MOC_LITERAL(4, 34, 4), // "type"
QT_MOC_LITERAL(5, 39, 10), // "LogContext"
QT_MOC_LITERAL(6, 50, 7), // "context"
QT_MOC_LITERAL(7, 58, 3), // "msg"
QT_MOC_LITERAL(8, 62, 13), // "outputMessage"
QT_MOC_LITERAL(9, 76, 18) // "QMessageLogContext"

    },
    "LogBrowser\0sendMessage\0\0QtMsgType\0"
    "type\0LogContext\0context\0msg\0outputMessage\0"
    "QMessageLogContext"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogBrowser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    3,   31,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QString,    4,    6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 9, QMetaType::QString,    4,    6,    7,

       0        // eod
};

void LogBrowser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LogBrowser *_t = static_cast<LogBrowser *>(_o);
        switch (_id) {
        case 0: _t->sendMessage((*reinterpret_cast< QtMsgType(*)>(_a[1])),(*reinterpret_cast< const LogContext(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->outputMessage((*reinterpret_cast< QtMsgType(*)>(_a[1])),(*reinterpret_cast< const QMessageLogContext(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LogBrowser::*_t)(QtMsgType , const LogContext & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogBrowser::sendMessage)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject LogBrowser::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LogBrowser.data,
      qt_meta_data_LogBrowser,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LogBrowser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogBrowser::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LogBrowser.stringdata))
        return static_cast<void*>(const_cast< LogBrowser*>(this));
    return QObject::qt_metacast(_clname);
}

int LogBrowser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void LogBrowser::sendMessage(QtMsgType _t1, const LogContext & _t2, const QString & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
