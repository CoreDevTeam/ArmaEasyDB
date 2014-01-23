#include <iostream>
#include <Windows.h>
#include <time.h>
#include <fstream>

#include "coreserver_main_header.h"

const std::string currentDateTime()
{
     time_t     now = time(0);
     struct tm  tstruct;
     char       buf[80];
     tstruct = *localtime(&now);
     /*%Y-%m-%d.*/
     strftime(buf, sizeof(buf), "%X", &tstruct);

     return buf;
}

void CoreServer::set_flag (flag newFlag)
{

     switch (newFlag) {
     case DEBUG:
          std::cout << "Debug mode is enable" << std::endl;
          CoreServer::debug = true;
          break;
     }
}

void CoreServer::write_log (log PRIORTY,std::string logtxt)
{

     std::fstream log("ArmaEasyDB.log",std::ios::out | std::ios::app);

     switch(PRIORTY) {
     case INFO :
          if(debug) {
               std::cout << "[" << currentDateTime() <<"]" << " [INFO]: " << logtxt << std::endl;
          }
          log << "[" << currentDateTime() <<"]" << " [INFO]: " << logtxt << std::endl;
          break;

     case WARNING :
          if(debug) {
               std::cout << "[" << currentDateTime() <<"]" << " [WARNING]: " << logtxt << std::endl;
          }
          log << "[" << currentDateTime() <<"]" << " [WARNING]: " << logtxt << std::endl;
          break;

     case _ERROR:
          if(debug) {
               std::cout << "[" << currentDateTime() <<"]" << " [ERROR]: " << logtxt << std::endl;
          }
          log << "[" << currentDateTime() <<"]" << " [ERROR]: " << logtxt << std::endl;
          break;

     case OUTPUT:
          if(debug) {
               std::cout << "[" << currentDateTime() <<"]" << " [OUTPUT]: " << logtxt << std::endl;
          }
          log << "[" << currentDateTime() <<"]" << " [OUTPUT]: " << logtxt << std::endl;
          break;
     }
}
