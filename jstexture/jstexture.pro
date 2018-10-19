#-------------------------------------------------
#
# Project created by QtCreator 2017-05-21T22:34:54
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++14
QMAKE_CXXFLAGS += -Wall -Wextra -O3 -Wunused-parameter -pedantic



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
    heightmapbuilderwidget.cpp \
    heightmapbuilderdialog.cpp \
    qrendererdescwidget.cpp \
    rendererdescdialog.cpp \
    texturebuilderexplorer.cpp \
    qmoduledescwidget.cpp \
    qmoduledescdialog.cpp \
    gradienthelper.cpp \
    texturebuilderwidget.cpp \
    texturebuilderdialog.cpp \
    addtextureworkflowwidget.cpp \
    addtextureworkflowdialog.cpp

HEADERS  += mainwindow.h \
    apppaths.h \
    viewingdialog.h \
    heightmapbuilderwidget.h \
    heightmapbuilderdialog.h \
    qrendererdescwidget.h \
    rendererdescdialog.h \
    texturebuilderexplorer.h \
    qmoduledescwidget.h \
    qmoduledescdialog.h \
    gradienthelper.h \
    texturebuilderwidget.h \
    texturebuilderdialog.h \
    addtextureworkflowwidget.h \
    addtextureworkflowdialog.h

FORMS    += mainwindow.ui \
    viewingdialog.ui \
    createmoduledescriptorjson.ui \
    heightmapbuilderdialog.ui

RESOURCES += resources.qrc

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libnoise-lua/libnoise-lua/release/ -llibnoise-lua
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libnoise-lua/libnoise-lua/debug/ -llibnoise-lua
else:unix: LIBS += -L$$OUT_PWD/../libnoise-lua/libnoise-lua/ -llibnoise-lua

INCLUDEPATH += $$PWD/../libnoise-lua/libnoise-lua/
DEPENDPATH += $$PWD/../libnoise-lua/libnoise-lua/

win32 {
    LIBS += -L$$PWD/../win_lua -llua53
    INCLUDEPATH += $$PWD/../win_lua/include
    QMAKE_CXXFLAGS += -Wa,-mbig-obj
    # DEFINES += SOL_USING_CXX_LUA
}
unix {
    LIBS += -llua5.3
    INCLUDEPATH += /usr/include/lua5.3/
}

