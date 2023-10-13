#ifndef MODULE_BASE_H
#define MODULE_BASE_H

#include <vector>
#include "line_device.h"
#include "errors.h"
#include "module_task.h"
#include "cmd_proto.h"
#include "ecom_transport.h"

class ModuleBase
{
public:
    ModuleBase(const int a);
    ModuleBase(const std::vector<unsigned char>& password);
    virtual ~ModuleBase();
    t_ret session();

    void AddTask(ecom_module::t_task task);
    void ExchCmd(ecom_protocol::CmdProto& command);
    void SetTransport(ecom_protocol::t_concrete_transport transport);
    void AssignCommLine(t_line_device commLine); //< назначить(привязать) линию связи
    const BufferType& GetPassword();
    virtual void SetPassword(const BufferType& password) {m_password=password;};
private:
    virtual t_ret doSession();
    ecom_module::t_tasks m_tasks;
    ecom_protocol::t_ecom_transport m_transport;
    t_line_device m_commLine; //< текущая линия связи
    BufferType m_password;
    int m_a;
};

/*template<class CommandType> class CommandWithResultRunner
{
public:
    CommandWithResultRunner()
    {
    }
    template<class ARG1>
    CommandWithResultRunner(const ARG1& arg1) :
        m_command(arg1)
    {
    }
    template<class ARG1, class ARG2>
    CommandWithResultRunner(const ARG1& arg1, const ARG2& arg2) :
        m_command(arg1, arg2)
    {
    }
    template<class ARG1, class ARG2, class ARG3>
    CommandWithResultRunner(const ARG1& arg1, const ARG2& arg2, const ARG3& arg3) :
        m_command(arg1, arg2, arg3)
    {
    }
    template<class ARG1, class ARG2, class ARG3, class ARG4>
    CommandWithResultRunner(const ARG1& arg1, const ARG2& arg2, const ARG3& arg3, const ARG4& arg4) :
        m_command(arg1, arg2, arg3, arg4)
    {
    }
    template<class ARG1, class ARG2, class ARG3, class ARG4>
    CommandWithResultRunner(const ARG1& arg1, const ARG2& arg2, const ARG3& arg3, ARG4& arg4) :
        m_command(arg1, arg2, arg3, arg4)
    {
    }
    typename CommandType::ResultType GetResult(ModuleBase& module)
    {
        module.ExchCmd(m_command);
        return m_command.GetResult();
    }
    typename CommandType::ResultType GetResult(Transport& transport)
    {
        m_command.Execute(transport);
        return m_command.GetResult();
    }
private:
    CommandType m_command;
};

template<class CommandType> class CommandRunner
{
public:
    CommandRunner()
    {
    }
    template<class ARG1> CommandRunner(const ARG1& arg1) : m_command(arg1)
    {
    }
    template<class ARG1> CommandRunner(ARG1& arg1) : m_command(arg1)
    {
    }
    template<class ARG1, class ARG2> CommandRunner(const ARG1& arg1, const ARG2& arg2) :
        m_command(arg1, arg2)
    {
    }
    template<class ARG1, class ARG2> CommandRunner(ARG1& arg1, ARG2& arg2) :
        m_command(arg1, arg2)
    {
    }
    template<class ARG1, class ARG2, class ARG3> CommandRunner(const ARG1& arg1, const ARG2& arg2, const ARG3& arg3) :
        m_command(arg1, arg2, arg3)
    {
    }
    template<class ARG1, class ARG2, class ARG3, class ARG4> CommandRunner(const ARG1& arg1, const ARG2& arg2, const ARG3& arg3, const ARG4& arg4) :
        m_command(arg1, arg2, arg3, arg4)
    {
    }
    template<class ARG1, class ARG2, class ARG3, class ARG4> CommandRunner(const ARG1& arg1, const ARG2& arg2, const ARG3& arg3, ARG4& arg4) :
        m_command(arg1, arg2, arg3, arg4)
    {
    }
    void Run(ModuleBase& module)
    {
        module.ExchCmd(m_command);
    }
    void Run(Transport& transport)
    {
        m_command.Execute(transport);
    }
private:
    CommandType m_command;
};*/

#endif // MODULE_BASE_H
