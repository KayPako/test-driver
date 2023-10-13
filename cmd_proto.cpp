#include "cmd_proto.h"

namespace ecom_protocol
{

//==============================================================================
//  Класс CmdSpec
//==============================================================================

CmdSpec& CmdSpec::NoRequest()
{
    m_needRequest = false;
    return *this;
}

bool CmdSpec::NeedRequest() const
{
    return m_needRequest;
}

bool CmdSpec::NeedSecondExhange() const
{
    return m_needSecondExchange;
}
/**
 * Без ответа
 * @return ссылка на самого себя
 */
CmdSpec& CmdSpec::NoReply()
{
    m_needReply = false;
    return *this;
}

/**
 * нужен повторный обмен кадрами
 * @return ссылка на самого себя
 */
CmdSpec& CmdSpec::SecondExchange()
{
    m_needSecondExchange = true;
    return *this;
}

/**
 * Задать размер ответа
 * @param replySize размер ответа
 * @return ссылка на самого себя
 */
CmdSpec& CmdSpec::ReplySize(const size_t replySize)
{
    m_replySize = replySize;
    return *this;
}

bool CmdSpec::NeedReply() const
{
    return m_needReply;
}

size_t CmdSpec::GetReplySize() const
{
    return m_replySize;
}

//==============================================================================
//  Класс CmdProto
//==============================================================================

CmdProto::CmdProto(const CmdSpec& spec) :
    m_spec(spec)
{
}

void CmdProto::Execute(Transport& transport)
{
    DoBeforeExecute(transport);
    Exch(transport);
}

void CmdProto::DoBeforeExecute(Transport& transport)
{
    (void)transport;
}

/**
 * Получить спецификацию команды
 * @return спецификация команды
 */
CmdSpec& CmdProto::spec()
{
    return m_spec;
}

const CmdSpec& CmdProto::spec() const
{
    return m_spec;
}


void CmdProto::Exch(Transport& transport)
{
    if (spec().NeedRequest())
    {
        Send(transport);
    }
    if (spec().NeedReply())
    {
        Recv(transport);
    }
    if(spec().NeedSecondExhange())
    {
        Send(transport);
        Recv(transport);
    }
}

void CmdProto::Send(Transport& transport)
{
    doBeforeSend(transport);
    transport.Send(*this);
    doAfterSend(transport);
}

// virtual
void CmdProto::doBeforeSend(Transport& transport)
{
    (void)transport;
}

// virtual
void CmdProto::doAfterSend(Transport& transport)
{
    (void)transport;
}

void CmdProto::Recv(Transport& transport)
{
    doBeforeRecv(transport);
    transport.Receive(*this);
    doAfterRecv(transport);
}

// virtual
void CmdProto::doBeforeRecv(Transport& transport)
{
    (void)transport;
}

// virtual
void CmdProto::doAfterRecv(Transport& transport)
{
    (void)transport;
}

void CmdProto::encode(t_Buffer &buf)
{
    doEncode(buf);
}

void CmdProto::decode(const BufferType &buf)
{
    doDecode(buf);
}

void CmdProto::doEncode(BufferType& buffer)
{
    (void)buffer;
}

void CmdProto::doDecode(const BufferType& buffer)
{
    (void)buffer;
}

} // namespace ecom_protocol
