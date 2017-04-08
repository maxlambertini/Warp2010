#ifndef GRAPHMLEXPORTER_H
#define GRAPHMLEXPORTER_H

#include "star.h"
#include "starlist.h"
#include <QString>

class GraphMLExporter
{
private:
    StarList *_starList = 0;
    QString      _docTemplate, _nodeTemplate, _edgeTemplate;
    QStringList  _edges, _nodes;
    QString      _doc;

    void loadTemplates();

    void fillNode (int i1);
    void fillEdge (int i1, int i2, const QString& lineColor = "#808080", int nWidth = 5, int fontSize=15);
public:
    GraphMLExporter();
    inline void setStarList(StarList *sl) { _starList = sl; }
    QString& createGraphicsMLDocs();
};

#endif // GRAPHMLEXPORTER_H
