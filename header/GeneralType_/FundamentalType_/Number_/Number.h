#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include "../FundamentalType.h"

class Number : public Fundamental_Type
{
private:
    long double __data;
public:
    Number();
    ~Number();
    virtual std::string& __get_data()            override;
    virtual void __set_data(const std::string&)  override;
};

#endif