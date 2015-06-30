#-------------------------------------------------
#
# Project created by QtCreator 2015-05-02T02:04:15
#
#-------------------------------------------------

QT       += core gui

QT      += gui-private
QT       += concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtTest
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    xing/IXingAPI.cpp \
    xing/xasession.cpp \
    xing/xaquery.cpp \
    tr/TrHandler.cpp \
    tr/trquery.cpp \
    tr/t8430/t8430query.cpp \
    tr/t8430/t8430handler.cpp \
    tr/t8430/t8430item.cpp \
    tr/tritem.cpp \
    view/resultdialog.cpp \
    tr/t1702/t1702item.cpp \
    tr/t1702/t1702query.cpp \
    tr/t1702/t1702handler.cpp \
    util/fieldutil.cpp

HEADERS  += dialog.h \
    util/templatesingleton.h \
    xing/IXingAPI.h \
    xing/xasession.h \
    tr/t8430/t8430.h \
    xing/xaquery.h \
    tr/TrHandler.h \
    tr/trquery.h \
    util/objectfactory.h \
    tr/t8430/t8430query.h \
    tr/t8430/t8430handler.h \
    tr/t8430/t8430item.h \
    tr/tritem.h \
    view/resultdialog.h \
    tr/t1702/t1702.h \
    tr/t1702/t1702item.h \
    tr/t1702/t1702query.h \
    tr/t1702/t1702handler.h \
    util/fieldutil.h \
    util/xingutil.h

FORMS    += dialog.ui

#LIBS += -lxingAPI
LIBS += -LC:/eBEST/xingAPI/

CONFIG += c++11
