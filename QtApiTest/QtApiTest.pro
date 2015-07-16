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
    tr/t1702/t1702item.cpp \
    tr/t8430/t8430item.cpp \
    tr/t8430/t8430query.cpp \
    tr/tritem.cpp \
    tr/trquery.cpp \
    util/xingutil.cpp \
    XingLib/xaquery.cpp \
    XingLib/xareal.cpp \
    XingLib/xasession.cpp \
    XingLib/xasessionevents.cpp \
    tr/trmetainfo.cpp

HEADERS += \
    data/stockinfo.h \
    manager/stockinfomngr.h \
    tr/t1102/t1102item.h \
    tr/t1702/t1702item.h \
    tr/t8430/t8430item.h \
    tr/t8430/t8430query.h \
    tr/tritem.h \
    tr/trquery.h \
    util/xingutil.h \
    XingLib/xaquery.h \
    XingLib/xareal.h \
    XingLib/xasession.h \
    XingLib/xasessionevents.h \
    tr/trmetainfo.h
