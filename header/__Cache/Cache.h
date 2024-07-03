#ifndef CACHE_H
#define CACHE_H

#include <unordered_map>
#include <string>
#include "../__Types/__Base_Type/Base_Type.h"

class Cache {
    std::unordered_map<std::string, Base_Type*> __cache;
    static Cache*                      __cache_instance;
    Cache();
public:
    Cache(const Cache&) = delete;
    ~Cache();
    static Cache* __get_cahce_instance();
    static void   __delete_cache_instance();
    void          __load_value (const std::string&, Base_Type*);
    Base_Type*    __get_val (const std::string&);
};

#endif // CACHE_H