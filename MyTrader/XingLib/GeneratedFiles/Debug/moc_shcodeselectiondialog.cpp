/****************************************************************************
** Meta object code from reading C++ file 'shcodeselectiondialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Src/common/ui/shcodeselectiondialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shcodeselectiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ShcodeSelectionDialog_t {
    QByteArrayData data[18];
    char stringdata0[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShcodeSelectionDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShcodeSelectionDialog_t qt_meta_stringdata_ShcodeSelectionDialog = {
    {
QT_MOC_LITERAL(0, 0, 21), // "ShcodeSelectionDialog"
QT_MOC_LITERAL(1, 22, 14), // "shcodeSelected"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 6), // "shcode"
QT_MOC_LITERAL(4, 45, 14), // "upcodeSelected"
QT_MOC_LITERAL(5, 60, 6), // "upcode"
QT_MOC_LITERAL(6, 67, 12), // "onBtnToggled"
QT_MOC_LITERAL(7, 80, 2), // "id"
QT_MOC_LITERAL(8, 83, 7), // "toggled"
QT_MOC_LITERAL(9, 91, 24), // "onShowShcodeListByUpjong"
QT_MOC_LITERAL(10, 116, 6), // "upjong"
QT_MOC_LITERAL(11, 123, 32), // "onShowUpjongCodeListByUpjongType"
QT_MOC_LITERAL(12, 156, 11), // "UPJONG_TYPE"
QT_MOC_LITERAL(13, 168, 10), // "upjongType"
QT_MOC_LITERAL(14, 179, 18), // "onTableViewClicked"
QT_MOC_LITERAL(15, 198, 5), // "index"
QT_MOC_LITERAL(16, 204, 17), // "onSearchCompleted"
QT_MOC_LITERAL(17, 222, 11) // "onSearching"

    },
    "ShcodeSelectionDialog\0shcodeSelected\0"
    "\0shcode\0upcodeSelected\0upcode\0"
    "onBtnToggled\0id\0toggled\0"
    "onShowShcodeListByUpjong\0upjong\0"
    "onShowUpjongCodeListByUpjongType\0"
    "UPJONG_TYPE\0upjongType\0onTableViewClicked\0"
    "index\0onSearchCompleted\0onSearching"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShcodeSelectionDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   60,    2, 0x08 /* Private */,
       9,    1,   65,    2, 0x08 /* Private */,
      11,    1,   68,    2, 0x08 /* Private */,
      14,    1,   71,    2, 0x0a /* Public */,
      16,    1,   74,    2, 0x0a /* Public */,
      17,    1,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::QModelIndex,   15,
    QMetaType::Void, QMetaType::QModelIndex,   15,
    QMetaType::Void, QMetaType::QModelIndex,   15,

       0        // eod
};

void ShcodeSelectionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ShcodeSelectionDialog *_t = static_cast<ShcodeSelectionDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->shcodeSelected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->upcodeSelected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onBtnToggled((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->onShowShcodeListByUpjong((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onShowUpjongCodeListByUpjongType((*reinterpret_cast< const UPJONG_TYPE(*)>(_a[1]))); break;
        case 5: _t->onTableViewClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->onSearchCompleted((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->onSearching((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ShcodeSelectionDialog::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ShcodeSelectionDialog::shcodeSelected)) {
                *result = 0;
            }
        }
        {
            typedef void (ShcodeSelectionDialog::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ShcodeSelectionDialog::upcodeSelected)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ShcodeSelectionDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ShcodeSelectionDialog.data,
      qt_meta_data_ShcodeSelectionDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ShcodeSelectionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShcodeSelectionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ShcodeSelectionDialog.stringdata0))
        return static_cast<void*>(const_cast< ShcodeSelectionDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ShcodeSelectionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void ShcodeSelectionDialog::shcodeSelected(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ShcodeSelectionDialog::upcodeSelected(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
