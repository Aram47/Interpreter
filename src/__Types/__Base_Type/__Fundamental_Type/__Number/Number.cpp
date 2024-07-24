#include "../../../../../header/__Types/__Base_Type/__Fundamental_Type/__Number/Number.h"
#include <iostream>

using pair_type_value = std::pair<std::string, std::string>;

// Constructors
Number::Number (const pair_type_value& __inp_value)
{
    this -> __type  = __inp_value.first;
    this -> __value = __inp_value.second;
}

Number::Number (const Base_Type& __other)
{
    this -> __type  = __other.__get_type();
    this -> __value = __other.__get_value();
}

// Logic 
pair_type_value 
Number::operator && (const Base_Type& __rhv) const
{
    if (
        (this->__value == "NaN")     || 
        (0 == std::stod(this->__value))
       )
    {
        return pair_type_value ({"Boolean", "false"});
    }

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
Number::operator || (const Base_Type& __rhv) const
{
    if (
        (this->__value != "NaN") &&
        (std::stod(this->__value))
       )
    {
        return pair_type_value ({"Boolean", "true"});
    }

    std::string __rhv_type = __rhv.__get_type();

    if (
        (__rhv_type == "Undef") ||
        (__rhv_type == "Null" ) ||
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
Number::operator == (const Base_Type& __rhv) const
{

    if (
        (__rhv.__get_type() == "Boolean") &&
        (this->__value != "NaN")
       )
    {
        if (
            (
                (std::stod(this->__value) == 0) &&
                (__rhv.__get_value() == "false")
            ) ||
            (
                (std::stod(this->__value) == 1) &&
                (__rhv.__get_value() == "true")
            )
           )
        {
            return pair_type_value ({"Number", "true"});
        }
    }

    if (
        (this->__value == "NaN") ||
        (
            (__rhv.__get_type() == "Number") &&
            (__rhv.__get_value() == "NaN")
        ) ||
        (__rhv.__get_type() != "Number") 
       )
    {
        return pair_type_value ({"Boolean", "false"});
    }

    return this->__value == __rhv.__get_value() 
        ? pair_type_value ({"Boolean", "true"})
        : pair_type_value ({"Boolean", "false"});
}

pair_type_value 
Number::operator != (const Base_Type& __rhv) const
{
    if (
        (__rhv.__get_type() == "Boolean") &&
        (this->__value != "NaN")
       )
    {
        if (
            (
                (std::stod(this->__value) == 0) &&
                (__rhv.__get_value() == "false")
            ) ||
            (
                (std::stod(this->__value) == 1) &&
                (__rhv.__get_value() == "true")
            )
           )
        {
            return pair_type_value ({"Number", "false"});
        }
    }

    if (__rhv.__get_type() != "Number")
    {
        return pair_type_value ({"Boolean", "true"});
    }

    if (
        (__rhv.__get_value() == "NaN") ||
        (this->__value == "NaN")       ||
        (this->__value != __rhv.__get_value())
       )
    {
        return pair_type_value ({"Boolean", "true"});
    }

    return pair_type_value ({"Boolean", "false"});
}

pair_type_value 
Number::operator < (const Base_Type& __rhv) const
{
    if (
        (__rhv.__get_type() == "Boolean") &&
        (this->__value != "NaN")
       )
    {
        if (
            (
                (std::stod(this->__value) <= 0) && 
                (__rhv.__get_value() == "true")
            ) ||
            (
                (std::stod(this->__value) <= 0) &&
                (__rhv.__get_value() == "false")
            )
           )
        {
            return pair_type_value ({"Number", "true"});
        }
    }
    
    if (__rhv.__get_type() != "Number")
    {
        return pair_type_value ({"Boolean", "false"});
    }

    if (
        (__rhv.__get_value() == "NaN") ||
        (this->__value == "NaN")       ||
        (std::stod(this->__value) >= std::stod(__rhv.__get_value()))
       )
    {
        return pair_type_value ({"Boolean", "false"});
    }

    return pair_type_value ({"Boolean", "true"});
}

pair_type_value 
Number::operator > (const Base_Type& __rhv) const
{
    if (
        (__rhv.__get_type() == "Boolean") &&
        (this->__value != "NaN")
       )
    {
        if (
            (
                (std::stod(this->__value) > 0) && // > 0
                (__rhv.__get_value() == "false")
            ) ||
            (
                (std::stod(this->__value) > 1) && //  > 1
                (__rhv.__get_value() == "true")
            )
           )
        {
            return pair_type_value ({"Number", "true"});
        }
    }

    if (__rhv.__get_type() != "Number")
    {
        return pair_type_value ({"Boolean", "false"});
    }

    if (
        (__rhv.__get_value() == "NaN") ||
        (this->__value == "NaN")       ||
        (std::stod(this->__value) <= std::stod(__rhv.__get_value()))
       )
    {
        return pair_type_value ({"Boolean", "false"});
    }

    return pair_type_value ({"Boolean", "true"});
}

pair_type_value 
Number::operator <= (const Base_Type& __rhv) const
{
    if (
        (__rhv.__get_type() == "Boolean") &&
        (this->__value != "NaN")
       )
    {
        if (
            (
                (std::stod(this->__value) <= 0) &&
                (__rhv.__get_value() == "false")
            ) ||
            (
                (std::stod(this->__value) <= 1) &&
                (__rhv.__get_value() == "true")
            )
           )
        {
            return pair_type_value ({"Number", "true"});
        }
    }

    if (__rhv.__get_type() != "Number")
    {
        return pair_type_value ({"Boolean", "false"});
    }

    if (
        (__rhv.__get_value() == "NaN") ||
        (this->__value == "NaN")       ||
        (std::stod(this->__value) > std::stod(__rhv.__get_value()))
       )
    {
        return pair_type_value ({"Boolean", "false"});
    }

    return pair_type_value ({"Boolean", "true"});
}

pair_type_value 
Number::operator >= (const Base_Type& __rhv) const
{
    if (
        (__rhv.__get_type() == "Boolean") &&
        (this->__value != "NaN")
       )
    {
        if (
            (
                (std::stod(this->__value) >= 0) &&
                (__rhv.__get_value() == "false")
            ) ||
            (
                (std::stod(this->__value) >= 1) &&
                (__rhv.__get_value() == "true")
            )
           )
        {
            return pair_type_value ({"Number", "true"});
        }
    }

    if (__rhv.__get_type() != "Number")
    {
        return pair_type_value ({"Boolean", "false"});
    }

    if (
        (__rhv.__get_value() == "NaN") ||
        (this->__value == "NaN")       ||
        (std::stod(this->__value) < std::stod(__rhv.__get_value()))
       )
    {
        return pair_type_value ({"Boolean", "false"});
    }

    return pair_type_value ({"Boolean", "true"});
}

// Ariphmetic
pair_type_value 
Number::operator + (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();

    if (
        (__rhv_type == "Undef")    ||
        (__rhv_type == "Null" )    ||
        (__rhv_type == "Object")   ||
        (__rhv_type == "Function") ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    if (
        (this->__value == "NaN") &&
        (__rhv_type != "String")
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    if (__rhv_type == "String")
    {
        return pair_type_value ({"String", this->__value + __rhv.__get_value()});
    }

    if (__rhv_type == "Boolean")
    {
        return __rhv.__get_value() == "true"
            ? pair_type_value ({"Number", std::to_string(std::stod(this->__value) + 1)})
            : pair_type_value ({"Number", this->__value});
    }

    // if (__rhv_type == "Array")
    // {

    // }

    return pair_type_value ({
      "Number",
      std::to_string(std::stod(this->__value) + std::stod(__rhv.__get_value()))  
    });
}

pair_type_value 
Number::operator - (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();

    if (
        (this->__value != "NaN") &&
        (__rhv_type == "Boolean")
       )
    {
        return __rhv.__get_value() == "false"
            ? pair_type_value ({"Number", this->__value})
            : pair_type_value ({"Number", std::to_string(std::stod(this->__value) - 1)});
    }

    if (
        (__rhv_type != "Number")    ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    if (this->__value == "NaN")
    {
        return pair_type_value ({"Number", "NaN"});
    }

    return pair_type_value ({
      "Number",
      std::to_string(std::stod(this->__value) - std::stod(__rhv.__get_value()))  
    });
}

pair_type_value 
Number::operator * (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();

    if (
        (__rhv_type != "Number")    ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    if (this->__value == "NaN")
    {
        return pair_type_value ({"Number", "NaN"});
    }

    return pair_type_value ({
      "Number",
      std::to_string(std::stod(this->__value) * std::stod(__rhv.__get_value()))  
    });
}

pair_type_value 
Number::operator / (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();

    if (
        (__rhv_type != "Number")    ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    if (this->__value == "NaN")
    {
        return pair_type_value ({"Number", "NaN"});
    }

    return pair_type_value ({
      "Number",
      std::to_string(std::stod(this->__value) / std::stod(__rhv.__get_value()))  
    });
}

pair_type_value 
Number::operator % (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();

    if (
        (__rhv_type != "Number")    ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    if (this->__value == "NaN")
    {
        return pair_type_value ({"Number", "NaN"});
    }

    long long int __this_value = std::stod(this->__value);
    long long int __rhv_value = std::stod(__rhv.__get_value());

    return pair_type_value ({
      "Number",
      std::to_string(__this_value % __rhv_value)  
    });
}

pair_type_value 
Number::operator << (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();

    if (
        (__rhv_type != "Number")    ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    if (this->__value == "NaN")
    {
        return pair_type_value ({"Number", "NaN"});
    }

    long long int __this_value = std::stod(this->__value);
    long long int __rhv_value = std::stod(__rhv.__get_value());

    return pair_type_value ({
      "Number",
      std::to_string(__this_value << __rhv_value)  
    });
}

pair_type_value 
Number::operator >> (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();

    if (
        (__rhv_type != "Number")    ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    if (this->__value == "NaN")
    {
        return pair_type_value ({"Number", "NaN"});
    }

    long long int __this_value = std::stod(this->__value);
    long long int __rhv_value = std::stod(__rhv.__get_value());

    return pair_type_value ({
      "Number",
      std::to_string(__this_value >> __rhv_value)  
    });
}

pair_type_value 
Number::operator | (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();

    if (
        (__rhv_type != "Number")    ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    if (this->__value == "NaN")
    {
        return pair_type_value ({"Number", "NaN"});
    }

    long long int __this_value = std::stod(this->__value);
    long long int __rhv_value = std::stod(__rhv.__get_value());

    return pair_type_value ({
      "Number",
      std::to_string(__this_value | __rhv_value)  
    });
}

pair_type_value 
Number::operator & (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();

    if (
        (__rhv_type != "Number")    ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    if (this->__value == "NaN")
    {
        return pair_type_value ({"Number", "NaN"});
    }

    long long int __this_value = std::stod(this->__value);
    long long int __rhv_value = std::stod(__rhv.__get_value());

    return pair_type_value ({
      "Number",
      std::to_string(__this_value & __rhv_value)  
    });
}

pair_type_value 
Number::operator ^ (const Base_Type& __rhv) const
{
    std::string __rhv_type = __rhv.__get_type();

    if (
        (__rhv_type != "Number")    ||
        (
            (__rhv_type == "Number") &&
            (__rhv.__get_value() == "NaN")
        )
       )
    {
        return pair_type_value ({"Number", "NaN"});
    }

    if (this->__value == "NaN")
    {
        return pair_type_value ({"Number", "NaN"});
    }

    long long int __this_value = std::stod(this->__value);
    long long int __rhv_value = std::stod(__rhv.__get_value());

    return pair_type_value ({
      "Number",
      std::to_string(__this_value ^ __rhv_value)
    });
}

// Assignments
pair_type_value
Number::operator = (const Base_Type& __rhv)
{
    return pair_type_value ({
        "Number",
        this->__value = std::move(__rhv.__get_value())
    });
}

// Ariphmetic postfix and prefix inc/dec
pair_type_value 
Number::operator ++ (int) // value++
{
    return this->__value == "NaN" 
        ? pair_type_value ({"Number", "NaN"})
        : pair_type_value ({
            "Number",
            std::to_string(std::stod((this->__value = std::to_string(std::stod(this->__value) + 1))) - 1)
        });
}

pair_type_value 
Number::operator -- (int) // value--
{
    return this->__value == "NaN" 
        ? pair_type_value ({"Number", "NaN"})
        : pair_type_value ({
            "Number",
            std::to_string(std::stod((this->__value = std::to_string(std::stod(this->__value) - 1))) + 1)
        });
}

pair_type_value 
Number::operator ++ ()   // ++value
{
    return this->__value == "NaN" 
        ? pair_type_value ({"Number", "NaN"}) 
        : pair_type_value ({
            "Number",
            this->__value = std::to_string(std::stod(this->__value) + 1)
        });
}

pair_type_value 
Number::operator -- ()  // --value
{
    return this->__value == "NaN" 
        ? pair_type_value ({"Number", "NaN"}) 
        : pair_type_value ({
            "Number",
            this->__value = std::to_string(std::stod(this->__value) - 1)
        });
}