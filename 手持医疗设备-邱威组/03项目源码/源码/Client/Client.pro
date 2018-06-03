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
    electrocardiograph.cpp\
    examinationlist.cpp \
    temperatureview.cpp \
    examinationinfoview.cpp\
    caculator/widget.cpp\
    caculator/science.cpp\
    player/player.cpp\
    drawing/mainwindow.cpp\
    Map/map.cpp\

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
    electrocardiograph.h\
    examinationlist.h \
    temperatureview.h \
    examinationinfoview.h\
    caculator/widget.h\
    caculator/science.h\
    player/player.h\
    drawing/mainwindow.h\
    Map/map.h\

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
    electrocardiograph.ui\
    examinationlist.ui \
    temperatureview.ui \
    examinationinfoview.ui\
    caculator/widget.ui\
    caculator/science.ui\
    player/player.ui\
    drawing/mainwindow.ui\
    Map/map.ui\


RESOURCES += \
    resource.qrc\
    caculator/ground.qrc\
    player/1.qrc\
    Map/2.qrc

OTHER_FILES += \
    styleSheet/pithy.qss


QT  += sql
QT += network
QT += phonon
