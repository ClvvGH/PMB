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
        widget.cpp \
    database.cpp \
    chatserver.cpp

HEADERS  += widget.h \
    database.h \
    chatserver.h

FORMS    += widget.ui

QT  += sql
QT += network
