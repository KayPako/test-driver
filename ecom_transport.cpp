#include "ecom_transport.h"

#include "module_base.h"
#include "cmd_proto.h"

namespace ecom_protocol
{

//==============================================================================
//  Класс EcomLineConnection
//==============================================================================

// override
void EcomLineConnection::ReadPacket(BufferType& buffer, const size_t maxLen)
{
    GetLine().readPkt(buffer, maxLen);
}

// override
void EcomLineConnection::WritePacket(const BufferType& buffer)
{
    GetLine().writePkt(buffer);
}

void EcomLineConnection::AssignLine(t_line_device line)
{
    m_line = line;
}

LineDevice& EcomLineConnection::GetLine()
{
    return *m_line;
}

//==============================================================================
//  Класс EcomTransport
//==============================================================================

EcomTransport::EcomTransport(t_concrete_transport transport) :
    m_transport(transport)
{
}

// override
void EcomTransport::Send(CmdProto& command)
{
    m_buffer.clear();
    command.encode(m_buffer);
    m_transport->send(m_lineConnection, m_buffer);
}

// override
void EcomTransport::Receive(CmdProto& command)
{
    m_buffer.clear();
    m_transport->recv(m_lineConnection, m_buffer, command.spec().GetReplySize());
    command.decode(m_buffer);
}

void EcomTransport::AssignLine(t_line_device line)
{
    m_lineConnection.AssignLine(line);
}

} // namespace ecom_protocol
