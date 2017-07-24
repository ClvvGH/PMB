#-------------------------------------------------
#
# Project created by QtCreator 2017-07-13T09:16:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app


SOURCES += main.cpp\
        mainview.cpp \
    database.cpp \
    chatserver.cpp

HEADERS  += mainview.h \
    database.h \
    chatserver.h

FORMS    += mainview.ui\


QT  += sql
QT += network

RESOURCES += \
    picture.qrc
