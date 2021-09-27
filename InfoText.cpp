#include <iostream>
#include <string>
#include<windows.h>
#include <sstream>
using namespace std;
string make_info_text() {
    std::stringstream buffer;
    DWORD info =GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD version = info & mask;
    DWORD version_major = version & 0x00ff;
    DWORD version_minor = version & 0xff00;
    version_minor = version >>8;
    DWORD platform = info>>16;
    DWORD build;
    if ((platform &0x8000) == 0) build =platform;

    DWORD CNL = MAX_COMPUTERNAME_LENGTH+1;
    char ComputerName[CNL];
    GetComputerNameA(ComputerName,&CNL);

    buffer<<"Window V"<<version_major<<"."<<version_minor<<"(build "<<build<<")\n"
    <<"Computer name: "<<ComputerName;

    return buffer.str();
}
