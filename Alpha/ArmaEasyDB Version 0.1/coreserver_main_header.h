#ifndef CORESERVER_MAIN_HEADER_H_INCLUDED
#define CORESERVER_MAIN_HEADER_H_INCLUDED

class CoreServer {
private:
     enum flag {
          DEBUG
     };
     typedef std::string workingdir;
public:
     bool debug;
     enum log {
          INFO,
          WARNING,
          _ERROR,
          OUTPUT
     };
     void write_log(log PRIORTY,std::string logtxt);
     void set_flag(flag newFlag);
     void setGlobalWorkingDirectory(std::string workdir);
};

#endif // CORESERVER_MAIN_HEADER_H_INCLUDED
