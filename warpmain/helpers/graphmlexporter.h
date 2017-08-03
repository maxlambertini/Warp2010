#ifndef GRAPHMLEXPORTER_H
#define GRAPHMLEXPORTER_H

#include "star.h"
#include "starlist.h"
#include <QString>



class GraphMLExporter
{
private:
    StarList *_starList = 0;
    QString      _docTemplate, _nodeTemplate, _edgeTemplate, _edge2Template;
    QStringList  _edges, _edges2, _nodes;
    QString      _doc;
    QList<int> _starsInTradeRoutes;

    void loadTemplates();

    void fillNode (int i1, int width=160, int height=160, const QString& borderColor="#000000",
                   int borderWidth=1, int fontSize=18, const QString& textColor="#000000", const QString& fillColor="#ffff00",
                   const QString& nodeName = "");
    void fillEdge (int eID, int i1, int i2, const QString& lineColor = "#808080", int nWidth = 5, int fontSize=15);
    void generateNodes(int nFontSize, Star* star, QVector<int>& lstInMap, int nCount);

    void generateMainEdges(QStringList& links, Star* star);

    void generateSecondaryEdges(QVector<int>& lstInMap, Star* star, int nCount, QStringList& links);

    bool _exportDirectPathOnly = false;
    bool _exportGardenPathOnly = false;

public:
    void fillEdge2 (int eID, int i1, int i2, const QString& lineColor = "#808080", int nWidth = 5, int fontSize=15);
public:
    GraphMLExporter();
    QString& createGraphicsMLDocs(QString &filename);

    inline void setStarList(StarList *sl) { _starList = sl; }
    inline void setExportDirectPathOnly (bool b = false) { _exportDirectPathOnly = b; }
    inline void setExportGardenPathOnly (bool b = false) { _exportGardenPathOnly = b; }
    inline void setStarsInTradeRoutes (const QList<int>& s) { _starsInTradeRoutes = s; }

};

#endif // GRAPHMLEXPORTER_H
