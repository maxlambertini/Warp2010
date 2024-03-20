# ###########################################################################
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
# GNU General Public License Usage
# This file may be used under the terms of the GNU
# General Public License version 3.0 as published by the Free Software
# Foundation and appearing in the file LICENSE.GPL included in the
# packaging of this file. Please review the following information to
# ensure the GNU General Public License version 3.0 requirements will be
# met: http://www.gnu.org/copyleft/gpl.html.
# ###########################################################################
# -------------------------------------------------
# Project created by QtCreator 2009-03-31T07:42:33
# -------------------------------------------------

QT += printsupport widgets svg concurrent
TARGET = WarpNow
TEMPLATE = app
QMAKE_CXXFLAGS += -Wall -Wextra -O3 -Wunused-parameter -pedantic
CONFIG += c++20

SOURCES += main.cpp \
    coordinates.cpp \
    star.cpp \
    planet.cpp \
    orbit.cpp \
    starlist.cpp \
    starmapwidget.cpp \
    warpmainwindowform.cpp \
    starwidgetitem.cpp \
    stargraphicsitem.cpp \
    traderoute.cpp \
    solarsystemcreator.cpp \
    traderoutemediator.cpp \
    qtcolorpicker.cpp \
    traderoutewidgetitem.cpp \
    solarsystemwidget.cpp \
    onomastikon.cpp \
    traderoutereportwriter.cpp \
    starhexgraphicsitem.cpp \
    celestiaexporter.cpp \
    ssg_structures.cpp \
    sceneimageexporter.cpp \
    appmessage.cpp \
    exporters/clusterhtmlexporter.cpp \
    helpers/progressbarhelper.cpp \
    helpers/preferences.cpp \
    helpers/printingpreferences.cpp \
    dialogs/printingsetup.cpp \
    helpers/splashscreen.cpp \
    dialogs/traderoutedialog.cpp \
    dialogs/preferencesdialog.cpp \
    dialogs/newsectordialog.cpp \
    dialogs/createtraderoutedialog.cpp \
    helpers/sectorrectholder.cpp \
    models/clusteritemreachdata.cpp \
    models/clusteritemreachmodel.cpp \
    widgets/fontpreviewwidget.cpp \
    gfx_items/arcgraphicsitem.cpp \
    helpers/apppaths.cpp \
    widgets/solsysinspector.cpp \
    widgets/starinspector.cpp \
    widgets/basicstarinfowidget.cpp \
    widgets/planetaryinspector.cpp \
    helpers/pixmaphelper.cpp \
    gfx_items/planetgraphicsitem.cpp \
    helpers/solarsystemtoscene.cpp \
    widgets/solarsystemviewwidget.cpp \
    helpers/planetselector.cpp \
    warpmainwindowform_actions.cpp \
    helpers/startodiasporasummary.cpp \
    helpers/diasporaitemtostar.cpp \
    dialogs/createnewstardlg.cpp \
    helpers/starcodehelper.cpp \
    dialogs/createbetweenstarsdlg.cpp \
    helpers/planetrenderer.cpp \
    helpers/parsecstarlisthelper.cpp \
    helpers/graphmlexporter.cpp \
    helpers/noiseimagerunner.cpp \
    exporters/starsectorjsonexporter.cpp \
    widgets/actionbutton.cpp \
    scenemediator.cpp \
    dialogs/sectorexportoptionsdialog.cpp \
    helpers/graphvizexporter.cpp \
    parsecstar.cpp
HEADERS += coordinates.h \
    star.h \
    planet.h \
    orbit.h \
    starlist.h \
    starmapwidget.h \
    warpmainwindowform.h \
    starwidgetitem.h \
    stargraphicsitem.h \
    traderoute.h \
    ssg_structures.h \
    solarsystemcreator.h \
    traderoutemediator.h \
    qtcolorpicker.h \
    traderoutewidgetitem.h \
    warpexception.h \
    solarsystemwidget.h \
    onomastikon.h \
    traderoutereportwriter.h \
    starhexgraphicsitem.h \
    sceneimageexporter.h \
    appmessage.h \
    celestiaexporter.h \
    helpers/progressbarhelper.h \
    helpers/preferences.h \
    helpers/printingpreferences.h \
    dialogs/printingsetup.h \
    helpers/splashscreen.h \
    dialogs/traderoutedialog.h \
    dialogs/preferencesdialog.h \
    dialogs/newsectordialog.h \
    dialogs/createtraderoutedialog.h \
    helpers/sectorrectholder.h \
    widgets/fontpreviewwidget.h \
    gfx_items/arcgraphicsitem.h \
    helpers/apppaths.h \
    widgets/solsysinspector.h \
    widgets/starinspector.h \
    widgets/basicstarinfowidget.h \
    widgets/planetaryinspector.h \
    helpers/pixmaphelper.h \
    gfx_items/planetgraphicsitem.h \
    helpers/solarsystemtoscene.h \
    widgets/solarsystemviewwidget.h \
    helpers/planetselector.h \
    helpers/startodiasporasummary.h \
    helpers/diasporaitemtostar.h \
    dialogs/createnewstardlg.h \
    helpers/starcodehelper.h \
    dialogs/createbetweenstarsdlg.h \
    helpers/planetrenderer.h \
    helpers/parsecstarlisthelper.h \
    helpers/graphmlexporter.h \
    helpers/noiseimagerunner.h \
    exporters/starsectorjsonexporter.h \
    widgets/actionbutton.h \
    scenemediator.h \
    dialogs/sectorexportoptionsdialog.h \
    helpers/graphvizexporter.h \
    parsecstar.h
FORMS += warpmainwindow.ui \
    dialogs/printingsetup.ui \
    dialogs/traderoutedialog.ui \
    dialogs/preferencesdialog.ui \
    dialogs/createtraderoutedialog.ui \
    dialogs/newsectordialog.ui \
    widgets/fontpreviewwidget.ui \
    widgets/solsysinspector.ui \
    widgets/solarsystemviewwidget.ui \
    dialogs/createnewstardlg.ui \
    dialogs/createbetweenstarsdlg.ui
RESOURCES += Resources.qrc
#win32:RC_FILE = warpmain.rc
#win32:CONFIG += console

DISTFILES += test.tpl \
    aspects.aspect \
    LICENSE.LGPL \
    textures/chunk/*.texjson \
    textures/clouds/*.texjson \
    textures/clouds-alien/*.texjson \
    textures/desert/*.texjson \
    textures/rockball/*.texjson \
    textures/hothouse/*.texjson \
    textures/garden/*.texjson \
    textures/pregarden/*.texjson \
    textures/postgarden/*.texjson \
    textures/glacier/*.texjson \
    textures/rockball/*.texjson \
    textures/failedcore/*.texjson \
    textures/gasgiant/*.texjson \
    celestia/testplanet.tpl \
    yed/*

texjson.path=$${UtilsOUT_PWD}/textures
texjson.files=textures/*

#INSTALLS += texjson

win32 {
win32:CONFIG(release, debug|release):copydata.commands = $$shell_path($(COPY_DIR) $$PWD/textures) $$shell_path($$OUT_PWD/release/textures)
win32:CONFIG(debug, debug|release):  copydata.commands = $$shell_path($(COPY_DIR) $$PWD/textures) $$shell_path($$OUT_PWD/debug/)
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
}
else {
copydata.commands = $(COPY_DIR) $$PWD/textures $$OUT_PWD
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libnoise-warp/release/ -llibnoise-warp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libnoise-warp/debug/ -llibnoise-warp
else:unix: LIBS += -L$$OUT_PWD/../libnoise-warp/ -llibnoise-warp

INCLUDEPATH += $$PWD/../libnoise/src
DEPENDPATH += $$PWD/../libnoise/src


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libnoise-helpers/release/ -llibnoise-helpers
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libnoise-helpers/debug/ -llibnoise-helpers
else:unix: LIBS += -L$$OUT_PWD/../libnoise-helpers/ -llibnoise-helpers

INCLUDEPATH += $$PWD/../libnoise-helpers
DEPENDPATH += $$PWD/../libnoise-helpers

