/*
############################################################################
#
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA#
############################################################################
*/

#ifndef CLUSTERITEM_H
#define CLUSTERITEM_H
#include <QtCore>
#include "ssg_structures.h"
#include "cluster/aspect.h"

class Aspect;

class ClusterItem
{
    int _environment;
    int _technology;
    int _resources;
    QString _name;
    QString _description;
    QList<int> _links;
    QList<int> _linkedBy;
    QList<Aspect> _aspects;
public:
    inline void setEnvironment(int i) { _environment = i; }
    inline int environment()  { return _environment; }
    inline void setTechnology(int i) { _technology = i; }
    inline int technology() { return _technology; }
    inline void setResources( int i) { _resources = i; }
    inline int resources() { return _resources; }

    inline void setName (QString& i ) { _name = i; }
    inline void setName (const QString& i ) { _name = i; }
    inline QString& name()  { return _name; }
    inline const QString& constName()  { return _name; }

    inline void addLink(int nLink) {_links.append(nLink);}
    inline void addLinkedBy(int nLink) {_linkedBy.append(nLink);}
    inline void removeLink(int nLink) {_links.removeAll(nLink);}
    inline void removeLinkedBy(int nLink) {_linkedBy.removeOne(nLink);}

    inline int totalValue() { return _environment+ _technology+_resources; }

    inline void clearLinks() { _links.clear(); }
    inline const QList<int>& links() { return _links; }
    inline const QList<int>& linkedBy() { return _linkedBy; }
    inline QList<Aspect>& aspects() { return _aspects; }

    ClusterItem();
    ClusterItem(QString& name);
    ~ClusterItem() {
        //qDebug() << "Destroying cluster item " << this->_name;
    }

    inline const QString& description() { return _description; }
    inline void setDescription (QString& d) { _description = d; }
    inline void setDescription (const QString& d ) { _description = d; }

    void detach() { _links.detach(); }

    friend QDataStream & operator << (QDataStream &in, const ClusterItem &model);
    friend QDataStream & operator >> (QDataStream &out, ClusterItem &model);

};

#endif // CLUSTERITEM_H
