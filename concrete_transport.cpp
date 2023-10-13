#include "concrete_transport.h"

namespace ecom_protocol
{

LineConnection::~LineConnection()
{
}

IConcreteTransport::~IConcreteTransport()
{
}

void IConcreteTransport::send(LineConnection& connection, const BufferType& buffer)
{
    doSend(connection, buffer);
}

void IConcreteTransport::recv(LineConnection& connection, BufferType& destination,
    const size_t payloadLen)
{
    doRecv(connection, destination, payloadLen);
}

} // namespace ecom_protocol
