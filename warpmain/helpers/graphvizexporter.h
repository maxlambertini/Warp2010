#ifndef GRAPHVIZEXPORTER_H
#define GRAPHVIZEXPORTER_H

#include <star.h>
#include <starlist.h>
#include "scenemediator.h"
#include <QString>

class SceneMediator;

class GraphVizExporter
{
    StarList *_starList = 0;
    SceneMediator *_sceneMediator = 0;
    QString      _doc;
    QList<int> _starsInTradeRoutes;
    bool _exportDirectPathOnly = false;
    bool _exportGardenPathOnly = false;

public:
    GraphVizExporter();
    void createGraphVizDoc(QString& filename);

    inline void setStarList(StarList *sl) { _starList = sl; }
    inline void setSceneMediator (SceneMediator *sm) { _sceneMediator = sm; }
    inline void setExportDirectPathOnly (bool b = false) { _exportDirectPathOnly = b; }
    inline void setExportGardenPathOnly (bool b = false) { _exportGardenPathOnly = b; }
    inline void setStarsInTradeRoutes (const QList<int>& s) { _starsInTradeRoutes = s; }

};

#endif // GRAPHVIZEXPORTER_H
