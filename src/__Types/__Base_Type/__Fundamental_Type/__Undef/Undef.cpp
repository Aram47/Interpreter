#include "../../../../../header/__Types/__Base_Type/__Fundamental_Type/__Undef/Undef.h"

using pair_type_value = std::pair<std::string, std::string>;

// Constructors
Undef::Undef (const pair_type_value& __inp_value)
{
    this->__type  = __inp_value.first;
    this->__value = __inp_value.second;
}

Undef::Undef (const Base_Type& __other)
{
    this->__type  = __other.__get_type();
    this->__value = __other.__get_value();
}

// Logic 
pair_type_value 
Undef::operator && (const Base_Type& __rhv) const
{
    return pair_type_value ({"Boolean", "false"});
}

pair_type_value 
Undef::operator || (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();
    if (
        (__rhv_type == "Null")  ||
        (__rhv_type == "Undef") ||
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
Undef::operator == (const Base_Type& __rhv) const
{
    return this->__type == __rhv.__get_type()
        ? pair_type_value ({"Boolean", "true"})
        : pair_type_value ({"Boolean", "false"}); 
}

pair_type_value 
Undef::operator != (const Base_Type& __rhv) const
{
    return ((*this == __rhv).second == "true")
        ? pair_type_value ({"Boolean", "false"})
        : pair_type_value ({"Boolean", "true"});
}

pair_type_value 
Undef::operator < (const Base_Type& __rhv) const
{
    return pair_type_value ({"Boolean", "false"});
}

pair_type_value 
Undef::operator > (const Base_Type& __rhv) const
{
    return pair_type_value ({"Boolean", "false"});
}

pair_type_value 
Undef::operator <= (const Base_Type& __rhv) const
{
    return ((*this == __rhv).second == "true")
        ? pair_type_value ("Boolean", "true")
        : pair_type_value ("Boolean", "false");
}

pair_type_value 
Undef::operator >= (const Base_Type& __rhv) const
{
    return ((*this == __rhv).second == "true")
        ? pair_type_value ("Boolean", "true")
        : pair_type_value ("Boolean", "false");
}


// Ariphmetic
pair_type_value 
Undef::operator + (const Base_Type& __rhv) const
{
    return __rhv.__get_type() == "String"
        ? pair_type_value ({"String", this->__value + __rhv.__get_value()})
        : pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Undef::operator - (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
} 

pair_type_value 
Undef::operator * (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Undef::operator / (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Undef::operator % (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Undef::operator << (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Undef::operator >> (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Undef::operator | (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Undef::operator & (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Undef::operator ^ (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}


// Assignments
pair_type_value 
Undef::operator = (const Base_Type& __rhv) 
{
    return pair_type_value ({
        "Undef",
        this->__value = std::move(__rhv.__get_value())
    });
}


// Ariphmetic postfix and prefix inc/dec
pair_type_value 
Undef::operator ++ (int)    // value++
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Undef::operator -- (int)    // value--
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Undef::operator ++ ()       // ++value
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Undef::operator -- ()       // --value
{
    return pair_type_value ({"Number", "NaN"});
}