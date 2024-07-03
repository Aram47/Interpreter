#include "../../header/__Parser/Parser.h"

Parser::Parser()
    : __cch{Cache::__get_cahce_instance()}
{

}

Parser::~Parser()
{
    delete __ast;
    __cch->__delete_cache_instance();
    __ast = nullptr;
    __cch = nullptr;
}

void Parser::__parse(const std::string& line) 
{
    std::vector<std::string> __tokenized_expression = __tokenizer(line);
    this->__ast = new AST{__tokenized_expression};
    std::pair<std::string, Base_Type*> __res = this->__ast->__get_result();
}

void Parser::__withe_space_deleter(std::string& line)
{
    std::size_t i = 0;
    std::size_t j = line.size() - 1;

    while (line[j] == ' ')
        line.erase(j--, 1);

    while (line[i] == ' ')
        line.erase(i, 1);
}


// #include <iostream>

std::vector<std::string> Parser::__tokenizer(const std::string& expression) 
{
    std::string changebl_expression = expression;
    std::string __res;
    std::vector<std::string> __result;

    for (auto it = changebl_expression.begin(); it != changebl_expression.end(); ++it)
    {
        /*
            variable name,
            array name,
            function name,
            conditional(for/while/if/else/else if),
            boolean(true/false),
            NaN,
            Undef,
        */
        if (
            (*it >= 'A' && *it <= 'Z') || 
            (*it >= 'a' && *it <= 'z') || 
            (*it == '_') || (*it == '$')
           )
        {

            __res = __var_name_handler(it);
            __result.push_back(__res);
            it += __res.size() - 1;

        } 
        else if ( // number literals
                 (*it >= '0') &&
                 (*it <= '9')
                ) 
        {
            __number_literal_handler(it, [&__res] (std::string __ln) { __res = __ln; });
            if (__res.empty()) { throw std::exception();}
            else{ __result.push_back(__res); it += __res.size() - 1;}

        } 
        else if ( // operators
                 (*it == '+') ||
                 (*it == '-') || 
                 (*it == '*') || 
                 (*it == '/') ||
                 (*it == '%') ||
                 (*it == '=')
                ) 
        {

            __res = __operator_handler(it);
            __result.push_back(__res);
            it += __res.size() - 1;

        } 
        else if ( // string literals
                 (*it == '\'') ||
                 (*it == '"')  || 
                 (*it == '`')
                )
        {

            __res = __string_handler(it);
            __result.push_back(__res);
            it += __res.size() - 1;

        }
        else if ( // scope
                 (*it == '(')
                )
        {

            __res = __scope_handler(it);
            __result.push_back(__res);
            it += __res.size() - 1;

        } 
        else if (  // array (scope resolution)
                 (*it == '[')
                )
        {

            __res = __array_scope_resolution_handler(it);
            __result.push_back(__res);
            it += __res.size() - 1;

        } 
        else if ( // object
                 (*it == '{')
                )
        {

            __res = __object_scope_handler(it);
            __result.push_back(__res);
            it += __res.size() - 1;

        } 
        else if ( // comma
                 (*it == ';') ||
                 (*it == ',')
                )
        {

            __res = *it;
            __result.push_back(__res);

        }

        __res.clear();
    }
    // std::cout << changebl_expression << std::endl;
    // for (auto it : result)
    //     std::cout << it << std::endl;

    return __result;
}

void Parser::__number_literal_handler(string_iter __beg, std::function<void (std::string)> __lmbd)
{
    std::string ln;
    int __doth_count = 0;
    bool flag = false;

    while (
            (*__beg >= '0') && 
            (*__beg <= '9') || 
            (*__beg == '.')
          ) 
    {
        if (*__beg == '.') {
            ++__doth_count;
            if (__doth_count > 1)
                flag = true;
        }
        if (flag)
            break;

        ln.push_back(*__beg);
        ++__beg;
    }

    if (!flag)
        __lmbd(ln);
}

std::string Parser::__var_name_handler(string_iter __beg)
{
    std::string __res;
    while (
            (*__beg >= 'A' && *__beg <= 'Z')   ||
            (*__beg >= 'a' && *__beg <= 'z')   ||
            (*__beg >= '0' && *__beg <= '9')   ||
            (*__beg == '_') || (*__beg == '$')
          )
    {
        __res.push_back(*__beg);
        ++__beg;
    }

    return __res;
}

std::string Parser::__operator_handler(string_iter __beg)
{
    // if (
    //     (*__beg == '+') || 
    //     (*__beg == '-')
    //    ) 
    // {

    // }
    return {*__beg};
}

// std::string Parser::__string_handler(string_iter __beg)
// {

// }

// std::string Parser::__scope_handler(string_iter __beg)
// {

// }

// std::string Parser::__array_scope_resolution_handler(string_iter __beg)
// {

// }

// std::string Parser::__object_scope_handler(string_iter __beg)
// {

// }
