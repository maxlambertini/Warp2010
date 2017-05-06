#ifndef GASGIANT_H
#define GASGIANT_H

#include <helpers/planetmaps/abstractmap.h>

namespace maps {
class GasGiant : public AbstractMap
{
    Q_OBJECT
public:
    GasGiant();
    void generate();
};
}

#endif // GASGIANT_H
