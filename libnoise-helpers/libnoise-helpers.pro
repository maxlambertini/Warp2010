#-------------------------------------------------
#
# Project created by QtCreator 2017-05-21T09:35:04
#
#-------------------------------------------------

QT += core gui widgets

TARGET = libnoise-helpers
TEMPLATE = lib

INCLUDEPATH += $$PWD/../libnoise/src $$PWD/../warpmain

LIBS += -L$$PWD/../build/Libnoise/Release -llibnoise-warp


DEFINES += LIBNOISEHELPERS_LIBRARY

HEADERS += libnoisehelpers.h\
        planetmaps/earthlike.h \
        planetmaps/abstractmap.h \
        planetmaps/earthlike2.h \
        planetmaps/earthlike3.h \
        planetmaps/maps.h \
        planetmaps/earthlikepeaks.h \
        planetmaps/alienpeaks.h \
        planetmaps/desert.h \
        planetmaps/desertg.h \
        planetmaps/gg2.h \
        planetmaps/cloudy.h \
        planetmaps/gasgiant.h \
        planetmaps/Clouds/earthclouds.h \
        planetmaps/Clouds/funkyclouds.h \
        planetmaps/jade.h \
        planetmaps/jade2.h \
        planetmaps/ice.h \
        planetmaps/granite.h \
        texturebuilder/moduledescriptor.h \
        texturebuilder/noisemapbuilderdescriptor.h \
        texturebuilder/imagedescriptor.h \
        texturebuilder/rendererdescriptor.h \
        texturebuilder/heightmapdescriptor.h \
        texturebuilder/texturebuilder.h \
        libnoise-helpers_global.h \
        qcolorops.h \
        noiseimageutils.h \
        ssg_structures.h



unix {
    target.path = /usr/lib
    INSTALLS += target
}

SOURCES += \
    planetmaps/Clouds/earthclouds.cpp \
    planetmaps/Clouds/funkyclouds.cpp \
    planetmaps/abstractmap.cpp \
    planetmaps/alienpeaks.cpp \
    planetmaps/cloudy.cpp \
    planetmaps/desert.cpp \
    planetmaps/desertg.cpp \
    planetmaps/earthlike.cpp \
    planetmaps/earthlike2.cpp \
    planetmaps/earthlike3.cpp \
    planetmaps/earthlikepeaks.cpp \
    planetmaps/gasgiant.cpp \
    planetmaps/gg2.cpp \
    planetmaps/granite.cpp \
    planetmaps/ice.cpp \
    planetmaps/jade.cpp \
    planetmaps/jade2.cpp \
    texturebuilder/heightmapdescriptor.cpp \
    texturebuilder/imagedescriptor.cpp \
    texturebuilder/moduledescriptor.cpp \
    texturebuilder/noisemapbuilderdescriptor.cpp \
    texturebuilder/rendererdescriptor.cpp \
    texturebuilder/texturebuilder.cpp \
    libnoisehelpers.cpp \
    noiseimageutils.cpp

