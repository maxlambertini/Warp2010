#-------------------------------------------------
#
# Project created by QtCreator 2017-05-21T13:29:34
#
#-------------------------------------------------

QT       += widgets svg gui core printsupport

TARGET = diaspora-widgets
TEMPLATE = lib

DEFINES += DIASPORAWIDGETS_LIBRARY

SOURCES += diasporawidgets.cpp \
    onomastikon.cpp \
    diasporaclusterdialog.cpp \
    cluster/aspect.cpp \
    cluster/aspectgraphicsitem.cpp \
    cluster/aspectlist.cpp \
    cluster/cluster.cpp \
    cluster/clusteritem.cpp \
    cluster/diasporaclustergraphicsitem.cpp \
    cluster/diasporaclusterscene.cpp \
    clusteritemeditor.cpp \
    clusterhtmlexporter.cpp \
    diasporapaths.cpp \
    diasporamessage.cpp \
    diasporadefaultfonts.cpp \
    models/clusteritemreachdata.cpp \
    models/clusteritemreachmodel.cpp

HEADERS += diasporawidgets.h\
        diaspora-widgets_global.h \
    diasporaclusterdialog.h \
    onomastikon.h \
    cluster/aspect.h \
    cluster/aspectgraphicsitem.h \
    cluster/aspectlist.h \
    cluster/cluster.h \
    cluster/clusteritem.h \
    cluster/diasporaclustergraphicsitem.h \
    cluster/diasporaclusterscene.h \
    ssg_structures.h \
    clusteritemeditor.h \
    clusterhtmlexporter.h \
    diasporapaths.h \
    diasporamessage.h \
    diasporadefaultfonts.h \
    models/clusteritemreachdata.h \
    models/clusteritemreachmodel.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    diasporaclusterdialog.ui \
    clusteritemeditor.ui

RESOURCES += \
    ../warpmain/Resources.qrc
