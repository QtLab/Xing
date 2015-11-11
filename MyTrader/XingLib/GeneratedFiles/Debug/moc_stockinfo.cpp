/****************************************************************************
** Meta object code from reading C++ file 'stockinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Src/common/type/stockinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stockinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StockInfo_t {
    QByteArrayData data[158];
    char stringdata[1242];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StockInfo_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StockInfo_t qt_meta_stringdata_StockInfo = {
    {
QT_MOC_LITERAL(0, 0, 9), // "StockInfo"
QT_MOC_LITERAL(1, 10, 5), // "hname"
QT_MOC_LITERAL(2, 16, 7), // "expcode"
QT_MOC_LITERAL(3, 24, 5), // "isETF"
QT_MOC_LITERAL(4, 30, 7), // "isKOSPI"
QT_MOC_LITERAL(5, 38, 5), // "price"
QT_MOC_LITERAL(6, 44, 4), // "sign"
QT_MOC_LITERAL(7, 49, 6), // "change"
QT_MOC_LITERAL(8, 56, 4), // "diff"
QT_MOC_LITERAL(9, 61, 6), // "volume"
QT_MOC_LITERAL(10, 68, 8), // "recprice"
QT_MOC_LITERAL(11, 77, 3), // "avg"
QT_MOC_LITERAL(12, 81, 10), // "uplmtprice"
QT_MOC_LITERAL(13, 92, 10), // "dnlmtprice"
QT_MOC_LITERAL(14, 103, 10), // "jnilvolume"
QT_MOC_LITERAL(15, 114, 10), // "volumediff"
QT_MOC_LITERAL(16, 125, 4), // "open"
QT_MOC_LITERAL(17, 130, 8), // "opentime"
QT_MOC_LITERAL(18, 139, 4), // "high"
QT_MOC_LITERAL(19, 144, 8), // "hightime"
QT_MOC_LITERAL(20, 153, 3), // "low"
QT_MOC_LITERAL(21, 157, 7), // "lowtime"
QT_MOC_LITERAL(22, 165, 7), // "high52w"
QT_MOC_LITERAL(23, 173, 11), // "high52wdate"
QT_MOC_LITERAL(24, 185, 6), // "low52w"
QT_MOC_LITERAL(25, 192, 10), // "low52wdate"
QT_MOC_LITERAL(26, 203, 8), // "exhratio"
QT_MOC_LITERAL(27, 212, 3), // "per"
QT_MOC_LITERAL(28, 216, 4), // "pbrx"
QT_MOC_LITERAL(29, 221, 7), // "listing"
QT_MOC_LITERAL(30, 229, 6), // "jkrate"
QT_MOC_LITERAL(31, 236, 7), // "memedan"
QT_MOC_LITERAL(32, 244, 10), // "offernocd1"
QT_MOC_LITERAL(33, 255, 8), // "bidnocd1"
QT_MOC_LITERAL(34, 264, 8), // "offerno1"
QT_MOC_LITERAL(35, 273, 6), // "bidno1"
QT_MOC_LITERAL(36, 280, 5), // "dvol1"
QT_MOC_LITERAL(37, 286, 5), // "svol1"
QT_MOC_LITERAL(38, 292, 5), // "dcha1"
QT_MOC_LITERAL(39, 298, 5), // "scha1"
QT_MOC_LITERAL(40, 304, 6), // "ddiff1"
QT_MOC_LITERAL(41, 311, 6), // "sdiff1"
QT_MOC_LITERAL(42, 318, 10), // "offernocd2"
QT_MOC_LITERAL(43, 329, 8), // "bidnocd2"
QT_MOC_LITERAL(44, 338, 8), // "offerno2"
QT_MOC_LITERAL(45, 347, 6), // "bidno2"
QT_MOC_LITERAL(46, 354, 5), // "dvol2"
QT_MOC_LITERAL(47, 360, 5), // "svol2"
QT_MOC_LITERAL(48, 366, 5), // "dcha2"
QT_MOC_LITERAL(49, 372, 5), // "scha2"
QT_MOC_LITERAL(50, 378, 6), // "ddiff2"
QT_MOC_LITERAL(51, 385, 6), // "sdiff2"
QT_MOC_LITERAL(52, 392, 10), // "offernocd3"
QT_MOC_LITERAL(53, 403, 8), // "bidnocd3"
QT_MOC_LITERAL(54, 412, 8), // "offerno3"
QT_MOC_LITERAL(55, 421, 6), // "bidno3"
QT_MOC_LITERAL(56, 428, 5), // "dvol3"
QT_MOC_LITERAL(57, 434, 5), // "svol3"
QT_MOC_LITERAL(58, 440, 5), // "dcha3"
QT_MOC_LITERAL(59, 446, 5), // "scha3"
QT_MOC_LITERAL(60, 452, 6), // "ddiff3"
QT_MOC_LITERAL(61, 459, 6), // "sdiff3"
QT_MOC_LITERAL(62, 466, 10), // "offernocd4"
QT_MOC_LITERAL(63, 477, 8), // "bidnocd4"
QT_MOC_LITERAL(64, 486, 8), // "offerno4"
QT_MOC_LITERAL(65, 495, 6), // "bidno4"
QT_MOC_LITERAL(66, 502, 5), // "dvol4"
QT_MOC_LITERAL(67, 508, 5), // "svol4"
QT_MOC_LITERAL(68, 514, 5), // "dcha4"
QT_MOC_LITERAL(69, 520, 5), // "scha4"
QT_MOC_LITERAL(70, 526, 6), // "ddiff4"
QT_MOC_LITERAL(71, 533, 6), // "sdiff4"
QT_MOC_LITERAL(72, 540, 10), // "offernocd5"
QT_MOC_LITERAL(73, 551, 8), // "bidnocd5"
QT_MOC_LITERAL(74, 560, 8), // "offerno5"
QT_MOC_LITERAL(75, 569, 6), // "bidno5"
QT_MOC_LITERAL(76, 576, 5), // "dvol5"
QT_MOC_LITERAL(77, 582, 5), // "svol5"
QT_MOC_LITERAL(78, 588, 5), // "dcha5"
QT_MOC_LITERAL(79, 594, 5), // "scha5"
QT_MOC_LITERAL(80, 600, 6), // "ddiff5"
QT_MOC_LITERAL(81, 607, 6), // "sdiff5"
QT_MOC_LITERAL(82, 614, 5), // "fwdvl"
QT_MOC_LITERAL(83, 620, 10), // "ftradmdcha"
QT_MOC_LITERAL(84, 631, 11), // "ftradmddiff"
QT_MOC_LITERAL(85, 643, 5), // "fwsvl"
QT_MOC_LITERAL(86, 649, 10), // "ftradmscha"
QT_MOC_LITERAL(87, 660, 11), // "ftradmsdiff"
QT_MOC_LITERAL(88, 672, 3), // "vol"
QT_MOC_LITERAL(89, 676, 6), // "shcode"
QT_MOC_LITERAL(90, 683, 5), // "value"
QT_MOC_LITERAL(91, 689, 7), // "jvolume"
QT_MOC_LITERAL(92, 697, 8), // "highyear"
QT_MOC_LITERAL(93, 706, 12), // "highyeardate"
QT_MOC_LITERAL(94, 719, 7), // "lowyear"
QT_MOC_LITERAL(95, 727, 11), // "lowyeardate"
QT_MOC_LITERAL(96, 739, 6), // "target"
QT_MOC_LITERAL(97, 746, 7), // "capital"
QT_MOC_LITERAL(98, 754, 6), // "abscnt"
QT_MOC_LITERAL(99, 761, 8), // "parprice"
QT_MOC_LITERAL(100, 770, 4), // "gsmm"
QT_MOC_LITERAL(101, 775, 8), // "subprice"
QT_MOC_LITERAL(102, 784, 5), // "total"
QT_MOC_LITERAL(103, 790, 8), // "listdate"
QT_MOC_LITERAL(104, 799, 4), // "name"
QT_MOC_LITERAL(105, 804, 7), // "bfsales"
QT_MOC_LITERAL(106, 812, 17), // "bfoperatingincome"
QT_MOC_LITERAL(107, 830, 16), // "bfordinaryincome"
QT_MOC_LITERAL(108, 847, 11), // "bfnetincome"
QT_MOC_LITERAL(109, 859, 5), // "bfeps"
QT_MOC_LITERAL(110, 865, 5), // "name2"
QT_MOC_LITERAL(111, 871, 8), // "bfsales2"
QT_MOC_LITERAL(112, 880, 18), // "bfoperatingincome2"
QT_MOC_LITERAL(113, 899, 17), // "bfordinaryincome2"
QT_MOC_LITERAL(114, 917, 12), // "bfnetincome2"
QT_MOC_LITERAL(115, 930, 6), // "bfeps2"
QT_MOC_LITERAL(116, 937, 6), // "salert"
QT_MOC_LITERAL(117, 944, 5), // "opert"
QT_MOC_LITERAL(118, 950, 5), // "ordrt"
QT_MOC_LITERAL(119, 956, 5), // "netrt"
QT_MOC_LITERAL(120, 962, 5), // "epsrt"
QT_MOC_LITERAL(121, 968, 5), // "info1"
QT_MOC_LITERAL(122, 974, 5), // "info2"
QT_MOC_LITERAL(123, 980, 5), // "info3"
QT_MOC_LITERAL(124, 986, 5), // "info4"
QT_MOC_LITERAL(125, 992, 8), // "janginfo"
QT_MOC_LITERAL(126, 1001, 5), // "t_per"
QT_MOC_LITERAL(127, 1007, 7), // "tonghwa"
QT_MOC_LITERAL(128, 1015, 5), // "dval1"
QT_MOC_LITERAL(129, 1021, 5), // "sval1"
QT_MOC_LITERAL(130, 1027, 5), // "dval2"
QT_MOC_LITERAL(131, 1033, 5), // "sval2"
QT_MOC_LITERAL(132, 1039, 5), // "dval3"
QT_MOC_LITERAL(133, 1045, 5), // "sval3"
QT_MOC_LITERAL(134, 1051, 5), // "dval4"
QT_MOC_LITERAL(135, 1057, 5), // "sval4"
QT_MOC_LITERAL(136, 1063, 5), // "dval5"
QT_MOC_LITERAL(137, 1069, 5), // "sval5"
QT_MOC_LITERAL(138, 1075, 5), // "davg1"
QT_MOC_LITERAL(139, 1081, 5), // "savg1"
QT_MOC_LITERAL(140, 1087, 5), // "davg2"
QT_MOC_LITERAL(141, 1093, 5), // "savg2"
QT_MOC_LITERAL(142, 1099, 5), // "davg3"
QT_MOC_LITERAL(143, 1105, 5), // "savg3"
QT_MOC_LITERAL(144, 1111, 5), // "davg4"
QT_MOC_LITERAL(145, 1117, 5), // "savg4"
QT_MOC_LITERAL(146, 1123, 5), // "davg5"
QT_MOC_LITERAL(147, 1129, 5), // "savg5"
QT_MOC_LITERAL(148, 1135, 10), // "ftradmdval"
QT_MOC_LITERAL(149, 1146, 10), // "ftradmsval"
QT_MOC_LITERAL(150, 1157, 10), // "ftradmdavg"
QT_MOC_LITERAL(151, 1168, 10), // "ftradmsavg"
QT_MOC_LITERAL(152, 1179, 5), // "info5"
QT_MOC_LITERAL(153, 1185, 10), // "spac_gubun"
QT_MOC_LITERAL(154, 1196, 10), // "issueprice"
QT_MOC_LITERAL(155, 1207, 11), // "alloc_gubun"
QT_MOC_LITERAL(156, 1219, 10), // "alloc_text"
QT_MOC_LITERAL(157, 1230, 11) // "shterm_text"

    },
    "StockInfo\0hname\0expcode\0isETF\0isKOSPI\0"
    "price\0sign\0change\0diff\0volume\0recprice\0"
    "avg\0uplmtprice\0dnlmtprice\0jnilvolume\0"
    "volumediff\0open\0opentime\0high\0hightime\0"
    "low\0lowtime\0high52w\0high52wdate\0low52w\0"
    "low52wdate\0exhratio\0per\0pbrx\0listing\0"
    "jkrate\0memedan\0offernocd1\0bidnocd1\0"
    "offerno1\0bidno1\0dvol1\0svol1\0dcha1\0"
    "scha1\0ddiff1\0sdiff1\0offernocd2\0bidnocd2\0"
    "offerno2\0bidno2\0dvol2\0svol2\0dcha2\0"
    "scha2\0ddiff2\0sdiff2\0offernocd3\0bidnocd3\0"
    "offerno3\0bidno3\0dvol3\0svol3\0dcha3\0"
    "scha3\0ddiff3\0sdiff3\0offernocd4\0bidnocd4\0"
    "offerno4\0bidno4\0dvol4\0svol4\0dcha4\0"
    "scha4\0ddiff4\0sdiff4\0offernocd5\0bidnocd5\0"
    "offerno5\0bidno5\0dvol5\0svol5\0dcha5\0"
    "scha5\0ddiff5\0sdiff5\0fwdvl\0ftradmdcha\0"
    "ftradmddiff\0fwsvl\0ftradmscha\0ftradmsdiff\0"
    "vol\0shcode\0value\0jvolume\0highyear\0"
    "highyeardate\0lowyear\0lowyeardate\0"
    "target\0capital\0abscnt\0parprice\0gsmm\0"
    "subprice\0total\0listdate\0name\0bfsales\0"
    "bfoperatingincome\0bfordinaryincome\0"
    "bfnetincome\0bfeps\0name2\0bfsales2\0"
    "bfoperatingincome2\0bfordinaryincome2\0"
    "bfnetincome2\0bfeps2\0salert\0opert\0ordrt\0"
    "netrt\0epsrt\0info1\0info2\0info3\0info4\0"
    "janginfo\0t_per\0tonghwa\0dval1\0sval1\0"
    "dval2\0sval2\0dval3\0sval3\0dval4\0sval4\0"
    "dval5\0sval5\0davg1\0savg1\0davg2\0savg2\0"
    "davg3\0savg3\0davg4\0savg4\0davg5\0savg5\0"
    "ftradmdval\0ftradmsval\0ftradmdavg\0"
    "ftradmsavg\0info5\0spac_gubun\0issueprice\0"
    "alloc_gubun\0alloc_text\0shterm_text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StockInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
     157,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095003,
       2, QMetaType::QString, 0x00095003,
       3, QMetaType::Bool, 0x00095003,
       4, QMetaType::Bool, 0x00095003,
       5, QMetaType::Long, 0x00095103,
       6, QMetaType::QString, 0x00095103,
       7, QMetaType::Long, 0x00095103,
       8, QMetaType::Float, 0x00095103,
       9, QMetaType::Long, 0x00095103,
      10, QMetaType::Long, 0x00095103,
      11, QMetaType::Long, 0x00095103,
      12, QMetaType::Long, 0x00095103,
      13, QMetaType::Long, 0x00095103,
      14, QMetaType::Long, 0x00095103,
      15, QMetaType::Long, 0x00095103,
      16, QMetaType::Long, 0x00095103,
      17, QMetaType::QTime, 0x00095103,
      18, QMetaType::Long, 0x00095103,
      19, QMetaType::QTime, 0x00095103,
      20, QMetaType::Long, 0x00095103,
      21, QMetaType::QTime, 0x00095103,
      22, QMetaType::Long, 0x00095003,
      23, QMetaType::QDate, 0x00095003,
      24, QMetaType::Long, 0x00095003,
      25, QMetaType::QDate, 0x00095003,
      26, QMetaType::Float, 0x00095103,
      27, QMetaType::Float, 0x00095103,
      28, QMetaType::Float, 0x00095103,
      29, QMetaType::Long, 0x00095103,
      30, QMetaType::Long, 0x00095103,
      31, QMetaType::QString, 0x00095103,
      32, QMetaType::QString, 0x00095103,
      33, QMetaType::QString, 0x00095103,
      34, QMetaType::QString, 0x00095103,
      35, QMetaType::QString, 0x00095103,
      36, QMetaType::Long, 0x00095103,
      37, QMetaType::Long, 0x00095103,
      38, QMetaType::Long, 0x00095103,
      39, QMetaType::Long, 0x00095103,
      40, QMetaType::Float, 0x00095103,
      41, QMetaType::Float, 0x00095103,
      42, QMetaType::QString, 0x00095103,
      43, QMetaType::QString, 0x00095103,
      44, QMetaType::QString, 0x00095103,
      45, QMetaType::QString, 0x00095103,
      46, QMetaType::Long, 0x00095103,
      47, QMetaType::Long, 0x00095103,
      48, QMetaType::Long, 0x00095103,
      49, QMetaType::Long, 0x00095103,
      50, QMetaType::Float, 0x00095103,
      51, QMetaType::Float, 0x00095103,
      52, QMetaType::QString, 0x00095103,
      53, QMetaType::QString, 0x00095103,
      54, QMetaType::QString, 0x00095103,
      55, QMetaType::QString, 0x00095103,
      56, QMetaType::Long, 0x00095103,
      57, QMetaType::Long, 0x00095103,
      58, QMetaType::Long, 0x00095103,
      59, QMetaType::Long, 0x00095103,
      60, QMetaType::Float, 0x00095103,
      61, QMetaType::Float, 0x00095103,
      62, QMetaType::QString, 0x00095103,
      63, QMetaType::QString, 0x00095103,
      64, QMetaType::QString, 0x00095103,
      65, QMetaType::QString, 0x00095103,
      66, QMetaType::Long, 0x00095103,
      67, QMetaType::Long, 0x00095103,
      68, QMetaType::Long, 0x00095103,
      69, QMetaType::Long, 0x00095103,
      70, QMetaType::Float, 0x00095103,
      71, QMetaType::Float, 0x00095103,
      72, QMetaType::QString, 0x00095103,
      73, QMetaType::QString, 0x00095103,
      74, QMetaType::QString, 0x00095103,
      75, QMetaType::QString, 0x00095103,
      76, QMetaType::Long, 0x00095103,
      77, QMetaType::Long, 0x00095103,
      78, QMetaType::Long, 0x00095103,
      79, QMetaType::Long, 0x00095103,
      80, QMetaType::Float, 0x00095103,
      81, QMetaType::Float, 0x00095103,
      82, QMetaType::Long, 0x00095103,
      83, QMetaType::Long, 0x00095103,
      84, QMetaType::Float, 0x00095103,
      85, QMetaType::Long, 0x00095103,
      86, QMetaType::Long, 0x00095103,
      87, QMetaType::Float, 0x00095103,
      88, QMetaType::Float, 0x00095103,
      89, QMetaType::QString, 0x00095103,
      90, QMetaType::Long, 0x00095103,
      91, QMetaType::Long, 0x00095103,
      92, QMetaType::Long, 0x00095103,
      93, QMetaType::QDate, 0x00095103,
      94, QMetaType::Long, 0x00095103,
      95, QMetaType::QDate, 0x00095103,
      96, QMetaType::Long, 0x00095103,
      97, QMetaType::Long, 0x00095103,
      98, QMetaType::Long, 0x00095103,
      99, QMetaType::Long, 0x00095103,
     100, QMetaType::QString, 0x00095103,
     101, QMetaType::Long, 0x00095103,
     102, QMetaType::Long, 0x00095103,
     103, QMetaType::QDate, 0x00095103,
     104, QMetaType::QString, 0x00095103,
     105, QMetaType::Long, 0x00095103,
     106, QMetaType::Long, 0x00095103,
     107, QMetaType::Long, 0x00095103,
     108, QMetaType::Long, 0x00095103,
     109, QMetaType::Float, 0x00095103,
     110, QMetaType::QString, 0x00095103,
     111, QMetaType::Long, 0x00095103,
     112, QMetaType::Long, 0x00095103,
     113, QMetaType::Long, 0x00095103,
     114, QMetaType::Long, 0x00095103,
     115, QMetaType::Float, 0x00095103,
     116, QMetaType::Float, 0x00095103,
     117, QMetaType::Float, 0x00095103,
     118, QMetaType::Float, 0x00095103,
     119, QMetaType::Float, 0x00095103,
     120, QMetaType::Float, 0x00095103,
     121, QMetaType::QString, 0x00095103,
     122, QMetaType::QString, 0x00095103,
     123, QMetaType::QString, 0x00095103,
     124, QMetaType::QString, 0x00095103,
     125, QMetaType::QString, 0x00095103,
     126, QMetaType::Float, 0x00095003,
     127, QMetaType::QString, 0x00095103,
     128, QMetaType::Long, 0x00095103,
     129, QMetaType::Long, 0x00095103,
     130, QMetaType::Long, 0x00095103,
     131, QMetaType::Long, 0x00095103,
     132, QMetaType::Long, 0x00095103,
     133, QMetaType::Long, 0x00095103,
     134, QMetaType::Long, 0x00095103,
     135, QMetaType::Long, 0x00095103,
     136, QMetaType::Long, 0x00095103,
     137, QMetaType::Long, 0x00095103,
     138, QMetaType::Long, 0x00095103,
     139, QMetaType::Long, 0x00095103,
     140, QMetaType::Long, 0x00095103,
     141, QMetaType::Long, 0x00095103,
     142, QMetaType::Long, 0x00095103,
     143, QMetaType::Long, 0x00095103,
     144, QMetaType::Long, 0x00095103,
     145, QMetaType::Long, 0x00095103,
     146, QMetaType::Long, 0x00095103,
     147, QMetaType::Long, 0x00095103,
     148, QMetaType::Long, 0x00095103,
     149, QMetaType::Long, 0x00095103,
     150, QMetaType::Long, 0x00095103,
     151, QMetaType::Long, 0x00095103,
     152, QMetaType::QString, 0x00095103,
     153, QMetaType::QString, 0x00095003,
     154, QMetaType::Long, 0x00095103,
     155, QMetaType::QString, 0x00095003,
     156, QMetaType::QString, 0x00095003,
     157, QMetaType::QString, 0x00095003,

       0        // eod
};

void StockInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject StockInfo::staticMetaObject = {
    { &TrItem::staticMetaObject, qt_meta_stringdata_StockInfo.data,
      qt_meta_data_StockInfo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StockInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StockInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StockInfo.stringdata))
        return static_cast<void*>(const_cast< StockInfo*>(this));
    return TrItem::qt_metacast(_clname);
}

int StockInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TrItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = hname(); break;
        case 1: *reinterpret_cast< QString*>(_v) = expcode(); break;
        case 2: *reinterpret_cast< bool*>(_v) = isETF(); break;
        case 3: *reinterpret_cast< bool*>(_v) = isKOSPI(); break;
        case 4: *reinterpret_cast< long*>(_v) = price(); break;
        case 5: *reinterpret_cast< QString*>(_v) = sign(); break;
        case 6: *reinterpret_cast< long*>(_v) = change(); break;
        case 7: *reinterpret_cast< float*>(_v) = diff(); break;
        case 8: *reinterpret_cast< long*>(_v) = volume(); break;
        case 9: *reinterpret_cast< long*>(_v) = recprice(); break;
        case 10: *reinterpret_cast< long*>(_v) = avg(); break;
        case 11: *reinterpret_cast< long*>(_v) = uplmtprice(); break;
        case 12: *reinterpret_cast< long*>(_v) = dnlmtprice(); break;
        case 13: *reinterpret_cast< long*>(_v) = jnilvolume(); break;
        case 14: *reinterpret_cast< long*>(_v) = volumediff(); break;
        case 15: *reinterpret_cast< long*>(_v) = open(); break;
        case 16: *reinterpret_cast< QTime*>(_v) = opentime(); break;
        case 17: *reinterpret_cast< long*>(_v) = high(); break;
        case 18: *reinterpret_cast< QTime*>(_v) = hightime(); break;
        case 19: *reinterpret_cast< long*>(_v) = low(); break;
        case 20: *reinterpret_cast< QTime*>(_v) = lowtime(); break;
        case 21: *reinterpret_cast< long*>(_v) = high52w(); break;
        case 22: *reinterpret_cast< QDate*>(_v) = high52wdate(); break;
        case 23: *reinterpret_cast< long*>(_v) = low52w(); break;
        case 24: *reinterpret_cast< QDate*>(_v) = low52wdate(); break;
        case 25: *reinterpret_cast< float*>(_v) = exhratio(); break;
        case 26: *reinterpret_cast< float*>(_v) = per(); break;
        case 27: *reinterpret_cast< float*>(_v) = pbrx(); break;
        case 28: *reinterpret_cast< long*>(_v) = listing(); break;
        case 29: *reinterpret_cast< long*>(_v) = jkrate(); break;
        case 30: *reinterpret_cast< QString*>(_v) = memedan(); break;
        case 31: *reinterpret_cast< QString*>(_v) = offernocd1(); break;
        case 32: *reinterpret_cast< QString*>(_v) = bidnocd1(); break;
        case 33: *reinterpret_cast< QString*>(_v) = offerno1(); break;
        case 34: *reinterpret_cast< QString*>(_v) = bidno1(); break;
        case 35: *reinterpret_cast< long*>(_v) = dvol1(); break;
        case 36: *reinterpret_cast< long*>(_v) = svol1(); break;
        case 37: *reinterpret_cast< long*>(_v) = dcha1(); break;
        case 38: *reinterpret_cast< long*>(_v) = scha1(); break;
        case 39: *reinterpret_cast< float*>(_v) = ddiff1(); break;
        case 40: *reinterpret_cast< float*>(_v) = sdiff1(); break;
        case 41: *reinterpret_cast< QString*>(_v) = offernocd2(); break;
        case 42: *reinterpret_cast< QString*>(_v) = bidnocd2(); break;
        case 43: *reinterpret_cast< QString*>(_v) = offerno2(); break;
        case 44: *reinterpret_cast< QString*>(_v) = bidno2(); break;
        case 45: *reinterpret_cast< long*>(_v) = dvol2(); break;
        case 46: *reinterpret_cast< long*>(_v) = svol2(); break;
        case 47: *reinterpret_cast< long*>(_v) = dcha2(); break;
        case 48: *reinterpret_cast< long*>(_v) = scha2(); break;
        case 49: *reinterpret_cast< float*>(_v) = ddiff2(); break;
        case 50: *reinterpret_cast< float*>(_v) = sdiff2(); break;
        case 51: *reinterpret_cast< QString*>(_v) = offernocd3(); break;
        case 52: *reinterpret_cast< QString*>(_v) = bidnocd3(); break;
        case 53: *reinterpret_cast< QString*>(_v) = offerno3(); break;
        case 54: *reinterpret_cast< QString*>(_v) = bidno3(); break;
        case 55: *reinterpret_cast< long*>(_v) = dvol3(); break;
        case 56: *reinterpret_cast< long*>(_v) = svol3(); break;
        case 57: *reinterpret_cast< long*>(_v) = dcha3(); break;
        case 58: *reinterpret_cast< long*>(_v) = scha3(); break;
        case 59: *reinterpret_cast< float*>(_v) = ddiff3(); break;
        case 60: *reinterpret_cast< float*>(_v) = sdiff3(); break;
        case 61: *reinterpret_cast< QString*>(_v) = offernocd4(); break;
        case 62: *reinterpret_cast< QString*>(_v) = bidnocd4(); break;
        case 63: *reinterpret_cast< QString*>(_v) = offerno4(); break;
        case 64: *reinterpret_cast< QString*>(_v) = bidno4(); break;
        case 65: *reinterpret_cast< long*>(_v) = dvol4(); break;
        case 66: *reinterpret_cast< long*>(_v) = svol4(); break;
        case 67: *reinterpret_cast< long*>(_v) = dcha4(); break;
        case 68: *reinterpret_cast< long*>(_v) = scha4(); break;
        case 69: *reinterpret_cast< float*>(_v) = ddiff4(); break;
        case 70: *reinterpret_cast< float*>(_v) = sdiff4(); break;
        case 71: *reinterpret_cast< QString*>(_v) = offernocd5(); break;
        case 72: *reinterpret_cast< QString*>(_v) = bidnocd5(); break;
        case 73: *reinterpret_cast< QString*>(_v) = offerno5(); break;
        case 74: *reinterpret_cast< QString*>(_v) = bidno5(); break;
        case 75: *reinterpret_cast< long*>(_v) = dvol5(); break;
        case 76: *reinterpret_cast< long*>(_v) = svol5(); break;
        case 77: *reinterpret_cast< long*>(_v) = dcha5(); break;
        case 78: *reinterpret_cast< long*>(_v) = scha5(); break;
        case 79: *reinterpret_cast< float*>(_v) = ddiff5(); break;
        case 80: *reinterpret_cast< float*>(_v) = sdiff5(); break;
        case 81: *reinterpret_cast< long*>(_v) = fwdvl(); break;
        case 82: *reinterpret_cast< long*>(_v) = ftradmdcha(); break;
        case 83: *reinterpret_cast< float*>(_v) = ftradmddiff(); break;
        case 84: *reinterpret_cast< long*>(_v) = fwsvl(); break;
        case 85: *reinterpret_cast< long*>(_v) = ftradmscha(); break;
        case 86: *reinterpret_cast< float*>(_v) = ftradmsdiff(); break;
        case 87: *reinterpret_cast< float*>(_v) = vol(); break;
        case 88: *reinterpret_cast< QString*>(_v) = shcode(); break;
        case 89: *reinterpret_cast< long*>(_v) = value(); break;
        case 90: *reinterpret_cast< long*>(_v) = jvolume(); break;
        case 91: *reinterpret_cast< long*>(_v) = highyear(); break;
        case 92: *reinterpret_cast< QDate*>(_v) = highyeardate(); break;
        case 93: *reinterpret_cast< long*>(_v) = lowyear(); break;
        case 94: *reinterpret_cast< QDate*>(_v) = lowyeardate(); break;
        case 95: *reinterpret_cast< long*>(_v) = target(); break;
        case 96: *reinterpret_cast< long*>(_v) = capital(); break;
        case 97: *reinterpret_cast< long*>(_v) = abscnt(); break;
        case 98: *reinterpret_cast< long*>(_v) = parprice(); break;
        case 99: *reinterpret_cast< QString*>(_v) = gsmm(); break;
        case 100: *reinterpret_cast< long*>(_v) = subprice(); break;
        case 101: *reinterpret_cast< long*>(_v) = total(); break;
        case 102: *reinterpret_cast< QDate*>(_v) = listdate(); break;
        case 103: *reinterpret_cast< QString*>(_v) = name(); break;
        case 104: *reinterpret_cast< long*>(_v) = bfsales(); break;
        case 105: *reinterpret_cast< long*>(_v) = bfoperatingincome(); break;
        case 106: *reinterpret_cast< long*>(_v) = bfordinaryincome(); break;
        case 107: *reinterpret_cast< long*>(_v) = bfnetincome(); break;
        case 108: *reinterpret_cast< float*>(_v) = bfeps(); break;
        case 109: *reinterpret_cast< QString*>(_v) = name2(); break;
        case 110: *reinterpret_cast< long*>(_v) = bfsales2(); break;
        case 111: *reinterpret_cast< long*>(_v) = bfoperatingincome2(); break;
        case 112: *reinterpret_cast< long*>(_v) = bfordinaryincome2(); break;
        case 113: *reinterpret_cast< long*>(_v) = bfnetincome2(); break;
        case 114: *reinterpret_cast< float*>(_v) = bfeps2(); break;
        case 115: *reinterpret_cast< float*>(_v) = salert(); break;
        case 116: *reinterpret_cast< float*>(_v) = opert(); break;
        case 117: *reinterpret_cast< float*>(_v) = ordrt(); break;
        case 118: *reinterpret_cast< float*>(_v) = netrt(); break;
        case 119: *reinterpret_cast< float*>(_v) = epsrt(); break;
        case 120: *reinterpret_cast< QString*>(_v) = info1(); break;
        case 121: *reinterpret_cast< QString*>(_v) = info2(); break;
        case 122: *reinterpret_cast< QString*>(_v) = info3(); break;
        case 123: *reinterpret_cast< QString*>(_v) = info4(); break;
        case 124: *reinterpret_cast< QString*>(_v) = janginfo(); break;
        case 125: *reinterpret_cast< float*>(_v) = t_per(); break;
        case 126: *reinterpret_cast< QString*>(_v) = tonghwa(); break;
        case 127: *reinterpret_cast< long*>(_v) = dval1(); break;
        case 128: *reinterpret_cast< long*>(_v) = sval1(); break;
        case 129: *reinterpret_cast< long*>(_v) = dval2(); break;
        case 130: *reinterpret_cast< long*>(_v) = sval2(); break;
        case 131: *reinterpret_cast< long*>(_v) = dval3(); break;
        case 132: *reinterpret_cast< long*>(_v) = sval3(); break;
        case 133: *reinterpret_cast< long*>(_v) = dval4(); break;
        case 134: *reinterpret_cast< long*>(_v) = sval4(); break;
        case 135: *reinterpret_cast< long*>(_v) = dval5(); break;
        case 136: *reinterpret_cast< long*>(_v) = sval5(); break;
        case 137: *reinterpret_cast< long*>(_v) = davg1(); break;
        case 138: *reinterpret_cast< long*>(_v) = savg1(); break;
        case 139: *reinterpret_cast< long*>(_v) = davg2(); break;
        case 140: *reinterpret_cast< long*>(_v) = savg2(); break;
        case 141: *reinterpret_cast< long*>(_v) = davg3(); break;
        case 142: *reinterpret_cast< long*>(_v) = savg3(); break;
        case 143: *reinterpret_cast< long*>(_v) = davg4(); break;
        case 144: *reinterpret_cast< long*>(_v) = savg4(); break;
        case 145: *reinterpret_cast< long*>(_v) = davg5(); break;
        case 146: *reinterpret_cast< long*>(_v) = savg5(); break;
        case 147: *reinterpret_cast< long*>(_v) = ftradmdval(); break;
        case 148: *reinterpret_cast< long*>(_v) = ftradmsval(); break;
        case 149: *reinterpret_cast< long*>(_v) = ftradmdavg(); break;
        case 150: *reinterpret_cast< long*>(_v) = ftradmsavg(); break;
        case 151: *reinterpret_cast< QString*>(_v) = info5(); break;
        case 152: *reinterpret_cast< QString*>(_v) = spac_gubun(); break;
        case 153: *reinterpret_cast< long*>(_v) = issueprice(); break;
        case 154: *reinterpret_cast< QString*>(_v) = alloc_gubun(); break;
        case 155: *reinterpret_cast< QString*>(_v) = alloc_text(); break;
        case 156: *reinterpret_cast< QString*>(_v) = shterm_text(); break;
        default: break;
        }
        _id -= 157;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_hname != *reinterpret_cast< QString*>(_v)) {
                _hname = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 1:
            if (_expcode != *reinterpret_cast< QString*>(_v)) {
                _expcode = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 2:
            if (_isETF != *reinterpret_cast< bool*>(_v)) {
                _isETF = *reinterpret_cast< bool*>(_v);
            }
            break;
        case 3:
            if (_isKOSPI != *reinterpret_cast< bool*>(_v)) {
                _isKOSPI = *reinterpret_cast< bool*>(_v);
            }
            break;
        case 4: setPrice(*reinterpret_cast< long*>(_v)); break;
        case 5: setSign(*reinterpret_cast< QString*>(_v)); break;
        case 6: setChange(*reinterpret_cast< long*>(_v)); break;
        case 7: setDiff(*reinterpret_cast< float*>(_v)); break;
        case 8: setVolume(*reinterpret_cast< long*>(_v)); break;
        case 9: setRecprice(*reinterpret_cast< long*>(_v)); break;
        case 10: setAvg(*reinterpret_cast< long*>(_v)); break;
        case 11: setUplmtprice(*reinterpret_cast< long*>(_v)); break;
        case 12: setDnlmtprice(*reinterpret_cast< long*>(_v)); break;
        case 13: setJnilvolume(*reinterpret_cast< long*>(_v)); break;
        case 14: setVolumediff(*reinterpret_cast< long*>(_v)); break;
        case 15: setOpen(*reinterpret_cast< long*>(_v)); break;
        case 16: setOpentime(*reinterpret_cast< QTime*>(_v)); break;
        case 17: setHigh(*reinterpret_cast< long*>(_v)); break;
        case 18: setHightime(*reinterpret_cast< QTime*>(_v)); break;
        case 19: setLow(*reinterpret_cast< long*>(_v)); break;
        case 20: setLowtime(*reinterpret_cast< QTime*>(_v)); break;
        case 21: setHigh52W(*reinterpret_cast< long*>(_v)); break;
        case 22: setHigh52Wdate(*reinterpret_cast< QDate*>(_v)); break;
        case 23: setLow52W(*reinterpret_cast< long*>(_v)); break;
        case 24: setLow52Wdate(*reinterpret_cast< QDate*>(_v)); break;
        case 25: setExhratio(*reinterpret_cast< float*>(_v)); break;
        case 26: setPer(*reinterpret_cast< float*>(_v)); break;
        case 27: setPbrx(*reinterpret_cast< float*>(_v)); break;
        case 28: setListing(*reinterpret_cast< long*>(_v)); break;
        case 29: setJkrate(*reinterpret_cast< long*>(_v)); break;
        case 30: setMemedan(*reinterpret_cast< QString*>(_v)); break;
        case 31: setOffernocd1(*reinterpret_cast< QString*>(_v)); break;
        case 32: setBidnocd1(*reinterpret_cast< QString*>(_v)); break;
        case 33: setOfferno1(*reinterpret_cast< QString*>(_v)); break;
        case 34: setBidno1(*reinterpret_cast< QString*>(_v)); break;
        case 35: setDvol1(*reinterpret_cast< long*>(_v)); break;
        case 36: setSvol1(*reinterpret_cast< long*>(_v)); break;
        case 37: setDcha1(*reinterpret_cast< long*>(_v)); break;
        case 38: setScha1(*reinterpret_cast< long*>(_v)); break;
        case 39: setDdiff1(*reinterpret_cast< float*>(_v)); break;
        case 40: setSdiff1(*reinterpret_cast< float*>(_v)); break;
        case 41: setOffernocd2(*reinterpret_cast< QString*>(_v)); break;
        case 42: setBidnocd2(*reinterpret_cast< QString*>(_v)); break;
        case 43: setOfferno2(*reinterpret_cast< QString*>(_v)); break;
        case 44: setBidno2(*reinterpret_cast< QString*>(_v)); break;
        case 45: setDvol2(*reinterpret_cast< long*>(_v)); break;
        case 46: setSvol2(*reinterpret_cast< long*>(_v)); break;
        case 47: setDcha2(*reinterpret_cast< long*>(_v)); break;
        case 48: setScha2(*reinterpret_cast< long*>(_v)); break;
        case 49: setDdiff2(*reinterpret_cast< float*>(_v)); break;
        case 50: setSdiff2(*reinterpret_cast< float*>(_v)); break;
        case 51: setOffernocd3(*reinterpret_cast< QString*>(_v)); break;
        case 52: setBidnocd3(*reinterpret_cast< QString*>(_v)); break;
        case 53: setOfferno3(*reinterpret_cast< QString*>(_v)); break;
        case 54: setBidno3(*reinterpret_cast< QString*>(_v)); break;
        case 55: setDvol3(*reinterpret_cast< long*>(_v)); break;
        case 56: setSvol3(*reinterpret_cast< long*>(_v)); break;
        case 57: setDcha3(*reinterpret_cast< long*>(_v)); break;
        case 58: setScha3(*reinterpret_cast< long*>(_v)); break;
        case 59: setDdiff3(*reinterpret_cast< float*>(_v)); break;
        case 60: setSdiff3(*reinterpret_cast< float*>(_v)); break;
        case 61: setOffernocd4(*reinterpret_cast< QString*>(_v)); break;
        case 62: setBidnocd4(*reinterpret_cast< QString*>(_v)); break;
        case 63: setOfferno4(*reinterpret_cast< QString*>(_v)); break;
        case 64: setBidno4(*reinterpret_cast< QString*>(_v)); break;
        case 65: setDvol4(*reinterpret_cast< long*>(_v)); break;
        case 66: setSvol4(*reinterpret_cast< long*>(_v)); break;
        case 67: setDcha4(*reinterpret_cast< long*>(_v)); break;
        case 68: setScha4(*reinterpret_cast< long*>(_v)); break;
        case 69: setDdiff4(*reinterpret_cast< float*>(_v)); break;
        case 70: setSdiff4(*reinterpret_cast< float*>(_v)); break;
        case 71: setOffernocd5(*reinterpret_cast< QString*>(_v)); break;
        case 72: setBidnocd5(*reinterpret_cast< QString*>(_v)); break;
        case 73: setOfferno5(*reinterpret_cast< QString*>(_v)); break;
        case 74: setBidno5(*reinterpret_cast< QString*>(_v)); break;
        case 75: setDvol5(*reinterpret_cast< long*>(_v)); break;
        case 76: setSvol5(*reinterpret_cast< long*>(_v)); break;
        case 77: setDcha5(*reinterpret_cast< long*>(_v)); break;
        case 78: setScha5(*reinterpret_cast< long*>(_v)); break;
        case 79: setDdiff5(*reinterpret_cast< float*>(_v)); break;
        case 80: setSdiff5(*reinterpret_cast< float*>(_v)); break;
        case 81: setFwdvl(*reinterpret_cast< long*>(_v)); break;
        case 82: setFtradmdcha(*reinterpret_cast< long*>(_v)); break;
        case 83: setFtradmddiff(*reinterpret_cast< float*>(_v)); break;
        case 84: setFwsvl(*reinterpret_cast< long*>(_v)); break;
        case 85: setFtradmscha(*reinterpret_cast< long*>(_v)); break;
        case 86: setFtradmsdiff(*reinterpret_cast< float*>(_v)); break;
        case 87: setVol(*reinterpret_cast< float*>(_v)); break;
        case 88: setShcode(*reinterpret_cast< QString*>(_v)); break;
        case 89: setValue(*reinterpret_cast< long*>(_v)); break;
        case 90: setJvolume(*reinterpret_cast< long*>(_v)); break;
        case 91: setHighyear(*reinterpret_cast< long*>(_v)); break;
        case 92: setHighyeardate(*reinterpret_cast< QDate*>(_v)); break;
        case 93: setLowyear(*reinterpret_cast< long*>(_v)); break;
        case 94: setLowyeardate(*reinterpret_cast< QDate*>(_v)); break;
        case 95: setTarget(*reinterpret_cast< long*>(_v)); break;
        case 96: setCapital(*reinterpret_cast< long*>(_v)); break;
        case 97: setAbscnt(*reinterpret_cast< long*>(_v)); break;
        case 98: setParprice(*reinterpret_cast< long*>(_v)); break;
        case 99: setGsmm(*reinterpret_cast< QString*>(_v)); break;
        case 100: setSubprice(*reinterpret_cast< long*>(_v)); break;
        case 101: setTotal(*reinterpret_cast< long*>(_v)); break;
        case 102: setListdate(*reinterpret_cast< QDate*>(_v)); break;
        case 103: setName(*reinterpret_cast< QString*>(_v)); break;
        case 104: setBfsales(*reinterpret_cast< long*>(_v)); break;
        case 105: setBfoperatingincome(*reinterpret_cast< long*>(_v)); break;
        case 106: setBfordinaryincome(*reinterpret_cast< long*>(_v)); break;
        case 107: setBfnetincome(*reinterpret_cast< long*>(_v)); break;
        case 108: setBfeps(*reinterpret_cast< float*>(_v)); break;
        case 109: setName2(*reinterpret_cast< QString*>(_v)); break;
        case 110: setBfsales2(*reinterpret_cast< long*>(_v)); break;
        case 111: setBfoperatingincome2(*reinterpret_cast< long*>(_v)); break;
        case 112: setBfordinaryincome2(*reinterpret_cast< long*>(_v)); break;
        case 113: setBfnetincome2(*reinterpret_cast< long*>(_v)); break;
        case 114: setBfeps2(*reinterpret_cast< float*>(_v)); break;
        case 115: setSalert(*reinterpret_cast< float*>(_v)); break;
        case 116: setOpert(*reinterpret_cast< float*>(_v)); break;
        case 117: setOrdrt(*reinterpret_cast< float*>(_v)); break;
        case 118: setNetrt(*reinterpret_cast< float*>(_v)); break;
        case 119: setEpsrt(*reinterpret_cast< float*>(_v)); break;
        case 120: setInfo1(*reinterpret_cast< QString*>(_v)); break;
        case 121: setInfo2(*reinterpret_cast< QString*>(_v)); break;
        case 122: setInfo3(*reinterpret_cast< QString*>(_v)); break;
        case 123: setInfo4(*reinterpret_cast< QString*>(_v)); break;
        case 124: setJanginfo(*reinterpret_cast< QString*>(_v)); break;
        case 125: setT_Per(*reinterpret_cast< float*>(_v)); break;
        case 126: setTonghwa(*reinterpret_cast< QString*>(_v)); break;
        case 127: setDval1(*reinterpret_cast< long*>(_v)); break;
        case 128: setSval1(*reinterpret_cast< long*>(_v)); break;
        case 129: setDval2(*reinterpret_cast< long*>(_v)); break;
        case 130: setSval2(*reinterpret_cast< long*>(_v)); break;
        case 131: setDval3(*reinterpret_cast< long*>(_v)); break;
        case 132: setSval3(*reinterpret_cast< long*>(_v)); break;
        case 133: setDval4(*reinterpret_cast< long*>(_v)); break;
        case 134: setSval4(*reinterpret_cast< long*>(_v)); break;
        case 135: setDval5(*reinterpret_cast< long*>(_v)); break;
        case 136: setSval5(*reinterpret_cast< long*>(_v)); break;
        case 137: setDavg1(*reinterpret_cast< long*>(_v)); break;
        case 138: setSavg1(*reinterpret_cast< long*>(_v)); break;
        case 139: setDavg2(*reinterpret_cast< long*>(_v)); break;
        case 140: setSavg2(*reinterpret_cast< long*>(_v)); break;
        case 141: setDavg3(*reinterpret_cast< long*>(_v)); break;
        case 142: setSavg3(*reinterpret_cast< long*>(_v)); break;
        case 143: setDavg4(*reinterpret_cast< long*>(_v)); break;
        case 144: setSavg4(*reinterpret_cast< long*>(_v)); break;
        case 145: setDavg5(*reinterpret_cast< long*>(_v)); break;
        case 146: setSavg5(*reinterpret_cast< long*>(_v)); break;
        case 147: setFtradmdval(*reinterpret_cast< long*>(_v)); break;
        case 148: setFtradmsval(*reinterpret_cast< long*>(_v)); break;
        case 149: setFtradmdavg(*reinterpret_cast< long*>(_v)); break;
        case 150: setFtradmsavg(*reinterpret_cast< long*>(_v)); break;
        case 151: setInfo5(*reinterpret_cast< QString*>(_v)); break;
        case 152: setSpac_Gubun(*reinterpret_cast< QString*>(_v)); break;
        case 153: setIssueprice(*reinterpret_cast< long*>(_v)); break;
        case 154: setAlloc_Gubun(*reinterpret_cast< QString*>(_v)); break;
        case 155: setAlloc_Text(*reinterpret_cast< QString*>(_v)); break;
        case 156: setShterm_Text(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
        _id -= 157;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 157;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 157;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 157;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 157;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 157;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 157;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 157)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 157;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
