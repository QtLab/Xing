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


SOURCES += main.cpp\
        mainwindow.cpp \
    XingLib/xaquery.cpp \
    XingLib/xareal.cpp \
    XingLib/xasession.cpp \
    XingLib/xasessionevents.cpp \
    ui/logindialog.cpp

HEADERS  += mainwindow.h \
    XingLib/xaquery.h \
    XingLib/xareal.h \
    XingLib/xasession.h \
    XingLib/xasessionevents.h \
    ui/logindialog.h

FORMS    += mainwindow.ui

CONFIG += c++11
