#-------------------------------------------------
#
# Project created by QtCreator 2015-05-02T02:04:15
#
#-------------------------------------------------

QT       += core gui

QT      += gui-private

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtTest
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    xing/IXingAPI.cpp \
    xing/xasession.cpp \
    xing/xaquery.cpp \
    tr/t8430.cpp

HEADERS  += dialog.h \
    util/templatesingleton.h \
    xing/IXingAPI.h \
    xing/xasession.h \
    xing/xaquery.h \
    tr/t8430.h

FORMS    += dialog.ui

#LIBS += -lxingAPI
LIBS += -LC:/eBEST/xingAPI/
