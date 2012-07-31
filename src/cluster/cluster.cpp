#include "cluster/cluster.h"
#include "onomastikon.h"
#include "ssg_structures.h"
#include "aspectlist.h"

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

void Cluster::create( int nCluster) {
    _isDirty = false;
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


    if (nSlipstream < 2) {
        for (int xx = nSlipstream; xx <2; xx++)
        {
            int idx = vector.at(xx);
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
        ci.addLink(n1);
        _clusterItems[n1].addLinkedBy(h);
        int res = SSGX::dF();
        if ( (res == 0 || res > 0) && h+2 < nCount) {
            ci.addLink(n2);
            _clusterItems[n2].addLinkedBy(h);
        }
        if (res > 0 && h+3 < nCount) {
            ci.addLink(n3);
            _clusterItems[n3].addLinkedBy(h);
        }
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
        stream << "graph Cluster {\n";
        stream << "\tdpi=200;\n\trankdir=LR;\n\tnode [shape=circle];\n";
        foreach (cli, _clusterItems) {
            tmpTech = cli.technology();
            if (tmpTech < 2) {
                stream << "\tcli_" << idx2 << " " << "[label=\""  << cli.name() << "\\n"
                        << "Env: " << cli.environment() << "\\n"
                        << "Tech: " << cli.technology() << "\\n"
                        << "Res: " << cli.resources() << "\"];\n";
            } else {
                stream << "\tcli_" << idx2 << " " << "[shape=doublecircle,label=\""  << cli.name() << "\\n"
                        << "Env: " << cli.environment() << "\\n"
                        << "Tech: " << cli.technology() << "\\n"
                        << "Res: " << cli.resources() << "\"];\n";

            }
            foreach (idx, cli.links())
            {
                cli2 = _clusterItems[idx];
                stream << "\t" << "cli_" << idx2 <<  " -- " << "cli_" << idx << ";\n";
            }
            idx2++;
        }

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
