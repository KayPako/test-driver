#ifndef ECOM_TRANSPORT_H
#define ECOM_TRANSPORT_H

#include "transport.h"
#include "concrete_transport.h"
#include "line_device.h"

class ModuleBase;

namespace ecom_protocol
{

class EcomLineConnection : public LineConnection
{
public:
    void ReadPacket(BufferType& buffer, const size_t maxLen) override;
    void WritePacket(const BufferType& buffer) override;
    void AssignLine(t_line_device line);
private:
    LineDevice& GetLine();
    t_line_device m_line;
};

/**
 * Базовый класс транспорта.
 * Реализует общий алгоритм обработки команд.
 */
class EcomTransport : public Transport
{
public:
    EcomTransport() = delete;
    EcomTransport(t_concrete_transport transport);

    /** Отправить запрос по команде
     * @param command обрабатываемая команда
     **/
    void Send(CmdProto& command) override;

    /** Получить ответ по команде
     * @param command обрабатываемая команда
     */
    void Receive(CmdProto& command) override;

    /** Привязать к линии связи
     * @param line привязываемая линия связи
     */
    void AssignLine(t_line_device line);
private:
    BufferType m_buffer; ///< общий буфер для обмена
    EcomLineConnection m_lineConnection;
    t_concrete_transport m_transport;
};

//typedef boost::shared_ptr<EcomTransport> t_ecom_transport;
typedef std::shared_ptr<EcomTransport> t_ecom_transport;

} // namespace ecom_protocol

#endif // ECOM_TRANSPORT_H
