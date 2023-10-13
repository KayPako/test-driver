#ifndef TESTLINEDEVICE_H
#define TESTLINEDEVICE_H

#include "line_device.h"
#include <vector>

class TestLineDevice: public LineDevice
{
public:
    TestLineDevice();
    ~TestLineDevice();
    void SetExchLog(std::vector<std::vector<unsigned char>> new_exch_log);
    const std::vector<std::vector<unsigned char>>& GetLogFromDriver() {return m_log_from_driver;};
private:
    t_ret doReadPkt(BufferType& ibuf, size_t max_len) override;
    t_ret doWritePkt(const BufferType& obuf) override;
    std::vector<std::vector<unsigned char>> m_exch_log;
    std::vector<std::vector<unsigned char>>::iterator m_exch_log_iter;
    std::vector<std::vector<unsigned char>> m_log_from_driver;
};

/*extern "C" TestLineDevice* create_TestLineDevice()
{
    return new TestLineDevice;
}

extern "C" void setExchLog(TestLineDevice* testlinedevice, std::vector<std::vector<unsigned char>> new_exch_log)
{
   testlinedevice->SetExchLog(new_exch_log);
}*/

#endif // TESTLINEDEVICE_H
