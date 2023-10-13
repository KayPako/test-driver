#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "base_types_impl.h"

namespace ecom_protocol
{

class CmdProto;

class Transport
{
public:
    static const size_t NO_LENGTH = size_t(-1);
    virtual ~Transport();
    virtual void Send(CmdProto& command) = 0;
    virtual void Receive(CmdProto& command) = 0;
    virtual BufferType GetPassword() const
    {
        return BufferType();
    }
};

} // namespace ecom_protocol

using ecom_protocol::Transport;

#endif // TRANSPORT_H
