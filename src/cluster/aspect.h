#ifndef ASPECT_H
#define ASPECT_H


#include <QtCore>
#include "clusteritem.h"

class ClusterItem;
class Aspect
{
    QString _name;
    int _minEnv;
    int _maxEnv;
    int _minTech;
    int _maxTech;
    int _minRes;
    int _maxRes;

    void checkAspectString();

public:
    inline QString& name() { return _name; } const
    inline void setName(const QString& name) {
        _name = name;
    }

    inline int minRes() { return _minRes; }
    inline int minTech() { return _minTech; }
    inline int minEnv() { return _minEnv; }

    inline int maxRes() { return _maxRes; }
    inline int maxTech() { return _maxTech; }
    inline int maxEnv() { return _maxEnv; }
    
    void processParametricAspect() ;

    bool canApplyToClusterItem(ClusterItem& cli);

    Aspect();
    ~Aspect() {
        //qDebug() << "Destroying aspect " << this->_name;
    }

    Aspect(QString name,
           int minEnv=-5, int maxEnv=5,
           int minTech=-5, int maxTech=5,
           int minRes = -5, int maxRes = 5) :
            _name(name),
            _minEnv(minEnv),
            _maxEnv(maxEnv),
            _minTech(minTech),
            _maxTech(maxTech),
            _minRes(minRes),
            _maxRes(maxRes)
    {}
    static Aspect FromString(const QString &definitionString);

    friend QDataStream & operator << (QDataStream &in, const Aspect &model);
    friend QDataStream & operator >> (QDataStream &out, Aspect &model);

};

#endif // ASPECT_H
