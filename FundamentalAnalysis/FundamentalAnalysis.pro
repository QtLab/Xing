#-------------------------------------------------
#
# Project created by QtCreator 2015-06-29T22:27:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FundamentalAnalysis
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ui/logindialog.cpp \
    xing/IXingAPI.cpp \
    xing/xaquery.cpp \
    xing/xasession.cpp

HEADERS  += mainwindow.h \
    ui/logindialog.h \
    xing/IXingAPI.h \
    xing/xaquery.h \
    xing/xasession.h

FORMS    += mainwindow.ui \
    ui/logindialog.ui
