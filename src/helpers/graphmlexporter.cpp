#include "graphmlexporter.h"
#include "star.h"
#include "starlist.h"

GraphMLExporter::GraphMLExporter()
{
    this->loadTemplates();
    qDebug() << this->_docTemplate;
    qDebug() << this->_edgeTemplate;
    qDebug() << this->_nodeTemplate;
}

void GraphMLExporter::loadTemplates() {
    QResource yedDoc(":/yed/document.tpl");
    QResource yedNode(":/yed/node.tpl");
    QResource yedEdge(":/yed/edge.tpl");
    QResource yedEdge2(":/yed/edge2.tpl");

    QFile docFile(yedDoc.absoluteFilePath());
    QFile nodeFile(yedNode.absoluteFilePath());
    QFile edgeFile(yedEdge.absoluteFilePath());
    QFile edgeFile2(yedEdge2.absoluteFilePath());

    if (!docFile.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Unable to open file: " << docFile.fileName() << " besause of error " << docFile.errorString() << endl;
    if (!nodeFile.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Unable to open file: " << nodeFile.fileName() << " besause of error " << nodeFile.errorString() << endl;
    if (!edgeFile.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Unable to open file: " << edgeFile.fileName() << " besause of error " << edgeFile.errorString() << endl;
    if (!edgeFile2.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Unable to open file: " << edgeFile2.fileName() << " besause of error " << edgeFile2.errorString() << endl;

    QTextStream inDoc(&docFile);
    this->_docTemplate = inDoc.readAll();
    QTextStream inNode(&nodeFile);
    this->_nodeTemplate = inNode.readAll();
    QTextStream inEdge(&edgeFile);
    this->_edgeTemplate = inEdge.readAll();
    QTextStream inEdge2(&edgeFile2);
    this->_edge2Template = inEdge2.readAll();
}

QString& GraphMLExporter::createGraphicsMLDocs(QString &filename) {

    const char * graph_colors[] = {
        "#FF0000",
        "#FF6000",
        "#FFB000",
        "#FFFF00",
        "#B0FF00",
        "#6FFF00",
        "#00FF00",
        "#00BF40",
        "#008F80",
        "#004FB0",
        "#0000FF",
        "#0060FF",
        "#00B0FF",
        "#00FFFF",
        "#00B0B0",
        "#008080",
    };


    int nCount = 0;
    int nFontSize = 15;
    QVector<int> lstInMap;
    QSharedPointer<Star>  star;
    foreach (star, _starList->stars()) {
        if (star->isReference() || star->path().count() > 1) {

            QStringList nameList;
            int l = star->starName.length();
            int rw = l / 10;
            int rm = l % 10;
            for (int hx = 0; hx < rw; hx++) {
                nameList.append(star->starName.mid(hx*10,10));
            }
            nameList.append(star->starName.mid(rw*10,rm));

            //QStringList nameList = star->starName.split(" ");
            int nWidth = 16 * 10;  // * findMaxLen(nameList);
            int nHeight = nameList.count()*25;
            if (star->isReference()) {
                nFontSize = 48;
                nWidth = nWidth*3;
            }
            else
                nFontSize = 18;

            QString sColor = "#EEEEEE";
            QString sFontColor = "#000000";
            switch (star->starType()) {
            case NSStar::StarType::stO:
                sColor = "#CCCCCC";
                break;
            case NSStar::StarType::stB:
                sColor = "#0000FF";
                sFontColor = "#FFFFFF";
                break;
            case NSStar::StarType::stA:
                sColor = "#00FFFF";
                break;
            case NSStar::StarType::stF:
                sColor = "#FFFFFF";
                break;
            case NSStar::StarType::stG:
                sColor = "#FFFF00";
                break;
            case NSStar::StarType::stK:
                sColor = "#FF8000";
                break;
            case NSStar::StarType::stM:
                sColor = "#C00000";
                sFontColor = "#FFFFFF";
                break;
            default:
                break;
            }

            QString sBorderColor;
            int hab = star->habitabilityIndex();
            if (hab >0) {
                QString sBorderColor = "#C07000"; // 1;
                if (star->habitabilityIndex()> 0)
                    sBorderColor = "#30FF30"; // 1;
                if (star->habitabilityIndex()> 1)
                    sBorderColor = "#00FF60"; // 1;
                if (star->habitabilityIndex()> 2)
                    sBorderColor = "#00FFFF"; // 1;
                if (star->habitabilityIndex()> 4)
                    sBorderColor = "#0000FF"; // 1;
            }
            lstInMap.append(nCount);
            this->fillNode(nCount,nWidth,nWidth,sBorderColor,4,18,"#000000",sColor);
            star->setVisited(false);
        }
        nCount++;
    }

    nCount = 0;
    int i1,i2,iTmp;
    QSharedPointer<Star>  p1,p2;
    QStringList links;
    int nEdge = 0;

    qDebug("Set visited");
    foreach (star, _starList->stars())
        star->setVisited(false);

    qDebug("Calc edges");
    int myWidth = 0;
    foreach (star, _starList->stars())
    {
        int pathCount = star->path().count();
        int sPath = 15;
        if (pathCount > 1) {
            for (int w = 1; w < pathCount; w++)
            {
                int myPath = sPath + 1 - w;
                if (myPath < 0) myPath = 0;
                    myWidth = myPath * 2;
                if (myWidth < 5) myWidth = 5;
                QString fillColor = graph_colors[sPath-myPath];
                i1 = star->path().at(w-1);
                i2 = star->path().at(w);
                if (i1 > i2) {
                    iTmp = i1;
                    i1 = i2;
                    i2 = iTmp;
                }
                QString key = QString("%1_%2").arg(i1,i2);
                if (!links.contains(key))
                    links.append(key);
                p1 = _starList->stars().at(i1);
                p2 = _starList->stars().at(i2);

                if (!p1->visited() || !p2->visited())
                {
                    p1->visit();
                    p2->visit();
                    this->fillEdge(++nEdge, i1,i2,fillColor,myWidth);
                }
            }
        }
    }

    foreach (star, _starList->stars()) {
        int iNeighbor;
        foreach (iNeighbor, star->neighbors()) {
            if (iNeighbor > nCount) {
                i1 = nCount;
                i2 = iNeighbor;
            } else {
                i1 = iNeighbor;
                i2 = nCount;
            }
            QString key = QString("%1_%2").arg(i1,i2);
            if (!links.contains(key)) {
                links.append(key);
                p1 = _starList->stars().at(i1);
                p2 = _starList->stars().at(i2);
                if (lstInMap.contains(i1) && lstInMap.contains(i2))
                    this->fillEdge2(++nEdge, i1,i2,"#808080",4,12);
            }
        }

        nCount++;
    }

    QString allEdges = this->_edges.join("\n");
    QString allEdges2 = this->_edges2.join("\n");
    QString allNodes = this->_nodes.join("\n");
    QString allDoc = this->_docTemplate
            .replace("[NODES]",allNodes)
            .replace("[EDGES2]",allEdges2)
            .replace("[EDGES]",allEdges);

    QFile file(filename);
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream output(&file);
        output << allDoc;
    }
    qDebug() << allDoc;
    this->_doc = allDoc;
    return this->_doc;
}

void GraphMLExporter::fillEdge(int eID, int i1, int i2, const QString& lineColor, int nWidth, int fontSize) {
    Star *s1 = this->_starList->stars().at(i1).data();
    Star *s2 = this->_starList->stars().at(i2).data();
    double dist = s1->distance(s2);
    QString res = QString(_edgeTemplate);
    res
            .replace("[EID]",QString::number(eID))
            .replace("[N1]", QString::number(i1))
            .replace("[N2]", QString::number(i2))
            .replace("[LINE_COLOR]", lineColor)
            .replace("[FONT_SIZE]", QString::number(fontSize))
            .replace("[LINE_WIDTH]", QString::number(nWidth))
            .replace("[LABEL]", QString::number(dist,'g',2));
    _edges.append(res);
}

void GraphMLExporter::fillEdge2(int eID, int i1, int i2, const QString& lineColor, int nWidth, int fontSize) {
    Star *s1 = this->_starList->stars().at(i1).data();
    Star *s2 = this->_starList->stars().at(i2).data();
    double dist = s1->distance(s2);
    QString res = QString(_edge2Template);
    res
            .replace("[EID]",QString::number(eID))
            .replace("[N1]", QString::number(i1))
            .replace("[N2]", QString::number(i2))
            .replace("[LINE_COLOR]", lineColor)
            .replace("[FONT_SIZE]", QString::number(fontSize))
            .replace("[LINE_WIDTH]", QString::number(nWidth))
            .replace("[LABEL]", QString::number(dist,'g',2));
    _edges2.append(res);
}

void GraphMLExporter::fillNode(int i1,int width, int height, const QString& borderColor,
                               int borderWidth, int fontSize, const QString& textColor,
                               const QString& fillColor) {
    Star *s1 = this->_starList->stars().at(i1).data();
    QString res = QString(_nodeTemplate);
    res
            .replace("[NODE_ID]", QString::number(i1))
            .replace("[X]", QString::number(s1->x()*100.0))
            .replace("[Y]", QString::number(s1->y()*100.0))
            .replace("[WIDTH]", QString::number(width))
            .replace("[HEIGHT]", QString::number(height))
            .replace("[BORDER_COLOR]", borderColor)
            .replace("[BORDER_WIDTH]", QString::number(borderWidth))
            .replace("[FONT_SIZE]", QString::number(fontSize))
            .replace("[TEXT_COLOR]", textColor)
            .replace("[FILL_COLOR]", fillColor)
            .replace("[LABEL]", s1->starName);
    this->_nodes.append(res);
}
