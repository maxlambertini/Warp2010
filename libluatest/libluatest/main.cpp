#include <iostream>
#include "libnoiselua.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Starting LuaLib!" << endl;
    Libnoiselua lib;
    lib.lua().script_file("/home/maxl/dev/Warp2010/libluatest/libluatest/test.lua");
    cout << "End...\n\n";
    return 0;
}
