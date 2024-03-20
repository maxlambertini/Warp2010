#-------------------------------------------------
#
# Project created by QtCreator 2017-05-21T09:35:04
#
#-------------------------------------------------

QT += core gui widgets

TARGET = libnoise-helpers
TEMPLATE = lib
CONFIG += c++20

QMAKE_CXXFLAGS += -Wall -Wextra -pedantic -ansi -O3 -Wno-reorder -Wno-attributes -Wno-unused-parameter  -Wno-reorder


DEFINES += LIBNOISEHELPERS_LIBRARY

HEADERS += libnoisehelpers.h\
        texturebuilder/moduledescriptor.h \
        texturebuilder/noisemapbuilderdescriptor.h \
        texturebuilder/imagedescriptor.h \
        texturebuilder/rendererdescriptor.h \
        texturebuilder/heightmapdescriptor.h \
        texturebuilder/texturebuilder.h \
        libnoise-helpers_global.h \
        qcolorops.h \
        noiseimageutils.h \
        ssg_structures.h \
    ringtexturebuilder.h



unix {
    target.path = /usr/lib
    INSTALLS += target
}

SOURCES += \
    texturebuilder/heightmapdescriptor.cpp \
    texturebuilder/imagedescriptor.cpp \
    texturebuilder/moduledescriptor.cpp \
    texturebuilder/noisemapbuilderdescriptor.cpp \
    texturebuilder/rendererdescriptor.cpp \
    texturebuilder/texturebuilder.cpp \
    libnoisehelpers.cpp \
    noiseimageutils.cpp \
    ringtexturebuilder.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libnoise-warp/release/ -llibnoise-warp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libnoise-warp/debug/ -llibnoise-warp
else:unix: LIBS += -L$$OUT_PWD/../libnoise-warp/ -llibnoise-warp

INCLUDEPATH += $$PWD/../libnoise/src
DEPENDPATH += $$PWD/../libnoise/src
