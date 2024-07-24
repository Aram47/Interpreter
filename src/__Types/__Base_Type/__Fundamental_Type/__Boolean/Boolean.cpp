#include "../../../../../header/__Types/__Base_Type/__Fundamental_Type/__Boolean/Boolean.h"

using pair_type_value = std::pair<std::string, std::string>;

// Constructors
Boolean::Boolean (const pair_type_value& __inp_value)
{
    this -> __type  = __inp_value.first;
    this -> __value = __inp_value.second;
}

Boolean::Boolean (const Base_Type& __other)
{
    this -> __type  = __other.__get_type();
    this -> __value = __other.__get_value();
}

// Logic 
pair_type_value 
Boolean::operator && (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();

    if (
        (this->__value == "false") ||
        (__rhv_type == "Undef")    ||
        (__rhv_type == "Null")     ||
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
Boolean::operator || (const Base_Type& __rhv) const
{
    if (this->__value == "true")
    {
        return pair_type_value ({"Boolean", "true"});
    }

    std::string __rhv_type = __rhv.__get_type();

    if (
        (__rhv_type == "Undef")    ||
        (__rhv_type == "Null")     ||
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
Boolean::operator == (const Base_Type& __rhv) const
{
    if (
        (__rhv.__get_type() == "Number") &&
        (__rhv.__get_value() != "NaN")
       )
    {
        if (
            (
                (std::stod(__rhv.__get_value()) == 0) &&
                (this->__value == "false")
            ) ||
            (
                (std::stod(__rhv.__get_value()) == 1) &&
                (this->__value == "true")
            )
           )
        {
            return pair_type_value ({"Boolean", "true"});
        } 
    }

    if (__rhv.__get_type() != "Boolean")
    {
        return pair_type_value ({"Boolean", "false"});
    }

    return this->__value == __rhv.__get_value()
        ? pair_type_value ({"Boolean", "true"})
        : pair_type_value ({"Boolean", "false"});
}

pair_type_value 
Boolean::operator != (const Base_Type& __rhv) const
{
    if (
        (__rhv.__get_type() == "Number") &&
        (__rhv.__get_value() != "NaN")
       )
    {
        if (
            (
                (std::stod(__rhv.__get_value()) == 0) &&
                (this->__value == "false")
            ) ||
            (
                (std::stod(__rhv.__get_value()) == 1) &&
                (this->__value == "true")
            )
           )
        {
            return pair_type_value ({"Boolean", "false"});
        } 
    }

    if (__rhv.__get_type() != "Boolean")
    {
        return pair_type_value ({"Boolean", "true"});
    }

    return this->__value != __rhv.__get_value()
        ? pair_type_value ({"Boolean", "true"})
        : pair_type_value ({"Boolean", "false"});
}

pair_type_value 
Boolean::operator < (const Base_Type& __rhv) const
{
    if (
        (__rhv.__get_type() == "Number") &&
        (__rhv.__get_value() != "NaN")
       )
    {
        if (
            (
                (std::stod(__rhv.__get_value()) >= 0) &&
                (this->__value == "false")
            ) ||
            (
                (std::stod(__rhv.__get_value()) >= 1) &&
                (this->__value == "true")
            )
           )
        {
            return pair_type_value ({"Boolean", "false"});
        } 
    }

    if (__rhv.__get_type() != "Boolean")
    {
        return pair_type_value ({"Boolean", "true"});
    }

    return (
            (this->__value == "false") && 
            (__rhv.__get_value() == "true")
           )
           ? pair_type_value ({"Boolean", "true"})
           : pair_type_value ({"Boolean", "false"}); 
}

pair_type_value 
Boolean::operator > (const Base_Type& __rhv) const
{
    if (
        (__rhv.__get_type() == "Number") &&
        (__rhv.__get_value() != "NaN")
       )
    {
        if (
            (
                (std::stod(__rhv.__get_value()) <= 0) &&
                (this->__value == "false")
            ) ||
            (
                (std::stod(__rhv.__get_value()) <= 1) &&
                (this->__value == "true")
            )
           )
        {
            return pair_type_value ({"Boolean", "false"});
        } 
    }

    if (__rhv.__get_type() != "Boolean")
    {
        return pair_type_value ({"Boolean", "true"});
    }

    return (
            (this->__value == "true") && 
            (__rhv.__get_value() == "false")
           )
           ? pair_type_value ({"Boolean", "true"})
           : pair_type_value ({"Boolean", "false"}); 
}

pair_type_value 
Boolean::operator <= (const Base_Type& __rhv) const
{
    if (
        (__rhv.__get_type() == "Number") &&
        (__rhv.__get_value() != "NaN")
       )
    {
        if (
            (
                (std::stod(__rhv.__get_value()) > 0) &&
                (this->__value == "false")
            ) ||
            (
                (std::stod(__rhv.__get_value()) > 1) &&
                (this->__value == "true")
            )
           )
        {
            return pair_type_value ({"Boolean", "false"});
        } 
    }

    if (__rhv.__get_type() != "Boolean")
    {
        return pair_type_value ({"Boolean", "true"});
    }
    
    return ((this->__value == "false") || (this->__value == __rhv.__get_value()))
           ? pair_type_value ({"Boolean", "true"})
           : pair_type_value ({"Boolean", "false"}); 
}

pair_type_value 
Boolean::operator >= (const Base_Type& __rhv) const
{
    if (
        (__rhv.__get_type() == "Number") &&
        (__rhv.__get_value() != "NaN")
       )
    {
        if (
            (
                (std::stod(__rhv.__get_value()) < 0) &&
                (this->__value == "false")
            ) ||
            (
                (std::stod(__rhv.__get_value()) < 1) &&
                (this->__value == "true")
            )
           )
        {
            return pair_type_value ({"Boolean", "false"});
        } 
    }

    if (__rhv.__get_type() != "Boolean")
    {
        return pair_type_value ({"Boolean", "true"});
    }
    
    return ((this->__value == "true") || (this->__value == __rhv.__get_value()))
           ? pair_type_value ({"Boolean", "true"})
           : pair_type_value ({"Boolean", "false"}); 
}

// Ariphmetic
pair_type_value 
Boolean::operator + (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();

    if (
        (__rhv_type == "Object") ||
        (__rhv_type == "Function")
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    // if (__rhv_type == "Array")
    // {

    // }

    if (__rhv_type == "Number")
    {
        if (__rhv.__get_value() == "NaN")
        {
            return pair_type_value ({"String", this->__value + __rhv.__get_value()});
        }

        return this->__value == "true" 
            ? pair_type_value ({"Number", std::to_string(1 + std::stod(__rhv.__get_value()))})
            : pair_type_value ({"Number", std::to_string(0 + std::stod(__rhv.__get_value()))});
    }

    return pair_type_value ({"String", this->__value + __rhv.__get_value()});
}

pair_type_value 
Boolean::operator - (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();

    if (
        (__rhv_type == "Object")   ||
        (__rhv_type == "Function") ||
        (__rhv_type == "Array")    ||
        (__rhv_type == "String")   ||
        (__rhv_type == "Undef")    ||
        (__rhv_type == "Null")     ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    
    return this->__value == "true" 
        ? pair_type_value ({"Number", std::to_string(1 - std::stod(__rhv.__get_value()))})
        : pair_type_value ({"Number", std::to_string(0 - std::stod(__rhv.__get_value()))});
} 

pair_type_value 
Boolean::operator * (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();
    
    if (
        (__rhv_type == "Object")   ||
        (__rhv_type == "Function") ||
        (__rhv_type == "Array")    ||
        (__rhv_type == "String")   ||
        (__rhv_type == "Undef")    ||
        (__rhv_type == "Null")     ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    
    return this->__value == "true" 
        ? pair_type_value ({"Number", std::to_string(1 * std::stod(__rhv.__get_value()))})
        : pair_type_value ({"Number", std::to_string(0 * std::stod(__rhv.__get_value()))});
}

pair_type_value 
Boolean::operator / (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();
    
    if (
        (__rhv_type == "Object")   ||
        (__rhv_type == "Function") ||
        (__rhv_type == "Array")    ||
        (__rhv_type == "String")   ||
        (__rhv_type == "Undef")    ||
        (__rhv_type == "Null")     ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    
    return this->__value == "true" 
        ? pair_type_value ({"Number", std::to_string(1 / std::stod(__rhv.__get_value()))})
        : pair_type_value ({"Number", "NaN"});
}

pair_type_value 
Boolean::operator % (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();
    
    if (
        (__rhv_type == "Object")   ||
        (__rhv_type == "Function") ||
        (__rhv_type == "Array")    ||
        (__rhv_type == "String")   ||
        (__rhv_type == "Undef")    ||
        (__rhv_type == "Null")     ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    long long int __rhv_value = std::stod(__rhv.__get_value());
    
    return this->__value == "true" 
        ? pair_type_value ({"Number", std::to_string(1 % __rhv_value)})
        : pair_type_value ({"Number", std::to_string(0 % __rhv_value)});
}

pair_type_value 
Boolean::operator << (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();
    
    if (
        (__rhv_type == "Object")   ||
        (__rhv_type == "Function") ||
        (__rhv_type == "Array")    ||
        (__rhv_type == "String")   ||
        (__rhv_type == "Undef")    ||
        (__rhv_type == "Null")     ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    long long int __rhv_value = std::stod(__rhv.__get_value());
    
    return this->__value == "true" 
        ? pair_type_value ({"Number", std::to_string(1 << __rhv_value)})
        : pair_type_value ({"Number", std::to_string(0 << __rhv_value)});
}

pair_type_value 
Boolean::operator >> (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();
    
    if (
        (__rhv_type == "Object")   ||
        (__rhv_type == "Function") ||
        (__rhv_type == "Array")    ||
        (__rhv_type == "String")   ||
        (__rhv_type == "Undef")    ||
        (__rhv_type == "Null")     ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    long long int __rhv_value = std::stod(__rhv.__get_value());
    
    return this->__value == "true" 
        ? pair_type_value ({"Number", std::to_string(1 >> __rhv_value)})
        : pair_type_value ({"Number", std::to_string(0 >> __rhv_value)});
}

pair_type_value 
Boolean::operator | (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();
    
    if (
        (__rhv_type == "Object")   ||
        (__rhv_type == "Function") ||
        (__rhv_type == "Array")    ||
        (__rhv_type == "String")   ||
        (__rhv_type == "Undef")    ||
        (__rhv_type == "Null")     ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    long long int __rhv_value = std::stod(__rhv.__get_value());
    
    return this->__value == "true" 
        ? pair_type_value ({"Number", std::to_string(1 | __rhv_value)})
        : pair_type_value ({"Number", std::to_string(0 | __rhv_value)});
}

pair_type_value 
Boolean::operator & (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();
    
    if (
        (__rhv_type == "Object")   ||
        (__rhv_type == "Function") ||
        (__rhv_type == "Array")    ||
        (__rhv_type == "String")   ||
        (__rhv_type == "Undef")    ||
        (__rhv_type == "Null")     ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    long long int __rhv_value = std::stod(__rhv.__get_value());
    
    return this->__value == "true" 
        ? pair_type_value ({"Number", std::to_string(1 & __rhv_value)})
        : pair_type_value ({"Number", std::to_string(0 & __rhv_value)});
}

pair_type_value 
Boolean::operator ^ (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();
    
    if (
        (__rhv_type == "Object")   ||
        (__rhv_type == "Function") ||
        (__rhv_type == "Array")    ||
        (__rhv_type == "String")   ||
        (__rhv_type == "Undef")    ||
        (__rhv_type == "Null")     ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    long long int __rhv_value = std::stod(__rhv.__get_value());
    
    return this->__value == "true" 
        ? pair_type_value ({"Number", std::to_string(1 ^ __rhv_value)})
        : pair_type_value ({"Number", std::to_string(0 ^ __rhv_value)});
}


// Assignments
pair_type_value 
Boolean::operator = (const Base_Type& __rhv)
{
    return pair_type_value ({
        "Boolean",
        this->__value = std::move(__rhv.__get_value())
    });
}

// Ariphmetic postfix and prefix inc/dec
pair_type_value 
Boolean::operator ++ (int) // value++
{
    if (this->__value == "false")
    {
        this->__value = "true";
        return pair_type_value ({"Number", "0"});
    }

    return pair_type_value ({"Number", "1"});
}

pair_type_value 
Boolean::operator -- (int) // value--
{
    if (this->__value == "false")
    {
        this->__value = "true";
        return pair_type_value ({"Number", "0"});
    }
    
    this->__value = "false";
    return pair_type_value ({"Number", "1"});
}

pair_type_value 
Boolean::operator ++ ()    // ++value
{
    if (this->__value == "false")
    {
        this->__value = "true";
        return pair_type_value ({"Number", "1"});
    }
    
    this->__value = "true";
    return pair_type_value ({"Number", "2"});
}

pair_type_value 
Boolean::operator -- ()    // --value
{
    if (this->__value == "false")
    {
        this->__value = "true";
        return pair_type_value ({"Number", "-1"});
    }
    
    this->__value = "false";
    return pair_type_value ({"Number", "0"});
}