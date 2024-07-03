#include "../../../header/__Types/__Base_Type/Base_Type.h"

Base_Type::~Base_Type()
{

}

void Base_Type::set_type_name (const std::string& __inp_type_name)
{   
    this->__type_name = __inp_type_name;
}

std::string Base_Type::get_type_name ()
{
    return this->__type_name;
}