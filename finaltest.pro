#-------------------------------------------------
#
# Project created by QtCreator 2022-05-23T15:16:09
#
#-------------------------------------------------

QT       += core gui sql
QT        += serialport

TARGET = finaltest
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    ATSysDatabaseControl.cpp \
    zhujiemian.cpp \
    menu.cpp \
    zhuce.cpp \
    change.cpp \
    mainwindow.cpp \
    group.cpp

HEADERS  += widget.h \
    ATSysDatabaseControl.h \
    zhujiemian.h \
    menu.h \
    zhuce.h \
    change.h \
    mainwindow.h \
    group.h

FORMS    += widget.ui \
    zhujiemian.ui \
    menu.ui \
    zhuce.ui \
    change.ui \
    mainwindow.ui \
    group.ui

RESOURCES += \
    res.qrc \
    icom.qrc \
    pic.qrc
