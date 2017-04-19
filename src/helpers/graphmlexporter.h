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


    void loadTemplates();

    void fillNode (int i1, int width=160, int height=160, const QString& borderColor="#000000",
                   int borderWidth=1, int fontSize=18, const QString& textColor="#000000", const QString& fillColor="#ffff00");
    void fillEdge (int eID, int i1, int i2, const QString& lineColor = "#808080", int nWidth = 5, int fontSize=15);
    void generateNodes(int nFontSize, Star* star, QVector<int>& lstInMap, int nCount);

    void generateMainEdges(QStringList& links, Star* star);

    void generateSecondaryEdges(QVector<int>& lstInMap, Star* star, int nCount, QStringList& links);

public:
    void fillEdge2 (int eID, int i1, int i2, const QString& lineColor = "#808080", int nWidth = 5, int fontSize=15);
public:
    GraphMLExporter();
    inline void setStarList(StarList *sl) { _starList = sl; }
    QString& createGraphicsMLDocs(QString &filename);
};

#endif // GRAPHMLEXPORTER_H
