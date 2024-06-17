#ifndef STRING_H
#define STRING_H

#include "../FundamentalType.h"

class String : public Fundamental_Type
{
private:
    std::string __data;
public:
    String();
    ~String();
    virtual std::string& __get_data()            override;
    virtual void __set_data(const std::string&)  override;
};

#endif // STRING_H