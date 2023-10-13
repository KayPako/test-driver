#ifndef LOGFILEMANAGER_H
#define LOGFILEMANAGER_H

#include <string>
#include <vector>

enum LogFileType { FT_CSV, FT_BINARY };

class LogFileManager
{
public:
    LogFileManager();
    ~LogFileManager() {};
    void SetFileName(std::string newFN);
    void LoadFromFile();
    int GetLogSize();
    std::vector<unsigned char> GetPacket(int PacketIndex);
private:
    std::string m_fileName;
    std::vector<std::vector<unsigned char>> m_log;
    LogFileType m_fileType;
};
#endif // LOGFILEMANAGER_H
