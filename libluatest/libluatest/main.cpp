#include <iostream>
#include "libnoiselua.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Starting LuaLib!" << endl;
    Libnoiselua lib;
#ifdef WIN32
    lib.lua().script_file("C:/codice/qt/Warp2010/libluatest/libluatest/test.lua");
#else
    lib.lua().script_file("/home/maxl/dev/Warp2010/libluatest/libluatest/test.lua");
#endif
    cout << "End...\n\n";
    return 0;
}
