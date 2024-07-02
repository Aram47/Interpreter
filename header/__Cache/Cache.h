#ifndef CACHE_H
#define CACHE_H

#include <unordered_map>
#include <string>

class Base_Type;

class Cache {
    std::unordered_map<std::string, Base_Type*> __cache;
    static Cache*                      __cache_instance;
    Cache();
public:
    Cache(const Cache&) = delete;
    ~Cache();
    static Cache* __get_cahce_instance();
    void          __load_value (const std::string&, Base_Type*);
    Base_Type*    __get_val (const std::string&);
};

Cache* Cache::__cache_instance = nullptr;

#endif // CACHE_H