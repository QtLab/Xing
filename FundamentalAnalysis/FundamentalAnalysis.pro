#-------------------------------------------------
#
# Project created by QtCreator 2015-06-29T22:27:30
#
#-------------------------------------------------

QT       += core gui concurrent sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FundamentalAnalysis
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ui/logindialog.cpp \
    xing/IXingAPI.cpp \
    xing/xaquery.cpp \
    xing/xasession.cpp \
    util/fieldutil.cpp \
    tr/t1702/t1702handler.cpp \
    tr/t1702/t1702item.cpp \
    tr/t1702/t1702query.cpp \
    tr/t8430/t8430handler.cpp \
    tr/t8430/t8430item.cpp \
    tr/t8430/t8430query.cpp \
    tr/TrHandler.cpp \
    tr/tritem.cpp \
    tr/TrQuery.cpp \
    util/xingutil.cpp \
    function/stockdatamanager.cpp \
    tr/t1102/t1102item.cpp \
    tr/t1102/t1102query.cpp \
    tr/t1102/t1102handler.cpp \
    function/stockinfomngr.cpp \
    data/stockinfo.cpp

HEADERS  += mainwindow.h \
    ui/logindialog.h \
    xing/IXingAPI.h \
    xing/xaquery.h \
    xing/xasession.h \
    util/fieldutil.h \
    util/objectfactory.h \
    util/templatesingleton.h \
    tr/t1702/t1702.h \
    tr/t1702/t1702handler.h \
    tr/t1702/t1702item.h \
    tr/t1702/t1702query.h \
    tr/t8430/t8430.h \
    tr/t8430/t8430handler.h \
    tr/t8430/t8430item.h \
    tr/t8430/t8430query.h \
    tr/TrHandler.h \
    tr/tritem.h \
    tr/trquery.h \
    util/xingutil.h \
    function/stockdatamanager.h \
    tr/t1102/t1102.h \
    tr/t1102/t1102item.h \
    tr/t1102/t1102query.h \
    tr/t1102/t1102handler.h \
    function/stockinfomngr.h \
    data/stockinfo.h

FORMS    += mainwindow.ui \
    ui/logindialog.ui
LIBS += -LC:/eBEST/xingAPI/

CONFIG += c++11
