#ifndef NAN_H
#define NAN_H

#include "../FundamentalType.h"

class Nan : public Fundamental_Type
{
private:
    std::string __data;
public:
    Nan();
    ~Nan();
    virtual std::string& __get_data()            override;
    virtual void __set_data(const std::string&)  override;
};

#endif