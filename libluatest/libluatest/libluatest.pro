TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt



SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../libnoise-lua/libnoise-lua/release/ -llibnoise-lua
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../libnoise-lua/libnoise-lua/debug/ -llibnoise-lua
else:unix: LIBS += -L$$OUT_PWD/../../libnoise-lua/libnoise-lua/ -llibnoise-lua

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../libnoise-warp/release/ -llibnoise-warp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../libnoise-warp/debug/ -llibnoise-warp
else:unix: LIBS += -L$$OUT_PWD/../../libnoise-warp/ -llibnoise-warp

INCLUDEPATH += $$PWD/../../libnoise/src
DEPENDPATH += $$PWD/../../libnoise/src

INCLUDEPATH += $$PWD/../../libnoise-lua/libnoise-lua/
DEPENDPATH += $$PWD/../../libnoise-lua/libnoise-lua/

win32 {
    LIBS += -L$$PWD/../../win_lua -llua53
    INCLUDEPATH += $$PWD/../../win_lua/include
    QMAKE_CXXFLAGS += -Wa,-mbig-obj
    # DEFINES += SOL_USING_CXX_LUA
}


DISTFILES += \
    test.lua \
    test2.lua
