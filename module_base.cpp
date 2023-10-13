#include "module_base.h"

//#include <boost/make_shared.hpp>

ModuleBase::ModuleBase(int a):m_a{a}
{
}

ModuleBase::ModuleBase(const BufferType& password) :
    m_password(password)
{
}

ModuleBase::~ModuleBase()
{
}

t_ret ModuleBase::session()
{
    return doSession();
}

//virtual
t_ret ModuleBase::doSession()
{
    ecom_module::t_tasks::iterator task;
    for (task = m_tasks.begin(); task != m_tasks.end(); ++task)
    {
        ecom_module::t_task t = *task;
        if (t->NeedRun())
        {
            t->Run();
        }
    }

    return RET_OK;
}

/** Добавить задачу в контейнер задач сессии
 * @param task добавляемая задача
 */
void ModuleBase::AddTask(ecom_module::t_task task)
{
    m_tasks.push_back(task);
}

void ModuleBase::ExchCmd(ecom_protocol::CmdProto& command)
{
    command.Execute(*m_transport);
}

void ModuleBase::SetTransport(ecom_protocol::t_concrete_transport concrete_transport)
{
    m_transport = std::make_shared<ecom_protocol::EcomTransport>(concrete_transport);
}

void ModuleBase::AssignCommLine(t_line_device commLine)
{
    m_commLine = commLine;
    m_transport->AssignLine(m_commLine);
}

const BufferType& ModuleBase::GetPassword()
{
    return m_password;
}
