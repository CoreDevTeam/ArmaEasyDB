#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::string convertInt(int number)
{
   std::stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

int main()
{
    std::string temp = "";
    std::string DBEntry;
    std::string dataString = "Mark Sepp;1234PW;100;false;";
///////////////////////////////////////
    std::string temp_db = "test.ArmaDB";
    std::ofstream ArmaEasyDatabaseStream (temp_db.c_str() , std::ios::app);
    std::ifstream fileOP (temp_db.c_str());

    int lines_count =0;
    std::string line;
    while (std::getline(fileOP , line)) {
        ++lines_count;
    }
///////////////////////////////////////
    for ( unsigned int i = 0; i < dataString.size(); i++ ) {
        if(dataString[i] != ';') {
            temp += dataString[(i)];
        } else {
            DBEntry +=  "[" + convertInt(lines_count) + "]" + temp + ";";
            temp = "";
        }
    }
///////////////////////////////////////
    if (ArmaEasyDatabaseStream.is_open()) {
        ArmaEasyDatabaseStream << DBEntry;
        ArmaEasyDatabaseStream << "\n";

        ArmaEasyDatabaseStream.close();

    } else {
        std::cerr << "#Error";
    }
}
