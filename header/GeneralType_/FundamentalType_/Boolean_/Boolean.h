#ifndef BOOLEAN_H
#define BOOLEAN_H

#include "../FundamentalType.h"

class Boolean : public Fundamental_Type
{
private:
    bool __data;
public:
    Boolean();
    ~Boolean();
    virtual std::string& __get_data()            override;
    virtual void __set_data(const std::string&)  override;
};

#endif // BOOLEAN_H