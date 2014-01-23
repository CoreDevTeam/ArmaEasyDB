#include "ArmaEasyDB_header.h"

std::string convertInt(int number)
{
    std::stringstream ss;//create a stringstream
    ss << number;//add number to the stream
    return ss.str();//return a string with the contents of the stream
}

ArmaEasyDB::ArmaEasyDB(std::string DBName, std::string currentVersion)
{
    ///init the current DB
    ///for later usage
    ArmaEasyDB::currentDatabase = DBName;
    ArmaEasyDB::ProjektVersion = currentVersion;
}

void ArmaEasyDB::setCurrentDatabase(std::string DBName)
{
    ArmaEasyDB::currentDatabase = DBName;
}

void ArmaEasyDB::createDatabase()
{
    CoreServer cserv;

    std::string temp_db = ArmaEasyDB::currentDatabase + ".ArmaDB";
    std::ofstream ArmaEasyDatabaseStream (temp_db.c_str());
    if (ArmaEasyDatabaseStream.is_open()) {
        cserv.write_log(CoreServer::log::INFO,"Database "+temp_db+" created with success!");
        ArmaEasyDatabaseStream.close();
        cserv.write_log(CoreServer::log::INFO,"Database "+temp_db+" closed with success!");
    } else {
        cserv.write_log(CoreServer::log::_ERROR,"Database "+temp_db+" cannot be opend #Error @void ArmaEasyDB::createDatabase()");
    }
}

void ArmaEasyDB::createDatabase(std::string DataBaseName)
{
    CoreServer cserv;

    std::string temp_db = DataBaseName + ".ArmaDB";
    std::ofstream ArmaEasyDatabaseStream (temp_db.c_str());
    if (ArmaEasyDatabaseStream.is_open()) {
        cserv.write_log(CoreServer::log::INFO,"Database "+temp_db+" created with success!");

        ArmaEasyDatabaseStream.close();
        cserv.write_log(CoreServer::log::INFO,"Database "+temp_db+" closed with success!");
    } else {
        cserv.write_log(CoreServer::log::_ERROR,"Database "+temp_db+" cannot be opend #Error @void ArmaEasyDB::createDatabase(std::string DataBaseName)");
    }
}

void ArmaEasyDB::deleteDatabase()
{
    CoreServer cserv;

    std::string temp_db = ArmaEasyDB::currentDatabase + ".ArmaDB";
    if( remove( temp_db.c_str() ) != 0 ) {
        cserv.write_log(CoreServer::log::_ERROR,"Database "+temp_db+" cannot be deleted #Error @void ArmaEasyDB::deleteDatabase()");
    } else {
        cserv.write_log(CoreServer::log::INFO,"Database "+temp_db+" was deleted with success!");
    }
}

void ArmaEasyDB::deleteDatabase(std::string DataBaseName)
{
    CoreServer cserv;

    std::string temp_db = DataBaseName + ".ArmaDB";
    if( remove( temp_db.c_str() ) != 0 ) {
        cserv.write_log(CoreServer::log::_ERROR,"Database "+temp_db+" cannot be deleted #Error @void ArmaEasyDB::deleteDatabase()");
    } else {
        cserv.write_log(CoreServer::log::INFO,"Database "+temp_db+" was deleted with success!");
    }
}

void ArmaEasyDB::clearDatabase()
{
    CoreServer cserv;

    std::string temp_db = ArmaEasyDB::currentDatabase + ".ArmaDB";
    std::ofstream ArmaEasyDatabaseStream (temp_db.c_str() , std::ios::trunc);
    if (ArmaEasyDatabaseStream.is_open()) {
        ArmaEasyDatabaseStream << "";
        cserv.write_log(CoreServer::log::INFO,"Database "+temp_db+" cleared with success!");
        ArmaEasyDatabaseStream.close();
        cserv.write_log(CoreServer::log::INFO,"Database "+temp_db+" closed with success!");
    } else {
        cserv.write_log(CoreServer::log::_ERROR,"Database "+temp_db+" cannot be opend #Error @void ArmaEasyDB::createDatabase()");
    }
}

void ArmaEasyDB::addEntry(std::string dataString)
{
    CoreServer cserv;
    std::string temp = "";
    std::string DBEntry;
    std::string temp_db = ArmaEasyDB::currentDatabase + ".ArmaDB";
    std::ofstream ArmaEasyDatabaseStream (temp_db.c_str() , std::ios::app);
    std::ifstream fileOP (temp_db.c_str());

    int lines_count =0;
    std::string line;
    while (std::getline(fileOP , line)) {
        ++lines_count;
    }

    for ( unsigned int i = 0; i < dataString.size(); i++ ) {
        if(dataString[i] != ';') {
            temp += dataString[(i)];
        } else {
            DBEntry += "[" + convertInt(lines_count) + "]" +temp+";";
            temp = "";
        }
    }

    if (ArmaEasyDatabaseStream.is_open()) {
        ArmaEasyDatabaseStream << DBEntry;
        ArmaEasyDatabaseStream << "\n";
        cserv.write_log(CoreServer::log::INFO,"Database "+temp_db+" opend and edit with success!");
        ArmaEasyDatabaseStream.close();
        cserv.write_log(CoreServer::log::INFO,"Database "+temp_db+" closed with success!");
    } else {
        cserv.write_log(CoreServer::log::_ERROR,"Database "+temp_db+" cannot be opend #Error @void ArmaEasyDB::addEntry(std::string dataString)");
    }
}

std::string ArmaEasyDB::getDLLVersion()
{
    return ArmaEasyDB::ProjektVersion;
}
