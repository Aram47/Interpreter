#ifndef OBJECT_H
#define OBJECT_H

#include <unordered_map>
#include <vector>
#include <string>
#include "../__Base_Type/Base_Type.h"

class Object : public Base_Type
{
private:
    std::unordered_map<std::string, Base_Type*> __properties;
public:
    explicit Object(std::vector<std::string>);
    Object(const Object&);
    Base_Type* __get_value(const std::string&); // std::string key
};

#endif