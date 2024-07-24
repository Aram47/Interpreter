#include "../../../../../header/__Types/__Base_Type/__Fundamental_Type/__String/String.h"

using pair_type_value = std::pair<std::string, std::string>;

// Constructors
String::String (const pair_type_value& __inp_value)
{
    this->__type  = __inp_value.first;
    this->__value = __inp_value.second;
}

String::String (const Base_Type& __other)
{
    this->__type  = __other.__get_type();
    this->__value = __other.__get_value();
}

// Logic 
pair_type_value 
String::operator && (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();
    if (
        (__rhv_type == "Undef") ||
        (__rhv_type == "Null")  ||
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
String::operator || (const Base_Type& __rhv) const
{
    return pair_type_value ({"Boolean", "true"});
}

pair_type_value 
String::operator == (const Base_Type& __rhv) const
{
    return this->__type != __rhv.__get_type()
        ? pair_type_value ({"Boolean", "false"})
        : this->__value == __rhv.__get_value()
        ? pair_type_value ({"Boolean", "true"})
        : pair_type_value ({"Boolean", "false"});
}

pair_type_value 
String::operator != (const Base_Type& __rhv) const
{
    return ((*this == __rhv).second == "false")
        ? pair_type_value ({"Boolean", "true"})
        : pair_type_value ({"Boolean", "false"});
}

pair_type_value 
String::operator < (const Base_Type& __rhv) const
{
    return this->__type != __rhv.__get_type()
        ? pair_type_value ({"Boolean", "false"})
        : this->__value < __rhv.__get_value()
        ? pair_type_value ({"Boolean", "true"})
        : pair_type_value ({"Boolean", "false"});
}

pair_type_value 
String::operator > (const Base_Type& __rhv) const
{
    return this->__type != __rhv.__get_type()
        ? pair_type_value ({"Boolean", "false"})
        : this->__value > __rhv.__get_value()
        ? pair_type_value ({"Boolean", "true"})
        : pair_type_value ({"Boolean", "false"});
}

pair_type_value 
String::operator <= (const Base_Type& __rhv) const
{
    return this->__type != __rhv.__get_type()
        ? pair_type_value ({"Boolean", "false"})
        : this->__value <= __rhv.__get_value()
        ? pair_type_value ({"Boolean", "true"})
        : pair_type_value ({"Boolean", "false"});
}

pair_type_value 
String::operator >= (const Base_Type& __rhv) const
{
    return this->__type != __rhv.__get_type()
        ? pair_type_value ({"Boolean", "false"})
        : this->__value >= __rhv.__get_value()
        ? pair_type_value ({"Boolean", "true"})
        : pair_type_value ({"Boolean", "false"});
}


// Ariphmetic
pair_type_value 
String::operator + (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();
    if (
        (__rhv_type == "Object") ||
        (__rhv_type == "Array")  ||
        (__rhv_type == "Function")
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    return pair_type_value ({"String", this->__value + __rhv.__get_value()});
}

pair_type_value 
String::operator - (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
} 

pair_type_value 
String::operator * (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
String::operator / (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
String::operator % (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
String::operator << (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
String::operator >> (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
String::operator | (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
String::operator & (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
String::operator ^ (const Base_Type& __rhv) const
{
    return pair_type_value ({"Number", "NaN"});
}


// Assignments
pair_type_value 
String::operator = (const Base_Type& __rhv) 
{
    return pair_type_value ({
        "String",
        this->__value = std::move(__rhv.__get_value())
    });
}


// Ariphmetic postfix and prefix inc/dec
pair_type_value 
String::operator ++ (int)    // value++
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
String::operator -- (int)    // value--
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
String::operator ++ ()       // ++value
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
String::operator -- ()       // --value
{
    return pair_type_value ({"Number", "NaN"});
}

pair_type_value 
String::operator [] (int __index)
{
    return __index >= (this->__value).size()
        ? pair_type_value ({"String", ""})
        : pair_type_value ({"String", std::string{(this->__value)[__index]}});
}