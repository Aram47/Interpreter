#include "../../../../header/__Types/__Fundamental_Type/__Number/Number.h"


Number::Number(const std::string& __value) 
{
    set_type_name("Number");
    set_value(__value);
}

std::pair<std::string, std::string> Number::operator+ (Base_Type* __arg)
{
    // if (this->get_value() == "NaN")
    //     return std::make_pair<std::string, std::string> (
    //         "Number",
    //         "Nan"
    //     );

    std::string __tpnm = __arg->get_type_name();

    if (__tpnm == "Number") {
        if (dynamic_cast<Fundamental_Type*>(__arg)->get_value() == "NaN")
            return std::make_pair<std::string, std::string> (
                "Number",
                "NaN"
            );

        return std::make_pair<std::string, std::string> (
            "Number",
            std::to_string (
                std::stod(this->get_value()) +
                std::stod(dynamic_cast<Fundamental_Type*>(__arg)->get_value())
            )
        ); 
    } else if (__tpnm == "String") {
        return std::make_pair<std::string, std::string> (
            "String",
            this->get_value() + dynamic_cast<Fundamental_Type*>(__arg)->get_value()
        );
    } else if (__tpnm == "Boolean") {
        if (dynamic_cast<Fundamental_Type*>(__arg)->get_value() == "false")
            return std::make_pair<std::string, std::string> (
                "Number",
                this->get_value()
            );
        
        return std::make_pair<std::string, std::string> (
                "Number",
                std::to_string(
                    std::stod(this->get_value()) + 1
                )
        );
    }

    return std::make_pair<std::string, std::string> (
        "Number",
        "NaN"
    );
}

std::pair<std::string, std::string> Number::operator- (Base_Type* __arg)
{
    if (this->get_value() == "NaN")
        return std::make_pair<std::string, std::string> (
            "Number",
            "Nan"
        );

    std::string __tpnm = __arg->get_type_name();

    if (__tpnm == "Number") {
        if (dynamic_cast<Fundamental_Type*>(__arg)->get_value() == "NaN")
            return std::make_pair<std::string, std::string> (
                "Number",
                "NaN"
            );

        return std::make_pair<std::string, std::string> (
            "Number",
            std::to_string (
                std::stod(this->get_value()) -
                std::stod(dynamic_cast<Fundamental_Type*>(__arg)->get_value())
            )
        ); 
    }

    return std::make_pair<std::string, std::string> (
        "Number",
        "NaN"
    );
}