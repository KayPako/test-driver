#include "testlinedevice.h"
#include <vector>
#include <iostream>

TestLineDevice::TestLineDevice()
{

}

TestLineDevice::~TestLineDevice()
{

}

void TestLineDevice::SetExchLog(std::vector<std::vector<unsigned char>> new_exch_log)
{
    m_exch_log=new_exch_log;
    m_exch_log_iter=m_exch_log.begin();
    m_log_from_driver.clear();

}

// override
t_ret TestLineDevice::doReadPkt(BufferType& ibuf, size_t max_len)
{
//    std::cout<<"doReadPkt"<<std::endl;
    ibuf.clear();
    std::copy(m_exch_log_iter->begin(), m_exch_log_iter->end(),std::back_inserter<BufferType>(ibuf));
    m_log_from_driver.push_back(ibuf);
    m_exch_log_iter++;
    return RET_OK;
}

// override
t_ret TestLineDevice::doWritePkt(const BufferType& obuf)
{
  //  std::cout<<"doWritePkt"<<std::endl;
    m_log_from_driver.push_back(obuf);
    m_exch_log_iter++;
    return RET_OK;
}
