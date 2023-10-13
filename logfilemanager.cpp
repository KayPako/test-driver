#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include "logfilemanager.h"

using namespace std;

LogFileManager::LogFileManager()
{
    m_fileName = "";
}

void LogFileManager::SetFileName(string newFN)
{
    m_fileName = newFN;
    // если у файла расширение .csv, то его тип сделать m_fileType = FT_CSV
    size_t dot_pos = m_fileName.find_last_of(".");
    string extension = m_fileName.substr(dot_pos + 1);
    if (extension == "csv")
    {
        m_fileType = FT_CSV;
    }
}

void LogFileManager::LoadFromFile()
{
    fstream f;
    string buff;
    vector<unsigned char> packet;
    int CommaPos;  //позиция символа ; в строке
    bool FirstLine = true;
    if (m_fileType == FT_CSV)
    {
        f.open(m_fileName, ios::in);
        while (!f.eof())
        {
            getline(f, buff); // считали строку  файла
            if (FirstLine == true) //первую строку пропускаем, там заголовок
            {
                FirstLine = false;
                continue;
            }
            //пропускаем время
            CommaPos = buff.find(";"); //ищем точку с запятой
            if (CommaPos != string::npos) { //если нашли
                buff = buff.substr(CommaPos + 1); //обрезаем начало строки
            }
            //пропускаем символ направления
            CommaPos = buff.find(";"); //ищем точку с запятой
            if (CommaPos != string::npos) { //если нашли
                buff = buff.substr(CommaPos + 1); //обрезаем начало строки
            }
            //если есть еще одна ; то нам нужна часть символов только до нее
            CommaPos = buff.find(";"); //ищем точку с запятой
            if (CommaPos != string::npos) { //если нашли
                buff = buff.substr(0, CommaPos); //обрезаем конец строки
            }
   //         cout << buff << endl;
            // из строки buff заполняем массив packet
            packet.clear();
            while(buff.length()>1)
            {
                char digitcode1=buff[0];
                char digitcode2=buff[1];
                char digit1,digit2;
                if((digitcode1>='0')&&(digitcode1<='9'))
                    digit1=digitcode1-'0';
                else  //A,B,C,D,E,F
                    digit1=10+(digitcode1-'A');
                if((digitcode2>='0')&&(digitcode2<='9'))
                    digit2=digitcode2-'0';
                else//A,B,C,D,E,F
                    digit2=10+(digitcode2-'A');
                char number=digit1*16+digit2;
                packet.push_back(number);
                if(buff.size()>=3)
                    buff.erase(0,3);
                else
                    buff.clear();

            }
            if(packet.size()>0)
              m_log.push_back(packet);
        }
        vector<unsigned char> Packet;
        for (int i = 0; i < GetLogSize(); i++)
        {
            Packet = GetPacket(i);
            cout << i << "s line is: ";
            for (int j = 0; j < Packet.size(); j++)
            {
                cout << +Packet[j] << " ";
            }
            cout << endl;
        }
    }
}

int LogFileManager::GetLogSize()
{
    return m_log.size();
}

vector<unsigned char> LogFileManager::GetPacket(int PacketIndex)
{
    return m_log[PacketIndex];
}
