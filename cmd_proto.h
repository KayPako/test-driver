#ifndef CMD_PROTO_H
#define CMD_PROTO_H

//#include "ecom_transport.h"
#include "transport.h"

namespace ecom_protocol
{

/**
 * Спецификация параметров команды.
 * Параметризует общие алгоритмы обработки команды протоколом.
 */
class CmdSpec
{
public:
    CmdSpec& NoRequest();
    CmdSpec& NoReply();
    CmdSpec& SecondExchange();
    CmdSpec& ReplySize(const size_t replySize);
    bool NeedRequest() const;
    bool NeedReply() const;
    bool NeedSecondExhange() const;
    size_t GetReplySize() const;
private:
    bool m_needRequest = true; ///< не посылать запрос
    bool m_needReply = true; ///< команда парная, требуется ответ от устройства
    bool m_needSecondExchange=false; ///< требуется ли два обмена в команде
    size_t m_replySize = 0; ///< размер ожидаемого ответа (без учета заголовков и концевиков протокола)
};

/**
 * Базовый класс команд протокола
 */
class CmdProto
{
public:
    virtual ~CmdProto()
    {
    }
    CmdProto(const CmdSpec& spec = CmdSpec());
    /**
     * Сериализовать команду в буфер
     * @param buf буфер куда сериализуем
     */
    void encode(BufferType& buf);
    /**
     * Десериализовать команду из буфер
     * @param buf буфер откуда десериализуем
     */
    void decode(const BufferType& buf);
    /** Выполнить команду. */
    void Execute(Transport& transport);
    /** Спецификация команды */
    const CmdSpec& spec() const;
    CmdSpec& spec();
private:
    virtual void doBeforeSend(Transport& transport); ///< обработчик перед посылкой протоколу
    virtual void doAfterSend(Transport& transport);  ///< обработчик после посылки протоколу
    virtual void doBeforeRecv(Transport& transport); ///< обработчик перед приемом от протокола
    virtual void doAfterRecv(Transport& transport);  ///< обработчик после приема от протокола
    virtual void doEncode(BufferType& buffer); ///< закодировать пакет
    virtual void doDecode(const BufferType& buffer); ///< декодировать принятый пакет
    virtual void DoBeforeExecute(Transport& transport);
    void Send(Transport& transport);
    void Recv(Transport& transport);
    void Exch(Transport& transport);
    CmdSpec m_spec; ///< параметризация общих алгоритмов обработки команды
};

template<class T>
class CommandWithResult
{
public:
    typedef T ResultType;
    CommandWithResult() : m_result()
    {
    }
    void SetResult(const ResultType& result)
    {
        m_result = result;
    }
    const ResultType& GetResult() const
    {
        return m_result;
    }
private:
    ResultType m_result;
};

} // namespace ecom_protocol

#endif // CMD_PROTO_H
