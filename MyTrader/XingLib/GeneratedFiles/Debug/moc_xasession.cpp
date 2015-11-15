/****************************************************************************
** Meta object code from reading C++ file 'xasession.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Src/core/xing/xasession.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xasession.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_XASession_t {
    QByteArrayData data[24];
    char stringdata0[270];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XASession_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XASession_t qt_meta_stringdata_XASession = {
    {
QT_MOC_LITERAL(0, 0, 9), // "XASession"
QT_MOC_LITERAL(1, 10, 7), // "onLogin"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 6), // "szCode"
QT_MOC_LITERAL(4, 26, 5), // "szMsg"
QT_MOC_LITERAL(5, 32, 8), // "onLogout"
QT_MOC_LITERAL(6, 41, 12), // "onDisconnect"
QT_MOC_LITERAL(7, 54, 14), // "ReportEventLog"
QT_MOC_LITERAL(8, 69, 4), // "Init"
QT_MOC_LITERAL(9, 74, 13), // "ConnectServer"
QT_MOC_LITERAL(10, 88, 12), // "toDemoServer"
QT_MOC_LITERAL(11, 101, 16), // "DisconnectServer"
QT_MOC_LITERAL(12, 118, 5), // "Login"
QT_MOC_LITERAL(13, 124, 4), // "szID"
QT_MOC_LITERAL(14, 129, 5), // "szPwd"
QT_MOC_LITERAL(15, 135, 9), // "szCertPwd"
QT_MOC_LITERAL(16, 145, 11), // "nServerType"
QT_MOC_LITERAL(17, 157, 15), // "bShowCertErrDlg"
QT_MOC_LITERAL(18, 173, 6), // "Logout"
QT_MOC_LITERAL(19, 180, 17), // "SetConnectTimeOut"
QT_MOC_LITERAL(20, 198, 14), // "ConnectTimeOut"
QT_MOC_LITERAL(21, 213, 17), // "SetSendPacketSize"
QT_MOC_LITERAL(22, 231, 14), // "SendPacketSize"
QT_MOC_LITERAL(23, 246, 23) // "ReportXASessionEventLog"

    },
    "XASession\0onLogin\0\0szCode\0szMsg\0"
    "onLogout\0onDisconnect\0ReportEventLog\0"
    "Init\0ConnectServer\0toDemoServer\0"
    "DisconnectServer\0Login\0szID\0szPwd\0"
    "szCertPwd\0nServerType\0bShowCertErrDlg\0"
    "Logout\0SetConnectTimeOut\0ConnectTimeOut\0"
    "SetSendPacketSize\0SendPacketSize\0"
    "ReportXASessionEventLog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XASession[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       5,    0,   89,    2, 0x06 /* Public */,
       6,    0,   90,    2, 0x06 /* Public */,
       7,    1,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   94,    2, 0x0a /* Public */,
       9,    1,   95,    2, 0x0a /* Public */,
      11,    0,   98,    2, 0x0a /* Public */,
      12,    5,   99,    2, 0x0a /* Public */,
      12,    4,  110,    2, 0x2a /* Public | MethodCloned */,
      12,    3,  119,    2, 0x2a /* Public | MethodCloned */,
      18,    0,  126,    2, 0x0a /* Public */,
      19,    1,  127,    2, 0x0a /* Public */,
      21,    1,  130,    2, 0x0a /* Public */,
      23,    1,  133,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Bool,   13,   14,   15,   16,   17,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,   13,   14,   15,   16,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString,   13,   14,   15,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void XASession::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XASession *_t = static_cast<XASession *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onLogin((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->onLogout(); break;
        case 2: _t->onDisconnect(); break;
        case 3: _t->ReportEventLog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: { bool _r = _t->Init();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->ConnectServer((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->DisconnectServer(); break;
        case 7: { bool _r = _t->Login((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = _t->Login((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { bool _r = _t->Login((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { bool _r = _t->Logout();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: _t->SetConnectTimeOut((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->SetSendPacketSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->ReportXASessionEventLog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (XASession::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XASession::onLogin)) {
                *result = 0;
            }
        }
        {
            typedef void (XASession::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XASession::onLogout)) {
                *result = 1;
            }
        }
        {
            typedef void (XASession::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XASession::onDisconnect)) {
                *result = 2;
            }
        }
        {
            typedef void (XASession::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XASession::ReportEventLog)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject XASession::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_XASession.data,
      qt_meta_data_XASession,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XASession::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XASession::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XASession.stringdata0))
        return static_cast<void*>(const_cast< XASession*>(this));
    return QObject::qt_metacast(_clname);
}

int XASession::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void XASession::onLogin(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void XASession::onLogout()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void XASession::onDisconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void XASession::ReportEventLog(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
