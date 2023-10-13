#include "module_task.h"

namespace ecom_module
{

//==============================================================================
//  Класс Task
//==============================================================================

Task::Task(ModuleBase &module) :
    m_module(module)
{
}

Task::~Task()
{
}

void Task::Run()
{
    OnRun();
    doRun();
}

void Task::OnFailure()
{
    doOnFailure();
}

bool Task::NeedRun()
{
    return true;
}

ModuleBase& Task::Module()
{
    return m_module;
}

const ModuleBase& Task::GetModule() const
{
    return m_module;
}

// virtual
void Task::doOnFailure()
{
}

// virtual
void Task::OnRun()
{
}

//==============================================================================
//  Класс SessionOpenTask
//==============================================================================

SessionOpenTask::SessionOpenTask(ModuleBase& module, const BufferType& password) : Task(module), m_password(password)
{
}

// override
void SessionOpenTask::doRun()
{
    doSessionOpen(m_password);
}

//==============================================================================
//  Класс SessionCloseTask
//==============================================================================

SessionCloseTask::SessionCloseTask(ModuleBase& module) : Task(module)
{
}

// override
void SessionCloseTask::doRun()
{
    doSessionClose();
}

// override
void SessionCloseTask::doOnFailure()
{
    if (NeedRun())
    {
        doSessionClose();
    }
}

}