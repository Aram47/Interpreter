#include "../../../header/__Types/__Object/Object.h"

Object::Object(std::vector<std::string>)
{

}

Object::Object(const Object&)
{

}

Base_Type* Object::__get_value(const std::string& __key)
{
    return (__properties.find(__key) != __properties.end()) ? __properties.find(__key)->second : nullptr; 
}