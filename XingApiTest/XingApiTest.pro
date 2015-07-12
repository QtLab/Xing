#-------------------------------------------------
#
# Project created by QtCreator 2013-02-13T19:23:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT+=axcontainer

TARGET = XingApiTest
TEMPLATE = app


SOURCES += main.cpp\
                xingapitest.cpp \
    		XingLib/xasession.cpp \
    		XingLib/xasessionevents.cpp \
    		XingLib/xaquery.cpp \
    		XingLib/xareal.cpp \
    TrLib/t1702.cpp \
    TrLib/trhandler.cpp

HEADERS  += xingapitest.h \
    				XingLib/xasession.h \
    				XingLib/xasessionevents.h \
    				XingLib/xaquery.h \
    				XingLib/xareal.h \
    TrLib/t1702.h \
    TrLib/trhandler.h

FORMS    += xingapitest.ui
