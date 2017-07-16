#-------------------------------------------------
#
# Project created by QtCreator 2017-07-16T15:05:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    chatclient.cpp

HEADERS  += widget.h \
    chatclient.h

FORMS    += widget.ui

QT  += sql
QT += network
