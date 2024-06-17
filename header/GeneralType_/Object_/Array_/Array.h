#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include "../../GeneralType.h"
#include "../Object.h"

class Array : public Object
{
private:
    std::vector<General_Type*> __data;
public:
    Array();
    ~Array();
    virtual std::string& __get_data()            override;
    virtual void __set_data(const std::string&)  override;
};

#endif