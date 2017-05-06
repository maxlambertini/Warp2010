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
TARGET = Warp2010
TEMPLATE = app
QMAKE_CXXFLAGS += -Wall -Wextra -O3 -Wunused-parameter
INCLUDEPATH += $$PWD/../libnoise/src
DEPENDPATH += $$PWD/../libnoise/src
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
    mainscenehandler.cpp \
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
    cluster/clusteritem.cpp \
    cluster/cluster.cpp \
    cluster/diasporaclusterscene.cpp \
    diasporaclusterdialog.cpp \
    cluster/diasporaclustergraphicsitem.cpp \
    sceneimageexporter.cpp \
    cluster/aspect.cpp \
    cluster/aspectlist.cpp \
    cluster/aspectgraphicsitem.cpp \
    clusteritemeditor.cpp \
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
    helpers/matrixbuilder.cpp \
    helpers/parsecstarlisthelper.cpp \
    helpers/graphmlexporter.cpp \
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
    ../libnoise/src/noise/win32/dllmain.cpp \
    ../libnoise/src/noise/latlon.cpp \
    ../libnoise/src/noise/noisegen.cpp \
    ../libnoise/src/noiseutils.cpp \
    dialogs/noisemapplaygrounddialog.cpp \
    helpers/noiseimageutils.cpp \
    helpers/noiseimagerunner.cpp \
    helpers/planetmaps/earthlike.cpp \
    helpers/planetmaps/abstractmap.cpp \
    helpers/planetmaps/earthlike2.cpp \
    helpers/planetmaps/earthlike3.cpp \
    helpers/planetmaps/earthlikepeaks.cpp \
    helpers/planetmaps/alienpeaks.cpp \
    helpers/planetmaps/desert.cpp \
    helpers/planetmaps/desertg.cpp \
    helpers/planetmaps/gg2.cpp \
    helpers/planetmaps/cloudy.cpp \
    helpers/planetmaps/gasgiant.cpp \
    helpers/planetmaps/Clouds/earthclouds.cpp \
    helpers/planetmaps/Clouds/funkyclouds.cpp
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
    mainscenehandler.h \
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
    cluster/clusteritem.h \
    cluster/cluster.h \
    cluster/diasporaclusterscene.h \
    diasporaclusterdialog.h \
    cluster/diasporaclustergraphicsitem.h \
    sceneimageexporter.h \
    cluster/aspect.h \
    cluster/aspectlist.h \
    cluster/aspectgraphicsitem.h \
    clusteritemeditor.h \
    appmessage.h \
    exporters/clusterhtmlexporter.h \
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
    models/clusteritemreachdata.h \
    models/clusteritemreachmodel.h \
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
    helpers/matrixbuilder.h \
    helpers/parsecstarlisthelper.h \
    helpers/graphmlexporter.h \
    dialogs/noisemapplaygrounddialog.h \
    helpers/noiseimageutils.h \
    helpers/noiseimagerunner.h \
    helpers/qcolorops.h \
    helpers/planetmaps/earthlike.h \
    helpers/planetmaps/abstractmap.h \
    helpers/planetmaps/earthlike2.h \
    helpers/planetmaps/earthlike3.h \
    helpers/planetmaps/maps.h \
    helpers/planetmaps/earthlikepeaks.h \
    helpers/planetmaps/alienpeaks.h \
    helpers/planetmaps/desert.h \
    helpers/planetmaps/desertg.h \
    helpers/planetmaps/gg2.h \
    helpers/planetmaps/cloudy.h \
    helpers/planetmaps/gasgiant.h \
    helpers/planetmaps/Clouds/earthclouds.h \
    helpers/planetmaps/Clouds/funkyclouds.h
FORMS += warpmainwindow.ui \
    diasporaclusterdialog.ui \
    dialogs/printingsetup.ui \
    clusteritemeditor.ui \
    dialogs/traderoutedialog.ui \
    dialogs/preferencesdialog.ui \
    dialogs/createtraderoutedialog.ui \
    dialogs/newsectordialog.ui \
    widgets/fontpreviewwidget.ui \
    widgets/solsysinspector.ui \
    widgets/solarsystemviewwidget.ui \
    dialogs/createnewstardlg.ui \
    dialogs/createbetweenstarsdlg.ui \
    dialogs/noisemapplaygrounddialog.ui
RESOURCES += Resources.qrc
win32:RC_FILE = warp2010.rc
win32:CONFIG += console
DISTFILES += test.tpl \
    aspects.aspect \
    LICENSE.GPL
