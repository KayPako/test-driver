#ifndef DRIVERTESTER_H
#define DRIVERTESTER_H
#include <string>
#include <QLibrary>
#include "logfilemanager.h"

class DriverTester
{
public:
    DriverTester();
    ~DriverTester();
    void SetLogFile(std::string NewLogFN);
    void SetDriverFile(std::string NewDriverFN);
    int OpenDriver();
    int OpenLogFile();
    int SimulateExchange();

  //  std::vector<std::vector<unsigned char>> GetFileLog();
  //  std::vector<std::vector<unsigned char>> GetDriverLog();

    QLibrary m_linedevice_lib;
    std::vector<std::vector<unsigned char>> GetFileLog(){return log;};
    std::vector<std::vector<unsigned char>> GetDriverLog(){return driverlog;};
private:
    std::string m_logFilename;
    std::string m_driverFilename;
    LogFileManager m_fileManager;
    QLibrary m_lib;
    std::vector<std::vector<unsigned char>> log,driverlog;
};

#endif // DRIVERTESTER_H
