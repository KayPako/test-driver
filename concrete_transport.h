#ifndef CONCRETE_TRANSPORT_H
#define CONCRETE_TRANSPORT_H

#include "base_types_impl.h"
#include<memory>
//#include <boost/shared_ptr.hpp>

namespace ecom_protocol
{

/** Соединение по линии связи, ограничивает доступные операции над линией связи чтением/записью пакетов
 */
class LineConnection
{
public:
    virtual ~LineConnection();
    virtual void ReadPacket(BufferType& buffer, const size_t maxLen) = 0;
    virtual void WritePacket(const BufferType& buffer) = 0;
};

/** Интерфейс конкретного транспорта */
class IConcreteTransport
{
public:
    virtual ~IConcreteTransport();
    void send(LineConnection& connection, const BufferType& buffer);
    void recv(LineConnection& connection, BufferType& destination, const size_t payloadLen);
private:
    /** Конкретный алгоритм посылки команды запроса
     *
     * @param connection соединение
     * @param buffer пакет
     */
    virtual void doSend(LineConnection& connection, const BufferType& buffer) = 0;
    /** Конкретный алгоритм приёма ответа команды
     *
     * @param connection соединение
     * @param destination буфер, куда принимаем
     * @param payloadLen длина запрошенных данных
     */
    virtual void doRecv(LineConnection& connection, BufferType& destination,
        const size_t payloadLen) = 0; ///< конкретный алгоритм приёма команды ответа
};

//typedef boost::shared_ptr<IConcreteTransport> t_concrete_transport;
typedef std::shared_ptr<IConcreteTransport> t_concrete_transport;

// /** Простой сквозной транспорт */
// class SimpleTransport : public IConcreteTransport
// {
// protected:
//     virtual void doSend(LineConnection& connection, const BufferType& buffer);
//     virtual void doRecv(LineConnection& connection, BufferType& destination, const size_t payloadLen);
// };

} // namespace ecom_protocol

#endif // CONCRETE_TRANSPORT_H
