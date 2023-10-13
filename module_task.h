#ifndef MODULE_TASK_H
#define MODULE_TASK_H

#include <vector>
#include <string>

#include "base_types_impl.h"
#include<memory>
//#include <boost/shared_ptr.hpp>
//#include <boost/make_shared.hpp>

class ModuleBase;

namespace ecom_module
{

/** Задача
 */
class Task
{
public:
    Task(ModuleBase& module);
    virtual ~Task();
    void Run();
    void OnFailure();
    virtual bool NeedRun();
protected:
    // void exch(ecom_protocol::CmdProto& cmd);
    ModuleBase& Module();
    const ModuleBase& GetModule() const;
private:
    virtual void doRun() = 0;
    virtual void doOnFailure();
    virtual void OnRun();

    ModuleBase& m_module;
};

//typedef boost::shared_ptr<Task> t_task;
typedef std::shared_ptr<Task> t_task;
typedef std::vector<t_task> t_tasks;

class SessionOpenTask : public Task
{
public:
    SessionOpenTask(ModuleBase& module, const BufferType& password);
private:
    void doRun() override;
    virtual void doSessionOpen(const BufferType& password) = 0;
    const BufferType m_password;
};

class SessionCloseTask : public Task
{
public:
    SessionCloseTask(ModuleBase &module);
private:
    void doRun() override;
    virtual void doSessionClose() = 0;
    void doOnFailure() override;
};

} // namespace ecom_module

/**
 * Создать задачу без параметров
 * @param module связанный модуль
 * @return объект задачи
 */
template<typename TASK, typename MODULE>
//boost::shared_ptr<TASK> make_task(MODULE &module)
std::shared_ptr<TASK> make_task(MODULE &module)
{
    return std::make_shared<TASK>(module);
}

/**
 * Создать задачу с параметром ссылкой
 * @param module связанный модуль
 * @param r1 параметр-ссылка
 * @return объект задачи
 */
template<typename TASK, typename MODULE, typename R1>
std::shared_ptr<TASK> make_task(MODULE& module, const R1& r1)
{
    return std::make_shared<TASK>(module, r1);
}

template<typename TASK, typename MODULE, typename R1>
std::shared_ptr<TASK> make_task_param(MODULE& module, R1& r1)
{
    return std::make_shared<TASK>(module, r1);
}

#endif // MODULE_TASK_H
