#-------------------------------------------------
#
# Project created by QtCreator 2015-07-14T22:53:14
#
#-------------------------------------------------

QT       += core

QT       -= gui
QT       += axcontainer
TARGET = QtApiTest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    data/stockinfo.cpp \
    manager/stockinfomngr.cpp \
    tr/t1102/t1102item.cpp \
    tr/tritem.cpp \
    tr/trquery.cpp \
    util/xingutil.cpp \
    XingLib/xaquery.cpp \
    XingLib/xareal.cpp \
    XingLib/xasession.cpp \
    XingLib/xasessionevents.cpp \
    tr/trmetainfo.cpp \
    test/trtester.cpp \
    tr/t1102/t1102query.cpp

HEADERS += \
    data/stockinfo.h \
    manager/stockinfomngr.h \
    tr/t1102/t1102item.h \
    tr/tritem.h \
    tr/trquery.h \
    util/xingutil.h \
    XingLib/xaquery.h \
    XingLib/xareal.h \
    XingLib/xasession.h \
    XingLib/xasessionevents.h \
    tr/trmetainfo.h \
    test/trtester.h \
    tr/t1102/t1102query.h