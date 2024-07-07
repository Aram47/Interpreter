#include "../../header/__Copywriter/Copywriter.h"
#include <iostream>

std::vector<std::string> 
Copywriter::__function_hoisting_handler(std::vector<std::string>& __code)
{
    std::vector<std::string> __functions_for_hoisting;

    for (auto it = __code.begin(); it != __code.end(); ++it)
    {
        std::pair<std::vector<std::string>::iterator, std::vector<std::string>> 
        __instruction = __instruction_cutter(it, __code.end());

        if (__instruction_type_deducetor(__instruction.second) == "Function") {
            
            for (auto __fit = __instruction.second.begin(); __fit != __instruction.second.end(); ++__fit)
                __functions_for_hoisting.push_back(*__fit);

            it = __code.erase(it, __instruction.first + 1);
            --it;
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

// i will back
std::pair<std::vector<std::string>::iterator, std::vector<std::string>> 
Copywriter::__instruction_cutter(std::vector<std::string>::iterator __beg, std::vector<std::string>::iterator __end)
{
    auto __it = __beg;
    std::vector<std::string> __result;

    while (*__it != ";")
    {
        if (*__it == "{")
        {
            auto __current = __it;
            __it = __brecket_handler(__it);
            // *__it == "}" -> 100%
            
            if (__it + 1 == __end) {
                std::vector<std::string> temp(__current, __it);
                temp.push_back("}");
                for (auto i : temp)
                    __result.push_back(i);
                
                return std::pair<std::vector<std::string>::iterator, std::vector<std::string>> (__it, __result);

            } else if ((__it + 1 != __end) && (*(__it + 1) == ";")) {
                ++__it;
                std::vector<std::string> temp(__current, __it);
                temp.push_back(";");

                for (auto i : temp)
                    __result.push_back(i);
                
                return std::pair<std::vector<std::string>::iterator, std::vector<std::string>> (__it, __result);
            } 
            // else if ((__it + 1 != __end) && (*(__it + 1) != ",")) {
            //     // -------------
            // } else {
                std::vector<std::string> temp(__current, __it);

                for (auto i : temp)
                    __result.push_back(i);
            // }

        }

        __result.push_back(*__it);
        ++__it;
    }

    __result.push_back(*__it);

    return std::pair<std::vector<std::string>::iterator, std::vector<std::string>> (__it, __result);
}

std::string 
Copywriter::__instruction_type_deducetor(std::vector<std::string> __instruction)
{
    if (__is_func(__instruction))
        return "Function";

    return "";
}

std::vector<std::string>::iterator 
Copywriter::__brecket_handler(std::vector<std::string>::iterator __beg)
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
            --__brecket_count;

        if (__brecket_count == 0)
            break;

        ++__beg;
    }

    return __beg;
}

bool 
Copywriter::__is_func(std::vector<std::string> __instruction)
{   
    auto __beg = __instruction.begin();

    if ((__key_words.find(*__beg) != __key_words.end()) && 
        (__key_words.find(*__beg)->second == "func"))
    {
        ++__beg;
        if (__is_name(*__beg))
        {
            ++__beg;
            if (*__beg == "(") {
                int __arguments_scope_count = 0;
                while (*__beg != ")")
                {
                    if (*__beg == "(")
                        ++__arguments_scope_count;

                    ++__beg;
                }

                while (__arguments_scope_count)
                {
                    if (*__beg == ")")
                        --__arguments_scope_count;

                    ++__beg;
                }

                if (*__beg == "{")
                {
                    __beg = __brecket_handler(__beg);

                    return true;
                }
            }
        }
    }

    return false;
}

bool 
Copywriter::__is_name(const std::string& __name)
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