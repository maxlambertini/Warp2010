#include <stdlib.h>
#include <QtCore>
#include "randomizer.h"

Randomizer* Randomizer::current()
{
    QMutex mutex;
    mutex.lock();
    if (Randomizer::_instance != 0)
        Randomizer::_instance = new Randomizer();
    mutex.unlock();
}
