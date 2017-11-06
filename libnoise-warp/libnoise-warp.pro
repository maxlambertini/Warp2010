#-------------------------------------------------
#
# Project created by QtCreator 2017-05-21T08:41:18
#
#-------------------------------------------------


TARGET = libnoise-warp
TEMPLATE = lib
CONFIG += c++14

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
    ../libnoise/src/noise/module/avg.cpp \
    ../libnoise/src/noise/module/min.cpp \
    ../libnoise/src/noise/module/modulebase.cpp \
    ../libnoise/src/noise/module/multiply.cpp \
    ../libnoise/src/noise/module/perlin.cpp \
    ../libnoise/src/noise/module/power.cpp \
    ../libnoise/src/noise/module/ridgedmulti.cpp \
    ../libnoise/src/noise/module/ridgedmulti2.cpp \
    ../libnoise/src/noise/module/rotatepoint.cpp \
    ../libnoise/src/noise/module/scalebias.cpp \
    ../libnoise/src/noise/module/scalepoint.cpp \
    ../libnoise/src/noise/module/select.cpp \
    ../libnoise/src/noise/module/spheres.cpp \
    ../libnoise/src/noise/module/terrace.cpp \
    ../libnoise/src/noise/module/translatepoint.cpp \
    ../libnoise/src/noise/module/turbulence.cpp \
    ../libnoise/src/noise/module/turbulence2.cpp \
    ../libnoise/src/noise/module/turbulence_ridged.cpp \
    ../libnoise/src/noise/module/turbulence_billow.cpp \
    ../libnoise/src/noise/module/voronoi.cpp \
    ../libnoise/src/noise/module/cos.cpp \
    ../libnoise/src/noise/latlon.cpp \
    ../libnoise/src/noise/noisegen.cpp \
    ../libnoise/src/noiseutils.cpp

HEADERS += \
    ../libnoise/src/noise/model/cylinder.h \
    ../libnoise/src/noise/model/line.h \
    ../libnoise/src/noise/model/plane.h \
    ../libnoise/src/noise/model/sphere.h \
    ../libnoise/src/noise/module/module.h \
    ../libnoise/src/noise/module/abs.h \
    ../libnoise/src/noise/module/add.h \
    ../libnoise/src/noise/module/billow.h \
    ../libnoise/src/noise/module/blend.h \
    ../libnoise/src/noise/module/cache.h \
    ../libnoise/src/noise/module/checkerboard.h \
    ../libnoise/src/noise/module/clamp.h \
    ../libnoise/src/noise/module/const.h \
    ../libnoise/src/noise/module/curve.h \
    ../libnoise/src/noise/module/cylinders.h \
    ../libnoise/src/noise/module/displace.h \
    ../libnoise/src/noise/module/exponent.h \
    ../libnoise/src/noise/module/invert.h \
    ../libnoise/src/noise/module/max.h \
    ../libnoise/src/noise/module/avg.h \
    ../libnoise/src/noise/module/min.h \
    ../libnoise/src/noise/module/modulebase.h \
    ../libnoise/src/noise/module/multiply.h \
    ../libnoise/src/noise/module/perlin.h \
    ../libnoise/src/noise/module/power.h \
    ../libnoise/src/noise/module/ridgedmulti.h \
    ../libnoise/src/noise/module/ridgedmulti2.h \
    ../libnoise/src/noise/module/rotatepoint.h \
    ../libnoise/src/noise/module/scalebias.h \
    ../libnoise/src/noise/module/scalepoint.h \
    ../libnoise/src/noise/module/select.h \
    ../libnoise/src/noise/module/spheres.h \
    ../libnoise/src/noise/module/terrace.h \
    ../libnoise/src/noise/module/translatepoint.h \
    ../libnoise/src/noise/module/turbulence.h \
    ../libnoise/src/noise/module/turbulence2.h \
    ../libnoise/src/noise/module/turbulence_ridged.h \
    ../libnoise/src/noise/module/turbulence_billow.h \
    ../libnoise/src/noise/module/cos.h \
    ../libnoise/src/noise/module/voronoi.h \
    ../libnoise/src/noise/latlon.h \
    ../libnoise/src/noise/noisegen.h \
    ../libnoise/src/noise/noise.h \
    ../libnoise/src/noiseutils.h



unix {
    target.path = /usr/lib
    INSTALLS += target
}
