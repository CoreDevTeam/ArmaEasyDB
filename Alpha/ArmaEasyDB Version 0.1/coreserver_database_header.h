#ifndef CORESERVER_DATABASE_HEADER_H_INCLUDED
#define CORESERVER_DATABASE_HEADER_H_INCLUDED

#include <string>
#include "coreserver_main_header.h"

class CSDBString {
private :

public :
     CSDBString();
     CSDBString(std::string DataBaseTextLine);
     std::string convertCSDBStringToDataBaseTextLine(CSDBString CSstring);
     std::string DBTextLine;
};

class CSDB : public CSDBString, public CoreServer {
public:
     CSDB();
     void createDataBase(std::string DBName);
     void readFromDataBase(std::string DBName);
     void purgeDataBase(std::string DBName);
     void writeToDataBase(std::string DBName,CSDBString &DataBaseEntry);
     void writeToDataBaseFromString(std::string DBName, std::string DBEntry);
};


#endif // CORESERVER_DATABASE_HEADER_H_INCLUDED
