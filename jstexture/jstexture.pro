#-------------------------------------------------
#
# Project created by QtCreator 2017-05-21T22:34:54
#
#-------------------------------------------------

QT       += core gui
CONFIG += cpp11


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jstexture
TEMPLATE = app

#INCLUDEPATH += $$PWD/../libnoise/src $$PWD/../libnoise-helpers
#Release:LIBS += -L$$PWD/../builds/release/libnoise-warp -L$$PWD/../builds/release/libnoise-helpers -llibnoise-warp -llibnoise-helpers
#Debug:LIBS += -L$$PWD/../builds/debug/libnoise-warp -L$$PWD/../builds/debug/libnoise-helpers -llibnoise-warp -llibnoise-helpers

# include($$PWD/QtGradientEditor/qtcolorbutton.pri)
include($$PWD/QtGradientEditor/qtgradienteditor.pri)

SOURCES += main.cpp\
        mainwindow.cpp \
    apppaths.cpp \
    viewingdialog.cpp \
    createmoduledescriptorjson.cpp \
    heightmapbuilderwidget.cpp \
    heightmapbuilderdialog.cpp \
    qrendererdescwidget.cpp \
    rendererdescdialog.cpp

HEADERS  += mainwindow.h \
    apppaths.h \
    viewingdialog.h \
    createmoduledescriptorjson.h \
    heightmapbuilderwidget.h \
    heightmapbuilderdialog.h \
    qrendererdescwidget.h \
    rendererdescdialog.h

FORMS    += mainwindow.ui \
    viewingdialog.ui \
    createmoduledescriptorjson.ui \
    heightmapbuilderdialog.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libnoise-helpers/release/ -llibnoise-helpers
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libnoise-helpers/debug/ -llibnoise-helpers
else:unix: LIBS += -L$$OUT_PWD/../libnoise-helpers/ -llibnoise-helpers

INCLUDEPATH += $$PWD/../libnoise-helpers
DEPENDPATH += $$PWD/../libnoise-helpers

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libnoise-warp/release/ -llibnoise-warp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libnoise-warp/debug/ -llibnoise-warp
else:unix: LIBS += -L$$OUT_PWD/../libnoise-warp/ -llibnoise-warp

INCLUDEPATH += $$PWD/../libnoise/src
DEPENDPATH += $$PWD/../libnoise/src
