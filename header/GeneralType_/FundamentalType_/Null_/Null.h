#ifndef NULL_H
#define NULL_H

#include "../FundamentalType.h"

class Null : public Fundamental_Type
{
private:
    std::string __data;
public:
    Null();
    ~Null();
    virtual std::string& __get_data()            override;
    virtual void __set_data(const std::string&)  override;
};

#endif