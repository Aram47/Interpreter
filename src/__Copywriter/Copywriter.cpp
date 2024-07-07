#include "../../header/__Copywriter/Copywriter.h"

std::vector<std::string> Copywriter::__function_hoisting_handler(std::vector<std::string>& __code)
{
    std::vector<std::string> __functions_for_hoisting;

    for (auto it = __code.begin(); it != __code.end(); ++it)
    {
        std::pair<std::vector<std::string>::iterator, std::vector<std::string>> __instruction = __instruction_cutter(it);

        if (__instruction_type_deducetor(__instruction.second) == "Function") {
            std::vector<std::string> temp(it, __instruction.first + 1);
            
            for (auto __fit = temp.begin(); __fit != temp.end(); ++__fit)
                __functions_for_hoisting.push_back(*__fit);

            it = __code.erase(it, __instruction.first + 1);
        } else {
            it = __instruction.first;
        }
    }

    if (!__functions_for_hoisting.empty()) {
        for (auto __cit = __code.begin(); __cit != __code.end(); ++__cit)
            __functions_for_hoisting.push_back(*__cit);
        
        return __functions_for_hoisting;
    }

    return __code;
}

std::pair<std::vector<std::string>::iterator, std::vector<std::string>> 
Copywriter::__instruction_cutter(std::vector<std::string>::iterator __beg)
{
    auto __it = __beg;
    std::vector<std::string> __result;

    while (*__it != ";")
    {
        if (*__it == "{")
        {
            auto __current = __it;
            __it = __brecket_handler(__it);
            
            std::vector<std::string> temp(__current, __it);

            for (auto i = temp.begin(); i != temp.end(); ++i)
                __result.push_back(*i);

            if (*(__it + 1) != "," && *(__it + 1) != ";")
            {
                __result.push_back(*__it);
                return std::pair<std::vector<std::string>::iterator, std::vector<std::string>> (__it, __result);
            }
        }

        __result.push_back(*__it);
        ++__it;
    }

    __result.push_back(*__it);
    return std::pair<std::vector<std::string>::iterator, std::vector<std::string>> (__it, __result);
}

std::string Copywriter::__instruction_type_deducetor(std::vector<std::string> __instruction)
{
    if (__is_func(__instruction))
        return "Function";

    return "";
}

std::vector<std::string>::iterator Copywriter::__brecket_handler(std::vector<std::string>::iterator __beg)
{
    int __brecket_count = 0;

    while (*__beg != "}")
    {
        if (*__beg == "{")
            ++__brecket_count;

        ++__beg;
    }

    while (__brecket_count)
    {
        if (*__beg == "}")
            __brecket_count;

        ++__beg;
    }

    return __beg;
}

bool Copywriter::__is_func(std::vector<std::string> __instruction)
{
    if (*(__instruction.end() - 1) == ";")
        return false;
    
    auto __beg = __instruction.begin();

    if ((__key_words.find(*__beg) != __key_words.end()) && 
        (__key_words.find(*__beg)->second == "func"))
    {
        ++__beg;
        if ((*__beg == "(" ) || __is_name(*__beg))
        {
            if (*__beg == "(")
            {

            }
        }
    }

    return false;
}

bool Copywriter::__is_name(const std::string& __name)
{
    if (
        (*__name.begin() >= 'A' && *__name.begin() <= 'Z') ||
        (*__name.begin() >= 'a' && *__name.begin() <= 'z') ||
        (*__name.begin() == '_') || (*__name.begin() <= '$')
       ) 
    {
        for (auto i : __name)
        {
            if (!
                ((i >= 'A' && i <= 'Z') ||
                (i >= 'a' && i <= 'z') ||
                (i >= '0' && i <= '9') ||
                (i == '_') || (i == '&'))
               )
            {
                return false;
            }
        }
        return true;
    }

    return false;
}