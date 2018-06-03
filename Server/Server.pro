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
    database/database.cpp \
    network/chatserver.cpp \
    network/servercontroller.cpp\
    network/chatthread.cpp

HEADERS  += mainview.h \
    database/database.h \
    network/chatserver.h \
    network/servercontroller.h\
    network/chatthread.h

FORMS    += mainview.ui\


QT  += sql
QT += network


