#ifndef ARMAEASYDB_HEADER_H_INCLUDED
#define ARMAEASYDB_HEADER_H_INCLUDED

#include <sstream>

//  Functions:
/// createDB (string Name)
/// deleteDB (string Name)
/// clearDB (string Name)
// ----
/// addEntry (array [ID,Name,PW,banned])
/// removeEntry (int ID)
/// editEntry (array [ID,Name,PW,banned])
/// getEntryByID (int ID)
/// checkAccountLogin (string Name,string Password)

#include <string>
#include <fstream>
#include "coreserver_main_header.h"
///
class ArmaEasyDB {
private:
// Database Name for later
    std::string currentDatabase;
    std::string ProjektVersion;
//
public:

    ArmaEasyDB(std::string DBName,std::string currentVersion);
    void setCurrentDatabase(std::string DBName);

    void createDatabase();
    void createDatabase(std::string DataBaseName);

    void deleteDatabase();
    void deleteDatabase(std::string DataBaseName);

    void clearDatabase();
    void clearDatabase(std::string DataBaseName);

    void addEntry (std::string dataString);

    std::string getDLLVersion();
};

#endif // ARMAEASYDB_HEADER_H_INCLUDED
