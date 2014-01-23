///#include "main.h"

//#define WIN32_LEAN_AND_MEAN             // Selten verwendete Teile der Windows-Header nicht einbinden.
// Windows-Headerdateien:
#include <Windows.h>

// TODO: Hier auf zusätzliche Header, die das Programm erfordert, verweisen.
#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include <sstream>
#include <vector>

#include "ArmaEasyDB_header.h"

extern "C"
{
    __declspec (dllexport) void __stdcall RVExtension(char *output, int outputSize, const char *function);
}

void getParameterList(std::string paramList, std::vector<std::string> &rippedParameter)
{
    std::string temp = "";
    //Testing if string has space at the end, so the read function gets also the last parameter
    if(paramList[paramList.size()] != ' ') {
        paramList += " ";
    }

    for ( unsigned int i = 0; i < paramList.size(); i++ ) {
        if(paramList[i] != ' ') {
            temp += paramList[(i)];
        } else {
            rippedParameter.push_back(temp);
            temp = "";
        }
    }
};

void __stdcall RVExtension(char *output, int outputSize, const char *function)
{
    outputSize -= 1;

    std::vector<std::string> parameter;

    getParameterList(function,parameter);

    ArmaEasyDB instDB("Dummy","0.4");

    if (!strcmp(parameter[0].c_str(),"getDLLVersion")) {
        std::string _temp = instDB.getDLLVersion();
        strncpy(output,_temp.c_str(),outputSize);
    }
    if (!strcmp(parameter[0].c_str(),"createDatabase")) {
        instDB.createDatabase(parameter[1]);
        //strncpy(output,x.c_str(),outputSize);
    }
    if (!strcmp(parameter[0].c_str(),"deleteDatabase")) {
        instDB.deleteDatabase(parameter[1]);
        //strncpy(output,x.c_str(),outputSize);
    }
    if (!strcmp(parameter[0].c_str(),"clearDatabase")) {
        instDB.deleteDatabase(parameter[1]);
        //strncpy(output,x.c_str(),outputSize);
    }
    if (!strcmp(parameter[0].c_str(),"addEntry")) {
        instDB.addEntry(parameter[1]);
        //strncpy(output,x.c_str(),outputSize);
    }
}
