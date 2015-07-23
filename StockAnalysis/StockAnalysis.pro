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
    data/stockinfo.cpp \
    manager/stockinfomngr.cpp \
    tr/t8430/t8430query.cpp \
    tr/tritem.cpp \
    tr/trquery.cpp \
    manager/loginmngr.cpp \
    manager/querymngr.cpp \
    tr/t1102/t1102query.cpp \
    tr/t1702/t1702query.cpp \
    tr/trmetainfo.cpp \
    util/log.cpp \
    util/logbrowser.cpp \
    util/logbrowserdialog.cpp

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
    data/stockinfo.h \
    manager/stockinfomngr.h \
    tr/t8430/t8430query.h \
    tr/trquery.h \
    manager/loginmngr.h \
    manager/querymngr.h \
    tr/t1102/t1102query.h \
    tr/t1702/t1702query.h \
    tr/trmetainfo.h \
    util/log.h \
    util/logbrowser.h \
    util/logbrowserdialog.h

FORMS    += mainwindow.ui \
    ui/logindialog.ui \
    util/logbrowserdialog.ui

CONFIG += c++11
