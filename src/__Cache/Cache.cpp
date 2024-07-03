#include "../../header/__Cache/Cache.h"

Cache* Cache::__cache_instance = nullptr;

Cache::Cache()
{

}

Cache::~Cache()
{
    for (auto key : __cache)
        delete key.second;
}

Cache* Cache::__get_cahce_instance()
{
    if (!__cache_instance)
        __cache_instance = new Cache();
    
    return __cache_instance;
}

void Cache::__delete_cache_instance()
{
    delete __cache_instance;
    __cache_instance = nullptr;
}

void Cache::__load_value (const std::string& nm, Base_Type* obj) 
{
    if (__cache.find(nm) != __cache.end()) {
        bool status = false;

        for (auto key : __cache)
            if ((key.second == obj) && (key.first != nm))
                status = true;

        if (status) {
            auto it = __cache.find(nm);
            (*it).second = obj;
        } else {
            auto it = __cache.find(nm);
            delete (*it).second;
            (*it).second = obj;
        }

    } else {
        __cache.insert({nm, obj});
    }
}

Base_Type* Cache::__get_val (const std::string& nm) 
{
    if (__cache.find(nm) == __cache.end())
        return nullptr;

    return __cache[nm];
}