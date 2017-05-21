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

#include "clusteritem.h"
#include "ssg_structures.h"

ClusterItem::ClusterItem() :
        _environment(SSGX::dF(4)),
        _technology(SSGX::dF(4)),
        _resources(SSGX::dF(4) )
{
    _name.clear();

}

ClusterItem::ClusterItem(QString &name)  :
        _environment(SSGX::dF(4)),
        _technology(SSGX::dF(4)),
        _resources(SSGX::dF(4) ),
        _name(name)
{
}

QDataStream & operator >> (QDataStream &in, ClusterItem& frm) {
    QString name, description;
    qint32 resources, technology, environment;

    in >> resources >> technology >> environment >> name >> frm._links >> frm._aspects >> description;
    frm.setName(name);
    frm.setEnvironment(environment);
    frm.setTechnology(technology);
    frm.setResources(resources);
    frm.setDescription(description);
    return in;
}


QDataStream& operator << (QDataStream &out, const ClusterItem& frm)
{

    out << frm._resources << frm._technology << frm._environment << frm._name
            << frm._links << frm._aspects << frm._description;
    return out;
}
