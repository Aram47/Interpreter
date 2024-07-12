#include "../../header/__Intersection/Intersection.h"

Intersection::Intersection()
{
    __cpw = new Copywriter();
}

Intersection::~Intersection()
{
    delete __cpw;
    __cpw = nullptr;
}

void Intersection::resolv(const vec_str& __instruction)
{
    std::string __type = std::move(__cpw->__instruction_type_deducetor(__instruction));
    if (__type == "Function")
    {

    }
    else if (__type == "Function Call")
    {
        
    }
    else if (__type == "Expression")
    {

    } 
    else if (__type == "Loop") 
    {

    }
    else if (__type == "Condition") 
    {

    }
    else
    {
        throw std::exception();
    }
}