#include "drivertester.h"
#include <vector>
#include <iostream>
#include <QDebug>
#include "testlinedevice.h"
#include "register.h"
#include "module_base.h"
using namespace std;

DriverTester::DriverTester()
    {

    }

DriverTester::~DriverTester()
    {

    }

void DriverTester::SetLogFile(std::string NewLogFN)
    {
        m_logFilename = NewLogFN;
    }

void DriverTester::SetDriverFile(std::string NewDriverFN)
    {
        m_driverFilename = NewDriverFN;
    }

int  DriverTester::OpenDriver()
    {
        bool result;
       /* m_linedevice_lib.setFileName("linedevices.dll");
        result = m_linedevice_lib.load();
        if (!result)
        {
            cout<<"linedevices.dll is not loaded"<<endl;
            return-1; // Файл не открылся
        }
        else
        {
            cout<<"linedevices.dll is loaded"<<endl;*/
            cout<<"driverfile = "<<m_driverFilename<<endl;
            m_lib.setFileName(QString::fromStdString(m_driverFilename));
            result=m_lib.load();
       // }
        if(result)
        {
            cout<<"Driver is loaded"<<endl;
            return 0; // Файл открылся
        }
        else
        {
            cout<<"Driver is not loaded"<<endl;
            return -1; // Файл не открылся
        }
    }

int DriverTester::OpenLogFile()
    {
    m_fileManager.SetFileName(m_logFilename);
    m_fileManager.LoadFromFile();
    vector<unsigned char> Packet;
    log.clear();
    for (int i = 0; i < m_fileManager.GetLogSize(); i++)
    {
        Packet = m_fileManager.GetPacket(i);
        log.push_back(Packet);
    }
    return 0;
}
/*
vector<vector<unsigned char>> DriverTester::GetFileLog()
{
    return log;
}

vector<vector<unsigned char>> DriverTester::GetDriverLog()
{
    return driverlog;
}
*/

int DriverTester::SimulateExchange()
    {
    const vector<unsigned char> password {1, 2, 3, 4, 5, 6, 7, 8};
        typedef Registrator& (*getRegistrator_fun)();
        /*typedef void* (*create_TestLineDevice_fun)();
        typedef void* (*setExchlog_fun)(void* testlinedevice, std::vector<std::vector<unsigned char>> new_exch_log);
        typedef void* (*create_TestInterface_fun)(vector<unsigned char>);
        typedef void* (*setLineDevice_fun)(void* TI, void* LD);
        typedef std::vector<std::vector<unsigned char>> (*testConnect_fun)(void* TI, std::vector<unsigned char> password);*/
        vector<unsigned char> SendPacket;
        vector<unsigned char> ReceivePacket;
        /*void* TLD;
        void* TI;
        vector<vector<unsigned char>> log, driverlog;*/
 //было временно для теста
/*        vector<unsigned char> st1 {0x2F, 0x3F, 0x30, 0x36, 0x38, 0x21, 0x0D, 0x0A};
        log.push_back(st1);
        vector<unsigned char> st2 {0x2F, 0x47, 0x45, 0x43, 0x35, 0x31, 0x32, 0x30, 0x35, 0x31, 0x30, 0x30, 0x37, 0x30, 0x31, 0x30, 0x30, 0x40, 0x30, 0x30, 0x30, 0x0D, 0x0A};
        log.push_back(st2);
        vector<unsigned char> st3 {0x06,  0x30, 0x35, 0x31, 0x0D, 0x0A};
        log.push_back(st3);
        vector<unsigned char> st4 {0x01, 0x50, 0x30, 0x02, 0x28, 0x38, 0x37, 0x32, 0x38, 0x43, 0x43, 0x38, 0x43, 0x32, 0x43, 0x45, 0x32, 0x30, 0x42, 0x43, 0x29, 0x03, 0x11};
        log.push_back(st4);
        vector<unsigned char> st5 {0x01, 0x50, 0x32, 0x02, 0x28, 0x33, 0x44, 0x41, 0x44, 0x33, 0x43, 0x30, 0x38, 0x43, 0x46, 0x39, 0x37, 0x42, 0x45, 0x37, 0x32, 0x29, 0x03, 0x9F};
        log.push_back(st5);
        vector<unsigned char> st6 {0x06};
        log.push_back(st6);*/


        // Подключаем библеотеку LineDevices
        std::shared_ptr<TestLineDevice>TLDevice(new TestLineDevice);
                TLDevice->SetExchLog(log);
                cout<<"TLDevice log loaded" << endl;
        /*if(m_linedevice_lib.isLoaded())
            {
             create_TestLineDevice_fun create_TestLineDevice = (create_TestLineDevice_fun) m_linedevice_lib.resolve("create_TestLineDevice");

            if(!create_TestLineDevice)
            {
                cout << "create_TestLineDevice is not loaded" << endl;
                return -1;
            }

            // Вызываем функцию из библеотеки
            TLD = create_TestLineDevice();

            // Получаем адрес функции из библеотеки
            setExchlog_fun setExchlog = (setExchlog_fun)m_linedevice_lib.resolve("setExchLog");
            if(!setExchlog)
            {
                cout << "setExchLog is not loaded" << endl;
                return -1;
            }

            // Вызываем функцию
            setExchlog (TLD, log);
            cout << "LineDevice is OK" << endl;
            }*/
        // Подключаем библиотеку драйвера
        if(m_lib.isLoaded())
        {
            getRegistrator_fun get_Reg_obj =(getRegistrator_fun) m_lib.resolve("GetRegistrator");
                        if(!get_Reg_obj)
                        {
                            cout << "Registrator loaded " << endl;
                            return -1;
                        }
                        Registrator& fReg = get_Reg_obj();
                        cout << "Registrator is OK " << endl;
                        std::shared_ptr<ModuleBase> module = fReg.Create(1);
                        module -> SetPassword(password);
                        module -> AssignCommLine(TLDevice);
                        module -> session();
                        driverlog = TLDevice -> GetLogFromDriver();
            /*create_TestInterface_fun create_TestInterface = (create_TestInterface_fun) m_lib.resolve("create_TestInterface");
            if(!create_TestInterface)
                {
                    cout << "create_TestInterface is not loaded" << endl;
                    return -1;
                }
            // Вызываем функцию из библиотеки
            TI = create_TestInterface(password);
            setLineDevice_fun setLineDevice = (setLineDevice_fun)m_lib.resolve("setLineDevice");
            if(!setLineDevice)
            {
                cout << "setLineDevice is not loaded" << endl;
                return -1;
            }
            // Вызываем функцию
            setLineDevice(TI,TLD);

            testConnect_fun testConnect = (testConnect_fun)m_lib.resolve("testConnect");
            if(!testConnect)
            {
                cout<< "testConnect is not loaded"<<endl;
                return -1;
            }
            driverlog = testConnect(TI,password);
            cout<< "TestInterface loaded OK"<<endl;*/
            // Проверка совпадения
            for (int i=0;i<driverlog.size();i++)
            {
                if(log[i]!=driverlog[i])
                {
                    cout<<i<<"'s line is different"<<endl;
                }
            }
        }//if...
        return 0;
    }
