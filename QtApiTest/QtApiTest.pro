#-------------------------------------------------
#
# Project created by QtCreator 2015-07-14T22:53:14
#
#-------------------------------------------------

QT       += core gui
QT       += axcontainer sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtApiTest
TEMPLATE = app
DISTFILES = formatter.astylerc
TEMPLATE = app


SOURCES += main.cpp \
    data/stockinfo.cpp \
    tr/t1102/t1102item.cpp \
    tr/tritem.cpp \
    tr/trquery.cpp \
    util/xingutil.cpp \
    XingLib/xaquery.cpp \
    XingLib/xareal.cpp \
    XingLib/xasession.cpp \
    XingLib/xasessionevents.cpp \
    tr/trmetainfo.cpp \
    tr/t1102/t1102query.cpp \
    tr/t8430/t8430item.cpp \
    tr/t1702/t1702item.cpp \
    tr/t8430/t8430query.cpp \
    tr/t1702/t1702query.cpp \
    manager/querymngr.cpp \
    util/log.cpp \
    manager/loginmngr.cpp \
    test/trtest.cpp \
    manager/stockinfoupdater.cpp \
    test/trteststockinfoupdater.cpp \
    test/trtester.cpp \
    util/logbrowser.cpp \
    util/logbrowserdialog.cpp \
    testdialog.cpp \
    test/trtestmovement.cpp \
    manager/movementupdater.cpp \
    util/xingthread.cpp \
    manager/stockinfomngr.cpp \
    data/movementinfo.cpp \
    manager/movementmngr.cpp

HEADERS += \
    data/stockinfo.h \
    tr/t1102/t1102item.h \
    tr/tritem.h \
    tr/trquery.h \
    util/xingutil.h \
    XingLib/xaquery.h \
    XingLib/xareal.h \
    XingLib/xasession.h \
    XingLib/xasessionevents.h \
    tr/trmetainfo.h \
    tr/t1102/t1102query.h \
    tr/t8430/t8430item.h \
    tr/t1702/t1702item.h \
    tr/t8430/t8430query.h \
    tr/t1702/t1702query.h \
    manager/querymngr.h \
    util/log.h \
    manager/loginmngr.h \
    test/trtest.h \
    manager/stockinfoupdater.h \
    test/trteststockinfoupdater.h \
    test/trtester.h \
    util/logbrowser.h \
    util/logbrowserdialog.h \
    testdialog.h \
    test/trtestmovement.h \
    manager/movementupdater.h \
    util/xingthread.h \
    manager/stockinfomngr.h \
    data/movementinfo.h \
    manager/movementmngr.h

FORMS += util/logbrowserdialog.ui \
    testdialog.ui

CONFIG += c++11
