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
    network\chatclient.cpp \
    doctorregisterview.cpp \
    loginview.cpp \
    patientregisterview.cpp \
    doctormainview.cpp \
    selfinfoview.cpp \
    securityinfoview.cpp \
    changepasswordview.cpp \
    doctorlistview.cpp \
    model\jsonmodel.cpp \
    patientinfoview.cpp \
    patientlistview.cpp \
    treatview.cpp \
    treatlistview.cpp \
    treatinfoview.cpp \
    chosepatientview.cpp \
    patientmainview.cpp

HEADERS  += \
    network\chatclient.h \
    doctorregisterview.h \
    loginview.h \
    patientregisterview.h \
    doctormainview.h \
    selfinfoview.h \
    securityinfoview.h \
    changepasswordview.h \
    doctorlistview.h \
    model\jsonmodel.h \
    patientinfoview.h \
    patientlistview.h \
    treatview.h \
    treatlistview.h \
    treatinfoview.h \
    chosepatientview.h \
    patientmainview.h

FORMS    += \
    doctorregisterview.ui \
    loginview.ui \
    patientregisterview.ui \
    doctormainview.ui \
    selfinfoview.ui \
    securityinfoview.ui \
    changepasswordview.ui \
    doctorlistview.ui \
    patientinfoview.ui \
    patientlistview.ui \
    treatview.ui \
    treatlistview.ui \
    treatinfoview.ui \
    chosepatientview.ui \
    patientmainview.ui

QT  += sql
QT += network

RESOURCES += \
    resource.qrc
