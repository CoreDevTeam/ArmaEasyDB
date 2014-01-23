#include "coreserver_database_header.h"
#include <fstream>
#include <iostream>
CSDB::CSDB() {}

CSDBString::CSDBString() {}

CSDBString::CSDBString(std::string DataBaseTextLine)
{
     CSDBString::DBTextLine = DataBaseTextLine;
}

void CSDB::createDataBase(std::string DBName)
{
     std::string CSDBFileType = ".CSDB";
     std::string CSDBFileString = DBName+CSDBFileType;

     std::fstream CSDBFile(CSDBFileString.c_str(),std::ios::out);
     CSDBFile.close();
}
void CSDB::readFromDataBase(std::string DBName)
{

}
void CSDB::purgeDataBase(std::string DBName)
{
     std::string CSDBFileType = ".CSDB";
     std::string CSDBFileString = DBName+CSDBFileType;
     std::fstream CSDBFile(CSDBFileString.c_str(),std::ios::out | std::ios::trunc);
     CSDBFile << "";
     CSDBFile.close();
}

std::string CSDBString::convertCSDBStringToDataBaseTextLine(CSDBString CSstring)
{
     std::string DataBaseTextLine;
     CSstring.DBTextLine = DataBaseTextLine;
     return DataBaseTextLine;
}

void CSDB::writeToDataBase(std::string DBName,CSDBString &DataBaseEntry)
{
     std::string CSDBFileType = ".CSDB";
     std::string CSDBFileString = DBName+CSDBFileType;

     std::fstream CSDBFile(CSDBFileString.c_str(),std::ios::out | std::ios::app);

     std::string DataBaseTextLine;
     DataBaseEntry.DBTextLine = DataBaseTextLine;
     CoreServer cs;
     if(cs.debug = true) {
          cs.write_log(CoreServer::log::OUTPUT,DataBaseTextLine);
     }
     CSDBFile << DataBaseEntry.DBTextLine;
}

void CSDB::writeToDataBaseFromString(std::string DBName, std::string DBEntry)
{
     std::string CSDBFileType = ".CSDB";
     std::string CSDBFileString = DBName+CSDBFileType;

     std::fstream CSDBFile(CSDBFileString.c_str(),std::ios::out | std::ios::app);

     CoreServer cs;
     if(cs.debug = true) {
          cs.write_log(CoreServer::log::OUTPUT,DBEntry);
     }
     CSDBFile << DBEntry;
}
