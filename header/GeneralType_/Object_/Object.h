#ifndef OBJECT_H
#define OBJECT_H

#include "../GeneralType.h"

class Object : public General_Type
{
public:
    Object(const std::string&, const std::string&)    ;
    virtual ~Object()                              = 0;
    virtual std::string& __get_data()              = 0;
    virtual void __set_data(const std::string&)    = 0;
};

#endif