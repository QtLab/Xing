/****************************************************************************
** Meta object code from reading C++ file 't8413query.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Src/core/tr/t8413/t8413query.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 't8413query.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_T8413Query_t {
    QByteArrayData data[23];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_T8413Query_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_T8413Query_t qt_meta_stringdata_T8413Query = {
    {
QT_MOC_LITERAL(0, 0, 10), // "T8413Query"
QT_MOC_LITERAL(1, 11, 5), // "edate"
QT_MOC_LITERAL(2, 17, 6), // "s_time"
QT_MOC_LITERAL(3, 24, 6), // "e_time"
QT_MOC_LITERAL(4, 31, 6), // "lowend"
QT_MOC_LITERAL(5, 38, 8), // "cts_date"
QT_MOC_LITERAL(6, 47, 8), // "jivolume"
QT_MOC_LITERAL(7, 56, 6), // "dshmin"
QT_MOC_LITERAL(8, 63, 6), // "dihigh"
QT_MOC_LITERAL(9, 70, 7), // "highend"
QT_MOC_LITERAL(10, 78, 7), // "comp_yn"
QT_MOC_LITERAL(11, 86, 5), // "gubun"
QT_MOC_LITERAL(12, 92, 6), // "disiga"
QT_MOC_LITERAL(13, 99, 7), // "jiclose"
QT_MOC_LITERAL(14, 107, 5), // "dilow"
QT_MOC_LITERAL(15, 113, 6), // "qrycnt"
QT_MOC_LITERAL(16, 120, 6), // "jisiga"
QT_MOC_LITERAL(17, 127, 7), // "diclose"
QT_MOC_LITERAL(18, 135, 6), // "jihigh"
QT_MOC_LITERAL(19, 142, 5), // "jilow"
QT_MOC_LITERAL(20, 148, 9), // "rec_count"
QT_MOC_LITERAL(21, 158, 6), // "shcode"
QT_MOC_LITERAL(22, 165, 5) // "sdate"

    },
    "T8413Query\0edate\0s_time\0e_time\0lowend\0"
    "cts_date\0jivolume\0dshmin\0dihigh\0highend\0"
    "comp_yn\0gubun\0disiga\0jiclose\0dilow\0"
    "qrycnt\0jisiga\0diclose\0jihigh\0jilow\0"
    "rec_count\0shcode\0sdate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_T8413Query[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      22,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QDate, 0x00095103,
       2, QMetaType::QString, 0x00095003,
       3, QMetaType::QString, 0x00095003,
       4, QMetaType::Long, 0x00095103,
       5, QMetaType::QDate, 0x00095003,
       6, QMetaType::Long, 0x00095103,
       7, QMetaType::QString, 0x00095103,
       8, QMetaType::Long, 0x00095103,
       9, QMetaType::Long, 0x00095103,
      10, QMetaType::QString, 0x00095003,
      11, QMetaType::QString, 0x00095103,
      12, QMetaType::Long, 0x00095103,
      13, QMetaType::Long, 0x00095103,
      14, QMetaType::Long, 0x00095103,
      15, QMetaType::Long, 0x00095103,
      16, QMetaType::Long, 0x00095103,
      17, QMetaType::Long, 0x00095103,
      18, QMetaType::Long, 0x00095103,
      19, QMetaType::Long, 0x00095103,
      20, QMetaType::Long, 0x00095003,
      21, QMetaType::QString, 0x00095103,
      22, QMetaType::QDate, 0x00095103,

       0        // eod
};

void T8413Query::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        T8413Query *_t = static_cast<T8413Query *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QDate*>(_v) = _t->edate(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->s_time(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->e_time(); break;
        case 3: *reinterpret_cast< long*>(_v) = _t->lowend(); break;
        case 4: *reinterpret_cast< QDate*>(_v) = _t->cts_date(); break;
        case 5: *reinterpret_cast< long*>(_v) = _t->jivolume(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->dshmin(); break;
        case 7: *reinterpret_cast< long*>(_v) = _t->dihigh(); break;
        case 8: *reinterpret_cast< long*>(_v) = _t->highend(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->comp_yn(); break;
        case 10: *reinterpret_cast< QString*>(_v) = _t->gubun(); break;
        case 11: *reinterpret_cast< long*>(_v) = _t->disiga(); break;
        case 12: *reinterpret_cast< long*>(_v) = _t->jiclose(); break;
        case 13: *reinterpret_cast< long*>(_v) = _t->dilow(); break;
        case 14: *reinterpret_cast< long*>(_v) = _t->qrycnt(); break;
        case 15: *reinterpret_cast< long*>(_v) = _t->jisiga(); break;
        case 16: *reinterpret_cast< long*>(_v) = _t->diclose(); break;
        case 17: *reinterpret_cast< long*>(_v) = _t->jihigh(); break;
        case 18: *reinterpret_cast< long*>(_v) = _t->jilow(); break;
        case 19: *reinterpret_cast< long*>(_v) = _t->rec_count(); break;
        case 20: *reinterpret_cast< QString*>(_v) = _t->shcode(); break;
        case 21: *reinterpret_cast< QDate*>(_v) = _t->sdate(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        T8413Query *_t = static_cast<T8413Query *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setEdate(*reinterpret_cast< QDate*>(_v)); break;
        case 1: _t->setS_Time(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setE_Time(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setLowend(*reinterpret_cast< long*>(_v)); break;
        case 4: _t->setCts_Date(*reinterpret_cast< QDate*>(_v)); break;
        case 5: _t->setJivolume(*reinterpret_cast< long*>(_v)); break;
        case 6: _t->setDshmin(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setDihigh(*reinterpret_cast< long*>(_v)); break;
        case 8: _t->setHighend(*reinterpret_cast< long*>(_v)); break;
        case 9: _t->setComp_Yn(*reinterpret_cast< QString*>(_v)); break;
        case 10: _t->setGubun(*reinterpret_cast< QString*>(_v)); break;
        case 11: _t->setDisiga(*reinterpret_cast< long*>(_v)); break;
        case 12: _t->setJiclose(*reinterpret_cast< long*>(_v)); break;
        case 13: _t->setDilow(*reinterpret_cast< long*>(_v)); break;
        case 14: _t->setQrycnt(*reinterpret_cast< long*>(_v)); break;
        case 15: _t->setJisiga(*reinterpret_cast< long*>(_v)); break;
        case 16: _t->setDiclose(*reinterpret_cast< long*>(_v)); break;
        case 17: _t->setJihigh(*reinterpret_cast< long*>(_v)); break;
        case 18: _t->setJilow(*reinterpret_cast< long*>(_v)); break;
        case 19: _t->setRec_Count(*reinterpret_cast< long*>(_v)); break;
        case 20: _t->setShcode(*reinterpret_cast< QString*>(_v)); break;
        case 21: _t->setSdate(*reinterpret_cast< QDate*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject T8413Query::staticMetaObject = {
    { &CtsTrQuery::staticMetaObject, qt_meta_stringdata_T8413Query.data,
      qt_meta_data_T8413Query,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *T8413Query::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *T8413Query::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_T8413Query.stringdata0))
        return static_cast<void*>(const_cast< T8413Query*>(this));
    return CtsTrQuery::qt_metacast(_clname);
}

int T8413Query::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CtsTrQuery::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 22;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 22;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 22;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 22;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 22;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
