#include "../../header/__Copywriter/Copywriter.h"
#include <iostream>

void 
Copywriter::__double_comments_deleter(std::vector<std::string>& __code)
{
    for (auto __it = __code.begin(); __it != __code.end(); ++__it)
    {
        if (__it + 1 != __code.end()) {
            if (*__it == "/" && *(__it + 1) == "*") {
                auto __runer = __it;
                while (true)
                {
                    if ((*__runer == "*") && (*(__runer + 1) == "/"))
                        break;

                    ++__runer;
                }
                ++__runer;
                __it = __code.erase(__it, __runer + 1);
                --__it;
            }
        }
    }
}


std::vector<std::string> 
Copywriter::__comma_adder(std::vector<std::string>& __code)
{

    for (auto __it = __code.begin(); __it != __code.end(); ++__it)
    {
        if ((__key_words.find(*__it) != __key_words.end()) &&
            ((__key_words.find(*__it)->first == "while")   ||
             (__key_words.find(*__it)->first == "for")))
        {
            __it = __loop_handler(__it, __code.end());

            if ((__it + 1 == __code.end()) || 
                (*(__it + 1) != ";"))
            {
                __it = __code.insert(__it + 1, ";");
            }
        }
        else if ((__key_words.find(*__it) != __key_words.end()) &&
                 (__key_words.find(*__it)->first == "if"))
        {
            __it = __condition_handler(__it, __code.end());
            
            if ((__it + 1 == __code.end()) ||
                (*(__it + 1) != ";"))
            {
                __it = __code.insert(__it + 1, ";");
            }
        }
        else if ((__key_words.find(*__it) != __key_words.end()) &&
                 (__key_words.find(*__it)->first == "func"))
        {
            __it = __func_handler(__it, __code.end());
            
            if ((__it + 1 == __code.end()) ||
                (*(__it + 1) != ";"))
            {
                __it = __code.insert(__it + 1, ";");
            }
        } 
        else if ((__key_words.find(*__it) == __key_words.end()) && // function call
                 (__is_name(*__it)))
        {
            if ((__it + 1 != __code.end()) && (*(__it + 1) == "("))
            {
                __it = __brecket_handler(__it + 1);
                
                if ((__it + 1 == __code.end()) ||
                    (*(__it + 1) != ";"))
                {   
                    __it = __code.insert(__it + 1, ";");
                }
            }
        }
        // else if ((__key_words.find(*__it) != __key_words.end()) &&
        //          (__key_words.find(*__it)->first == "class"))
        // {

        // }
    }

    return __code;
}

std::vector<std::string>::iterator 
Copywriter::__loop_handler(vec_str_iter __beg, vec_str_iter __end)
{    
    if ((__beg + 1 == __end) || 
        ( *(__beg + 1) != "("))
    {
        throw std::exception();
    }

    ++__beg;
    __beg = __brecket_handler(__beg);

    if (__beg + 1 == __end || *(__beg + 1) != "{")
        return __beg;

    ++__beg;

    return __brecket_handler(__beg);
}

std::vector<std::string>::iterator 
Copywriter::__condition_handler(vec_str_iter __beg, vec_str_iter __end)
{

    if (((__beg + 1 == __end) && (*__beg == "}")) ||
        ((*(__beg + 1) != "else") && (*__beg == "}")))
    {
        return __beg;
    }

    if ((__beg + 1 == __end) ||
        ((*__beg == "if") && (*(__beg + 1) != "(")) ||
        ((*__beg == "else") && ((*(__beg + 1) != "{") && (*(__beg + 1) != "if"))))
    {
        throw std::exception();
    }

    if ((*__beg == "(") || (*__beg == "{"))
    {
        __beg = __brecket_handler(__beg);
    }

    if ((*__beg == "else") || 
        (*__beg == "if")   || 
        (*__beg == ")")    || 
        (*__beg == "}" && (__beg + 1 != __end && (*(__beg + 1) == "else" || (*(__beg + 1) == "}"))))) 
    {
        return __condition_handler(__beg + 1, __end);
    }

    return __condition_handler(__beg, __end);
}

std::vector<std::string>::iterator 
Copywriter::__func_handler(vec_str_iter __beg, vec_str_iter __end)
{
    if ((__beg + 1 == __end) || ((*(__beg + 1) != "(") && !(__is_name(*(__beg + 1)))))
        throw std::exception();

    if (__is_name(*(__beg + 1)))
        ++__beg;

    __beg = __brecket_handler(__beg + 1);

    if ((__beg + 1 == __end) || (*(__beg + 1) != "{"))
        throw std::exception();

    __beg = __brecket_handler(__beg + 1);

    if ((__beg + 1 != __end) && (*(__beg + 1) == "("))
        __beg = __brecket_handler(__beg + 1);

    return __beg;
}


// std::vector<std::string>::iterator 
// Copywriter::__class_handler(std::vector<std::string>::iterator)
// {

// }











































std::vector<std::string> 
Copywriter::__function_hoisting_handler(std::vector<std::string>& __code)
{
    std::vector<std::string> __functions_for_hoisting;
    for (auto __it = __code.begin(); __it != __code.end(); ++__it)
    {
        
    }
}

// i will back
std::pair<std::vector<std::string>::iterator, std::vector<std::string>> 
Copywriter::__instruction_cutter(std::vector<std::string>::iterator __beg, std::vector<std::string>::iterator __end)
{

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
    std::string __open_scp = *__beg;
    std::string __close_scope;

    if (*__beg == "(")
        __close_scope.push_back((*__beg)[0] + 1);
    else
        __close_scope.push_back((*__beg)[0] + 2);

    while (*__beg != __close_scope)
    {
        if (*__beg == __open_scp)
            ++__brecket_count;

        ++__beg;
    }

    while (__brecket_count)
    {
        if (*__beg == __close_scope)
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