#include "../../../../header/__Types/__Base_Type/__Object/Object.h"

using pair_type_value = std::pair<std::string, std::string>;
using object_members = std::unordered_map<std::string, Base_Type*>;

// Constructors
Object::Object (const pair_type_value& __inp_value)
{
    this->__type  = __inp_value.first;
    this->__value = __resolve_and_members_initalization(__inp_value.second);
}

Object::Object (const Base_Type& __other)
{
    this->__type  = __other.__get_type();
    this->__value = __other.__get_value();
}

// Logic 
pair_type_value 
Object::operator && (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();
    if (
        (__rhv_type == "Null")  ||
        (__rhv_type == "Undef") ||
        (
            (__rhv_type == "Boolean") &&
            (__rhv.__get_value() == "false")
        ) ||
        (
            (__rhv_type == "Number") &&
            (
                (__rhv.__get_value() == "NaN") ||
                (0 == std::stod(__rhv.__get_value()))
            )
        )
       )
    {
        return pair_type_value ({"Boolean", "false"});
    }

    return pair_type_value ({"Boolean", "true"});
}

pair_type_value 
Object::operator || (const Base_Type& __rhv) const
{
    return pair_type_value ({"Boolean", "true"});
}

pair_type_value 
Object::operator == (const Base_Type& __rhv) const
{
    return __rhv.__get_type() != this->__type
        ? pair_type_value ({"Boolean", "false"})
        : this->__value == __rhv.__get_value()
        ? pair_type_value ({"Boolean", "true"})
        : pair_type_value ({"Boolean", "false"});
}

pair_type_value 
Object::operator != (const Base_Type& __rhv) const
{
    return __rhv.__get_type() != this->__type
        ? pair_type_value ({"Boolean", "true"})
        : __rhv.__get_value() != this->__value
        ? pair_type_value ({"Boolean", "true"})
        : pair_type_value ({"Boolean", "false"});
}

pair_type_value 
Object::operator < (const Base_Type& __rhv) const
{
    return pair_type_value ({"Boolean", "false"});
}

pair_type_value 
Object::operator > (const Base_Type& __rhv) const
{
    return pair_type_value ({"Boolean", "false"});
}

pair_type_value 
Object::operator <= (const Base_Type& __rhv) const
{
    return (*this == __rhv).second == "true"
        ? pair_type_value ({"Boolean", "true"})
        : pair_type_value ({"Boolean", "false"});
}

pair_type_value 
Object::operator >= (const Base_Type& __rhv) const
{
    return (*this == __rhv).second == "true"
        ? pair_type_value ({"Boolean", "true"})
        : pair_type_value ({"Boolean", "false"});
}


// Ariphmetic
pair_type_value 
Object::operator + (const Base_Type& __rhv) const
{
    return __rhv.__get_type() != "String"
        ? pair_type_value ({"Number", "NaN"})
        : pair_type_value ({
            "String",
            this->__value + __rhv.__get_value()
        });
}

pair_type_value 
Object::operator - (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
} 

pair_type_value 
Object::operator * (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Object::operator / (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Object::operator % (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Object::operator << (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Object::operator >> (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Object::operator | (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Object::operator & (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Object::operator ^ (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}


// Assignments
pair_type_value 
Object::operator = (const Base_Type& __rhv) 
{
    this->__type  = __rhv.__get_type();
    this->__value = __rhv.__get_value();
}


// Ariphmetic postfix and prefix inc/dec
pair_type_value 
Object::operator ++ (int)    // value++
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Object::operator -- (int)    // value--
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Object::operator ++ ()       // ++value
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Object::operator -- ()       // --value
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Object::operator [] (const String& __key)
{
    if ((this->__members).find(__key.__get_value()) == __members.end())
    {
        this->__members.insert({__key.__get_value(), new Undef({"Undef", "Undef"})});
    }

    return pair_type_value ({
        (((this->__members).find(__key.__get_value()))->second)->__get_type(),
        (((this->__members).find(__key.__get_value()))->second)->__get_value()
    });
}

std::string Object::__resolve_and_members_initalization(const std::string&)
{
    
}

std::string Object::__new_lines_and_tabuliation_adder(const std::string&)
{

}

std::string Object::__key_value_catter(const std::string&)
{
    
}