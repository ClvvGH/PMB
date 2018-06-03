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
    network/chatclient.cpp \
    doctorregisterview.cpp \
    loginview.cpp\
    patientregisterview.cpp \
    doctormainview.cpp \
    patientmainview.cpp \
    selfinfoview.cpp\
    securityinfoview.cpp \
    changepasswordview.cpp\
    chosepatientview.cpp\
    doctorlistview.cpp\
    patientinfoview.cpp\
    patientlistview.cpp\
    treatinfoview.cpp\
    treatlistview.cpp\
    treatview.cpp\

HEADERS  += \
    network/chatclient.h \
    doctorregisterview.h \
    loginview.h \
    patientregisterview.h\
    doctormainview.h \
    patientmainview.h \
    selfinfoview.h \
    securityinfoview.h\
    changepasswordview.h\
    chosepatientview.h\
    doctorlistview.h\
    patientinfoview.h\
    patientlistview.h\
    treatinfoview.h\
    treatlistview.h\
    treatview.h\

FORMS    += \
    doctorregisterview.ui \
    loginview.ui \
    patientregisterview.ui \
    doctormainview.ui \
    patientmainview.ui \
    selfinfoview.ui \
    securityinfoview.ui\
    changepasswordview.ui\
    chosepatientview.ui\
    doctorlistview.ui\
    patientinfoview.ui\
    patientlistview.ui\
    treatinfoview.ui\
    treatlistview.ui\
    treatview.ui\

QT  += sql
QT += network

RESOURCES += \
    resource.qrc
