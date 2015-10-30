#-------------------------------------------------
#
# Project created by QtCreator 2015-10-18T12:10:02
#
#-------------------------------------------------


QT = core bluetooth widgets
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DisplayData
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    costumplot.cpp \
    connect_bluetooth.cpp

HEADERS  += mainwindow.h \
    costumplot.h \
    connect_bluetooth.h

FORMS    += mainwindow.ui \
    connect_bluetooth.ui

