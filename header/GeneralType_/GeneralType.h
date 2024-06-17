#ifndef GENERAL_TYPE_H
#define GENERAL_TYPE_H

#include <string>

class General_Type
{
private:
    std::string      __name;
    std::string      __type;
public:
    General_Type(const std::string&, const std::string&);
    virtual ~General_Type()                          = 0;
    virtual std::string& __get_data()                = 0;
    virtual void __set_data(const std::string&)      = 0;
    std::string __get_name();
    std::string __get_type();
};

#endif