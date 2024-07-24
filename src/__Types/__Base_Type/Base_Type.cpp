#include "../../../header/__Types/__Base_Type/Base_Type.h"

Base_Type::~Base_Type() 
{

}

std::string Base_Type::__get_type() const 
{
    return this->__type;
}

std::string Base_Type::__get_value() const
{
    return this->__value;
}