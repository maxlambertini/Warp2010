#ifndef ASPECTLIST_H
#define ASPECTLIST_H

#include <QtCore>
#include "cluster/aspect.h"
#include "ssg_structures.h"

class AspectList
{
    QVector<Aspect> _aspects;
    QList<int> _drawnAspects;
    int _currentDrawIndex;
public:
    QVector<Aspect>& aspects() { return _aspects; }
    AspectList();
    static AspectList fromFile(const QString& filename);
    static AspectList fromAppDir();
    void clearAspectDraw() {
        int idMax = _aspects.count();
        _drawnAspects.clear();
        if (idMax > 0) {
            for (int x = 0; x < idMax; x++)
                _drawnAspects << x;
            for (int w = idMax; w > 1 ; w--) {
                int i2 = SSGX::dx(w);
                int t1 = _drawnAspects[i2];
                _drawnAspects[i2] = _drawnAspects[w-1];
                _drawnAspects[w-1] = t1;
            }

        }
        _currentDrawIndex = 0;
    }
    Aspect& drawAspect();
};

#endif // ASPECTLIST_H
