#-------------------------------------------------
#
# Project created by QtCreator 2017-05-21T08:41:18
#
#-------------------------------------------------

QT       += core gui

TARGET = libnoise-warp
TEMPLATE = lib

DEFINES += LIBNOISEWARP_LIBRARY

INCLUDEPATH += $$PWD/../libnoise/src
DEPENDPATH += $$PWD/../libnoise/src

QMAKE_CXXFLAGS += -Wall -Wextra -O3 -Wno-reorder -Wno-attributes -Wno-unused-parameter  -Wno-reorder

SOURCES += \
    ../libnoise/src/noise/model/cylinder.cpp \
    ../libnoise/src/noise/model/line.cpp \
    ../libnoise/src/noise/model/plane.cpp \
    ../libnoise/src/noise/model/sphere.cpp \
    ../libnoise/src/noise/module/abs.cpp \
    ../libnoise/src/noise/module/add.cpp \
    ../libnoise/src/noise/module/billow.cpp \
    ../libnoise/src/noise/module/blend.cpp \
    ../libnoise/src/noise/module/cache.cpp \
    ../libnoise/src/noise/module/checkerboard.cpp \
    ../libnoise/src/noise/module/clamp.cpp \
    ../libnoise/src/noise/module/const.cpp \
    ../libnoise/src/noise/module/curve.cpp \
    ../libnoise/src/noise/module/cylinders.cpp \
    ../libnoise/src/noise/module/displace.cpp \
    ../libnoise/src/noise/module/exponent.cpp \
    ../libnoise/src/noise/module/invert.cpp \
    ../libnoise/src/noise/module/max.cpp \
    ../libnoise/src/noise/module/min.cpp \
    ../libnoise/src/noise/module/modulebase.cpp \
    ../libnoise/src/noise/module/multiply.cpp \
    ../libnoise/src/noise/module/perlin.cpp \
    ../libnoise/src/noise/module/power.cpp \
    ../libnoise/src/noise/module/ridgedmulti.cpp \
    ../libnoise/src/noise/module/rotatepoint.cpp \
    ../libnoise/src/noise/module/scalebias.cpp \
    ../libnoise/src/noise/module/scalepoint.cpp \
    ../libnoise/src/noise/module/select.cpp \
    ../libnoise/src/noise/module/spheres.cpp \
    ../libnoise/src/noise/module/terrace.cpp \
    ../libnoise/src/noise/module/translatepoint.cpp \
    ../libnoise/src/noise/module/turbulence.cpp \
    ../libnoise/src/noise/module/voronoi.cpp \
    ../libnoise/src/noise/latlon.cpp \
    ../libnoise/src/noise/noisegen.cpp \
    ../libnoise/src/noiseutils.cpp

HEADERS +=


unix {
    target.path = /usr/lib
    INSTALLS += target
}
