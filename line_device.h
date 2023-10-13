#ifndef LINE_DEVICE_H
#define LINE_DEVICE_H

#include "base_types_impl.h"
#include "errors.h"
#include <memory>
//#include <boost/shared_ptr.hpp>

class LineDevice
{
public:
    virtual ~LineDevice()  noexcept(false);
    t_ret readPkt(BufferType& ibuf, size_t max_len = 0);
    t_ret writePkt(const BufferType& obuf);
private:
    virtual t_ret doReadPkt(BufferType& ibuf, size_t max_len) = 0;
    virtual t_ret doWritePkt(const BufferType& obuf) = 0;
};

//typedef boost::shared_ptr<LineDevice> t_line_device;
typedef std::shared_ptr<LineDevice> t_line_device;

#endif // LINE_DEVICE_H
