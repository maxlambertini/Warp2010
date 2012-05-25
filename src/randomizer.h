#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <stdlib.h>

class Randomizer;

class Randomizer
{
public:
    static Randomizer *current();
    inline int die(int n) { return rand() % n+1; }
    inline int die(int n, int howMany, int delta)
    {
        int res = delta;
        for (int h = 0; h < howMany; h++)
            res += die(n);
        return res;
    }
    inline int d6() { return die(6); }
    inline int d10() { return die(10); }


private:
    Randomizer() {}
    static Randomizer* _instance;

};

#endif // RANDOMIZER_H
