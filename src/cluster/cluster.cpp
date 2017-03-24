#include "cluster/cluster.h"
#include "onomastikon.h"
#include "ssg_structures.h"
#include "aspectlist.h"
#include <QtDebug>

QDataStream & operator >> (QDataStream &in, Cluster& frm) {

    in >> frm._clusterItems >> frm._clusterMap >> frm._name;
    return in;
}


QDataStream& operator << (QDataStream &out, const Cluster& frm)
{
    out << frm._clusterItems << frm._clusterMap << frm._name;
    return out;
}


Cluster::Cluster() : _onomastikon(Onomastikon::instancePtr())
{
    this->create();
}

void Cluster::create( int nCluster, bool closeCluster) {
    _isDirty = false;
    _closeCluster = closeCluster;
    _clusterItems.clear();
    _clusterMap.clear();
    int numCluster = nCluster != 0 ? nCluster : SSGX::dn(5)+5;
    _name = _onomastikon->pseudoNomen();

    QStringList lstNames;
    QString tmpName;
    for (int h = 0; h < numCluster; h++)
    {
        tmpName = clusterItemName();
        lstNames << tmpName;
    }

    _name = _onomastikon->pseudoNomen();

    for (int h = 0; h < numCluster; h++)
    {
        QString item = lstNames[h];
        ClusterItem ci(item);
        _clusterItems.append(ci);
        _clusterMap[_name] = ci;
    }

    int nCount = _clusterItems.count();

    bool bSlipstreamGuaranteed = false;
    int nSlipstream = 0;
    QVector<int> vector;
    for (int h = 0; h < nCount -1; h++)
    {
        ClusterItem& ci = _clusterItems[h];
        if (ci.technology() >= 2) {
            nSlipstream++;
            bSlipstreamGuaranteed = (nSlipstream >= 2);
        } else {
            vector.append(h);
        }
    }
    int idMax = vector.count();
    for (int w = idMax; w > 0 ; w--) {
        int i2 = SSGX::dx(w);
        int t1 = vector[i2];
        vector[i2] = vector[w-1];
        vector[w-1] = t1;
    }

    qDebug() << "Vector is: " << vector;


    if (nSlipstream < 2) {
        for (int xx = nSlipstream; xx <2; xx++)
        {
            int minVal = 13;
            int curItem = 999;
            for (int w = 0; w < vector.count(); w++) {
                ClusterItem& ci = _clusterItems[vector.at(w)];
                if (ci.totalValue() < minVal) {
                    curItem = w;
                    minVal = ci.totalValue();
                }
            }
            int idx = vector.at(curItem);
            ClusterItem& ci = _clusterItems[idx];
            ci.setTechnology(2);
        }
    }

    int nWarp = SSGX::dn(nCount);

    for (int h = 0; h < nCount-1; h++)
    {
        int n1 = h+1;
        int n2 = h+2;
        int n3 = h+3;
        ClusterItem& ci = _clusterItems[h];
        int res = SSGX::dF();
        ci.addLink(n1);
        _clusterItems[n1].addLinkedBy(h);
        if ( (res == 0 || res > 0) && h+2 < nCount && _clusterItems[n2].linkedBy().count() == 0) {
            ci.addLink(n2);
            _clusterItems[n2].addLinkedBy(h);
            qDebug() <<  "Added linked by " << h << " to " << n2;
        }
        qDebug() << "Draw is " << res << " for cluster item " << h;
        if (res > 0 && h+3 < nCount && _clusterItems[n3].linkedBy().count()==0) {
            ci.addLink(n3);
            _clusterItems[n3].addLinkedBy(h);
            qDebug() <<  "Added linked by " << h << " to " << n3;
        }
        qDebug() <<  "Added linked by " << h << " to " << n1;

    }
    if (_closeCluster) {
        int idxFirst = 0;
        int idxLast = _clusterItems.count()-1;
        _clusterItems.first().addLink(idxLast);
        _clusterItems.last().addLinkedBy(idxFirst);
    }

    _aspects.clearAspectDraw();
    for (int z = 0; z < nCount; z++ ){
        if (_aspects.aspects().count() > 0)
        {          
            ClusterItem& ci = _clusterItems[z];
            for (int nx = 0; nx < 3; nx++)
            {
                QString name1, name2 ;
                Aspect aspect = _aspects.drawAspect();
                while (!aspect.canApplyToClusterItem(ci))
                    aspect = _aspects.drawAspect();
                if (aspect.name().contains("[[SYSTEM]]")) {
                    int z1 = SSGX::dx(nCount);
                    while (z1 == z)
                        z1 = SSGX::dx(nCount);
                    ClusterItem ci2 = _clusterItems [z1];
                    name1 = ci2.name();
                    QString newAspect = aspect.name().replace("[[SYSTEM]]",name1);
                    aspect.setName(newAspect);
                }
                if (aspect.name().contains("[[SYSTEM2]]")) {
                    do {
                        int z1 = SSGX::dx(nCount);
                        while (z1 == z)
                            z1 = SSGX::dx(nCount);
                        ClusterItem ci2 = _clusterItems [z1];
                        name2 = ci2.name();
                    } while (name1 == name2);
                    QString newAspect = aspect.name().replace("[[SYSTEM2]]",name2);
                    aspect.setName(newAspect);
                }
                if (aspect.name().contains("[[HOME]]")) {
                    QString newAspect = aspect.name().replace("[[HOME]]",ci.name());
                    aspect.setName(newAspect);
                }
                aspect.processParametricAspect();
                ci.aspects() << aspect;
            }
        }

    }

}

QString Cluster::clusterItemName() {
    int d = SSGX::d10();
    QString item;
    switch (d)
    {
    case 1:
        item = _onomastikon->sigla();
        break;
    case 2:
        item = _onomastikon->sigla();
        break;
    case 3:
        item = _onomastikon->pseudoNomen();
        break;
    case 4:
        item = _onomastikon->pseudoNomen();
        break;
    case 5:
        item = _onomastikon->fakeNomen();
        break;
    case 6:
        item = _onomastikon->fakeNomen();
        break;
    case 7:
        item = _onomastikon->fakeNomen();
        break;
    default:
        item = _onomastikon->nomen();
        break;
    };

    return item;
}

void Cluster::exportClusterToGraphViz(QString defaultName)
{
    QString fileName;

    if (defaultName != "")
        fileName = defaultName;
    else
        fileName = this->_name+".dot";

    QFile file(fileName);
    QTextStream stream(&file);
    ClusterItem cli, cli2;
    int idx, idx2;
    idx2 = 0;
    int tmpTech;
    if (file.open(QIODevice::WriteOnly | QIODevice::ReadWrite)) {
        stream << "graph Cluster {\n overlap=false;ranksep=2.5;splines=true;";
        stream << "\tdpi=200;\n\tnode [shape=circle];\n";
        foreach (cli, _clusterItems) {
            tmpTech = cli.technology();

            QString s_color= tmpTech >= 2 ? "yellow" : "white";

            QString a1= cli.aspects()[0].name().replace("\"","'").replace("\n"," ");;
            QString a2= cli.aspects()[1].name().replace("\"","'").replace("\n"," ");;
            QString a3= cli.aspects()[2].name().replace("\"","'").replace("\n"," ");;
            stream << "\tcli_" << idx2 << " " << "["
                    << "shape=\"Mrecord\"\nlabel=<<table border=\"0\" cellpadding=\"3\" width=\"250\" bgcolor='" << s_color << "'><tr>"
                    << "<td width='250' bgcolor='black'><b><font color='white'>" << cli.name() << "</font></b></td></tr>"
                    << "<tr><td width='250' bgcolor='#DDDDDD'>Env: " << cli.environment() << ", "
                    << "Tech: " << cli.technology() << ", "
                    << "Res: " << cli.resources()  << "</td></tr>"
                    << "<tr><td width='250' >" << a1 << "</td></tr>"
                    << "<tr><td width='250' >" << a2 << "</td></tr>"
                    << "<tr><td width='250' >" << a3 << "</td></tr>"
                    << "</table>> "
                    << "];\n";
            foreach (idx, cli.links())
            {
                cli2 = _clusterItems[idx];
                stream << "\t" << "cli_" << idx2 <<  " -- " << "cli_" << idx << ";\n";
            }
            idx2++;
        }

        int mod = _clusterItems.count() / 2;
        stream << "{rank=same; ";
        for (int idx = 1; idx < mod; idx++) {
            stream << " cli_" << idx;
        }
        stream << "}\n";
        stream << "{rank=same; ";
        for (int idx = mod; idx < _clusterItems.count()-1;idx++) {
            stream << " cli_" << idx;
        }
        stream << "}\n";

        stream << "}\n";
        file.close();
    }
}

void Cluster::addLink(int idx, int idxToLink) {
    ClusterItem c1 = this->mutableClusterItems()[idx];
    ClusterItem c2 = this->mutableClusterItems()[idxToLink];
    if (!c1.links().contains(idxToLink))
        c1.addLink (idxToLink);
    if (!c2.links().contains(idx))
        c2.addLinkedBy (idx);
    _clusterItems[idx] = c1;
    _clusterItems[idxToLink] = c2;
}

void Cluster::removeLink(int idx, int idxToLink) {
    ClusterItem c1 = this->mutableClusterItems()[idx];
    ClusterItem c2 = this->mutableClusterItems()[idxToLink];
    if (!c1.links().contains(idxToLink))
        c1.removeLink( idxToLink);
    if (!c2.links().contains(idx))
        c2.removeLinkedBy( idx);
    _clusterItems[idx] = c1;
    _clusterItems[idxToLink] = c2;
}
