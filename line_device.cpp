#include "line_device.h"

LineDevice::~LineDevice() noexcept(false)
{
}

t_ret LineDevice::readPkt(t_Buffer& buf, size_t max_len)
{
    return doReadPkt(buf, max_len);
}

t_ret LineDevice::writePkt(const t_Buffer& buf)
{
    return doWritePkt(buf);
}
