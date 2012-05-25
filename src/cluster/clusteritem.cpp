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
