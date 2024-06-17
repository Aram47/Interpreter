#ifndef FUNDAMENTAL_TYPE_H
#define FUNDAMENTAL_TYPE_H

#include "../GeneralType.h"

class Fundamental_Type : public General_Type
{
public:
    Fundamental_Type(const std::string&, const std::string&);
    virtual ~Fundamental_Type()                          = 0;
    virtual std::string& __get_data()                    = 0;
    virtual void __set_data(const std::string&)          = 0;
};

#endif // FUNDAMENTAL_TYPE_H