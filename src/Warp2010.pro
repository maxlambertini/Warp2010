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
QT += svg
TARGET = Warp2010
TEMPLATE = app
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
    helpers/parsecstarlisthelper.cpp
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
    helpers/parsecstarlisthelper.h
FORMS += warpmainwindow.ui \
    diasporaclusterdialog.ui \
    clusteritemeditor.ui \
    dialogs/printingsetup.ui \
    dialogs/traderoutedialog.ui \
    dialogs/preferencesdialog.ui \
    dialogs/newsectordialog.ui \
    dialogs/createtraderoutedialog.ui \
    widgets/fontpreviewwidget.ui \
    widgets/solsysinspector.ui \
    widgets/solarsystemviewwidget.ui \
    dialogs/createnewstardlg.ui \
    dialogs/createbetweenstarsdlg.ui
RESOURCES += Resources.qrc
win32:RC_FILE = warp2010.rc
win32:CONFIG += console
DISTFILES += test.tpl \
    aspects.aspect \
    LICENSE.GPL
