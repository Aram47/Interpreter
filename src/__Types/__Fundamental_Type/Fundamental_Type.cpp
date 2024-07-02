#include "../../header/__Types/__Fundamental_Type/Fundamental_Type.h"

Fundamental_Type::~Fundamental_Type()
{

}

void Fundamental_Type::set_value (const std::string& __inp_value)
{
    this->__value = __inp_value;
}

std::string Fundamental_Type::get_value ()
{
    return this->__value;
}