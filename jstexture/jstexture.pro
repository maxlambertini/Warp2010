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
LIBS += -L$$PWD/../build/Libnoise/Release -L$$PWD/../build/Libnoise-Helpers/Release -llibnoise-warp -llibnoise-helpers


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
