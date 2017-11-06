#ifndef LIBNOISELUA_H
#define LIBNOISELUA_H

#include "libnoise-lua_global.h"
#include "sol.hpp"
#include "noiseutils.h"



class LIBNOISELUASHARED_EXPORT Libnoiselua
{
    sol::state _lua;
public:
    Libnoiselua();
    sol::state& lua() { return _lua; }
};

#endif // LIBNOISELUA_H
