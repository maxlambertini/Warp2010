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

    QFile docFile(yedDoc.absoluteFilePath());
    QFile nodeFile(yedNode.absoluteFilePath());
    QFile edgeFile(yedEdge.absoluteFilePath());

    if (!docFile.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Unable to open file: " << docFile.fileName() << " besause of error " << docFile.errorString() << endl;
    if (!nodeFile.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Unable to open file: " << nodeFile.fileName() << " besause of error " << nodeFile.errorString() << endl;
    if (!edgeFile.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Unable to open file: " << edgeFile.fileName() << " besause of error " << edgeFile.errorString() << endl;

    QTextStream inDoc(&docFile);
    this->_docTemplate = inDoc.readAll();
    QTextStream inNode(&nodeFile);
    this->_nodeTemplate = inNode.readAll();
    QTextStream inEdge(&edgeFile);
    this->_edgeTemplate = inEdge.readAll();
}

QString& GraphMLExporter::createGraphicsMLDocs() {
    return this->_doc;
}

void GraphMLExporter::fillEdge(int i1, int i2, const QString& lineColor, int nWidth, int fontSize) {
    Star *s1 = this->_starList->stars().at(i1);
    Star *s2 = this->_starList->stars().at(i2);
    double dist = s1->distance(s2);
    QString res = _edgeTemplate
            .replace("[N1]", QString::number(i1))
            .replace("[N2]", QString::number(i2))
            .replace("[LINE_COLOR]", lineColor)
            .replace("[LINE_WIDTH]", QString::number(nWidth))
            .replace("[LABEL]", QString::number(dist,'g',2));
    _edges.append(res);
}

void GraphMLExporter::fillNode(int i1) {
    Star *s1 = this->_starList->stars().at(i1);
    QString res = _edgeTemplate
            .replace("[NODE_ID]", QString::number(i1))
            .replace("[WIDTH]", QString::number(160))
            .replace("[HEIGHT]", QString::number(160))
            .replace("[BORDER_COLOR]", "#000000")
            .replace("[BORDER_WIDTH]", QString::number(1))
            .replace("[FONT_SIZE]", "18")
            .replace("[TEXT_COLOR]", "#000000")
            .replace("[FILL_COLOR]", "#ffff00")
            .replace("[LABEL]", s1->starName);
    this->_nodes.append(res);
}
