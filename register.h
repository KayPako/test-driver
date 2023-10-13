#pragma once

#include <map>
#include <stdexcept>

//#include <boost/shared_ptr.hpp>
//#include <boost/make_shared.hpp>
#include <memory>
#include <map>
class ModuleBase;

class Registrator
{
public:
    static Registrator& instance()
    {
        static Registrator registrator;
        return registrator;
    }
    void Add(std::shared_ptr<ModuleBase> module, const int id)
    {
        m_map[id] = module;
    }
    std::shared_ptr<ModuleBase> Create(const int id)
    {
        auto it = m_map.find(id);
        if (it != m_map.end())
        {
            return it->second;
        }
        return nullptr;
      //  throw std::runtime_error("No such module!");
    }
private:
    std::map<int, std::shared_ptr<ModuleBase>> m_map;
};

template <typename ModuleClass>
class RegHelper
{
public:
    RegHelper(std::shared_ptr<ModuleBase> module, const int id)
    {
        Registrator::instance().Add(module, id);
    }
};

#define REGISTER_MODULE(ModuleClass, id) \
    namespace \
    { \
        static ModuleClass module(id); \
        static RegHelper<ModuleClass> helper{std::make_shared<ModuleClass>(module), id}; \
    }
