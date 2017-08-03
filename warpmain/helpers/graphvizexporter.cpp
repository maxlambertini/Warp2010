#include "graphvizexporter.h"
#include <QSharedPointer>
#include <QFile>

GraphVizExporter::GraphVizExporter()
{

}

void GraphVizExporter::createGraphVizDoc(QString& filename) {
    QSharedPointer<Star> star;
    QSharedPointer<Star> p1,p2;

    this->_sceneMediator->prepareParsecStarList();
    ParsecStar ps;

    QFile file(filename);
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream output(&file);

        output << "graph { \noverlap=false;\nsplines=true;\nranksep=1.5;\n";
        output << "graph [charset=latin1, overlap_scaling=3, pack=90, label=\"StarMap\"]\n";
        output << "node [shape=none, label=\"\\N\", width=\"0.001\", height=\"0.001\", margin=\"0.001\"];\n";

        int h = 0;

        int iMaxNeighbor = 0;

        foreach (star, _starList->stars()) {
            if (star->neighbors().count() > iMaxNeighbor)
                iMaxNeighbor = star->neighbors().count();
        }
        iMaxNeighbor += 2;
        int sz;
        foreach (ps, this->_sceneMediator->parsecStarList() ) {
        //foreach (p1, _starList->stars()) {
            p1 = ps.star();
            auto pt = this->_sceneMediator->pointFromParsecStar(ps);
            QString name = p1.data()->starName;
            QString n, nRes("");
            QStringList lstRes;
            QStringList nameList = name.split(QChar(' '),QString::SkipEmptyParts);
            foreach (n, nameList) {
                if (n.length() < 10)
                    lstRes << n;
                else {
                    auto x = n.length() / 2;
                    lstRes << n.mid(0,x);
                    lstRes << n.mid(x);
                }
            }
            name = lstRes.join("\\n");

            if (p1->neighbors().count() > 0 && p1->path().count() > 0) {
                if (h != 0)
                    sz = 8+ (int)( pow( (double)p1->neighbors().count(),1.3));
                else
                    sz = 8+ (int)( pow( (double)iMaxNeighbor,1.3));
                output << h <<  "[label=\"" << name //<< p1->starName().replace(" ","\n")
                       << "\" group=\"" <<  1+(p1->path().count() % 3)
                       << "\" fontsize=\"" << sz
                       << "\" pos=\"" << pt.x() << "," << pt.y() << "\"];\n";
            }
            h++;
        }
        foreach (star, _starList->stars())
            star->setVisited(false);

        int nCount = 0;
        QStringList links;

        foreach (star, _starList->stars())
        {
            int iNeighbor,i1,i2, ia,ib;
            if (star->path().count() > 1 ) {
                if (!_exportDirectPathOnly) {
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
                            output << i1 << " -- " << i2 << ";\n";
                        }
                    }
                } else {
                    for (int w = 1; w < star->path().count(); w++)
                    {
                        ia = star->path().at(w-1);
                        ib = star->path().at(w);
                        if (ia > ib) {
                            i1 = ib;
                            i2 = ia;
                        } else {
                            i1 = ia;
                            i2 = ib;
                        }
                        QString key = QString("%1_%2").arg(i1,i2);
                        if (!links.contains(key)) {
                            links.append(key);
                            output << i1 << " -- " << i2 << ";\n";
                        }
                    }
                }
            }
            nCount++;
        }
        output << "\n}\n";
    }
    //file.close();

}
