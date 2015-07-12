#-------------------------------------------------
#
# Project created by QtCreator 2015-07-12T20:29:37
#
#-------------------------------------------------

QT       += core gui
QT       += axcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StockAnalysis
TEMPLATE = app
DISTFILES = formatter.astylerc

SOURCES += main.cpp\
        mainwindow.cpp \
    XingLib/xaquery.cpp \
    XingLib/xareal.cpp \
    XingLib/xasession.cpp \
    XingLib/xasessionevents.cpp \
    ui/logindialog.cpp \
    util/xingutil.cpp \
    tr/t1102/t1102item.cpp \
    tr/t1702/t1702item.cpp \
    tr/t8430/t8430item.cpp \
    data/stockinfo.cpp

HEADERS  += mainwindow.h \
    XingLib/xaquery.h \
    XingLib/xareal.h \
    XingLib/xasession.h \
    XingLib/xasessionevents.h \
    ui/logindialog.h \
    util/xingutil.h \
    tr/t1102/t1102item.h \
    tr/t1702/t1702item.h \
    tr/t8430/t8430item.h \
    tr/tritem.h \
    data/stockinfo.h

FORMS    += mainwindow.ui \
    ui/logindialog.ui

CONFIG += c++11
