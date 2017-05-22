#-------------------------------------------------
#
# Project created by QtCreator 2017-05-21T22:34:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jstexture
TEMPLATE = app

INCLUDEPATH += $$PWD/../libnoise/src $$PWD/../libnoise-helpers
Release:LIBS += -L$$PWD/../builds/libnoise-warp/release -L$$PWD/../builds/libnoise-helpers/release -llibnoise-helpers -llibnoise-warp
Debug:LIBS += -L$$PWD/../builds/libnoise-warp/debug -L$$PWD/../builds/libnoise-helpers/debug -llibnoise-helpers -llibnoise-warp


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
