#include "../../header/__Parser/Parser.h"

Parser::Parser()
{

}

Parser::~Parser()
{

}

void Parser::__parse(const std::string& line) 
{
    this->__tokenized_expression = __tokenizer(line);
    
    // for (auto it : __tokenized_expression)
    //     std::cout << it << std::endl;

    // this->__ast = new AST{__tokenized_expression};
    // std::pair<std::string, Base_Type*> __res = this->__ast->__get_result();
}

void Parser::__withe_space_deleter(std::string& line)
{
    auto it = line.begin();

    while (it != line.end())
    {
        bool flag = true;

        if ((*it == '\'') || (*it == '"')) 
        {
            if (*it == '\'')
                it = __string_scope_jumper(it + 1, '"', *it);
            else
                it = __string_scope_jumper(it + 1, '\'', *it);
        } 
        else if (*it == ' ')
        {
            if (*(it + 1) == ' ') {
                ++it;
                while (*it == ' ') 
                    line.erase(it, it + 1);
            
                flag = false;
            }
        }

        if (flag) ++it;
    }
}

std::vector<std::string> Parser::__get_tokenized_expression()
{
    return this->__tokenized_expression;
}

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
                 ((*it == '+') || 
                  (*it == '-') ||
                  (*it == '*') ||
                  (*it == '/') ||
                  (*it == '%') ||
                  (*it == '^') ||
                  (*it == '|') ||
                  (*it == '&') ||
                  (*it == '=') ||
                  (*it == '<') ||
                  (*it == '>') ||
                  (*it == '!') ||
                  (*it == '~') ||
                  (*it == ';') ||
                  (*it == ',') ||
                  (*it == '.') ||
                  (*it == '(') ||
                  (*it == ')') ||
                  (*it == '[') ||
                  (*it == ']') ||
                  (*it == '{') ||
                  (*it == '}'))
                ) 
        {

            __res = __operator_handler(it);
            __result.push_back(__res);
            it += __res.size() - 1;

        } 
        else if ( // string literals
                 (*it == '\'') ||
                 (*it == '"')
                )
        {

            __res = __string_handler(it, *it);
            __result.push_back(__res);
            it += __res.size() - 1;

        }

        __res.clear();
    }

    return __result;
}

std::string::iterator Parser::__string_scope_jumper (string_iter it, char symb, char current)
{
    if (*it == current)
        return it;

    if (*it == symb)
        it = __string_scope_jumper(it + 1, current, symb);

    return __string_scope_jumper(it + 1, symb, current);
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
    std::string __res;
    if      ( // assignments and boolean conditions
             ((*__beg == '+')   || 
             (*__beg == '-')    ||
             (*__beg == '*')    ||
             (*__beg == '/')    ||
             (*__beg == '%')    ||
             (*__beg == '^')    ||
             (*__beg == '|')    ||
             (*__beg == '&')    ||
             (*__beg == '=')    ||
             (*__beg == '<')    ||
             (*__beg == '>')    ||
             (*__beg == '!'))   &&
             (*(__beg + 1) == '=')
            ) 
    {
            __res += *__beg;
            __res += *(__beg + 1);
            return __res;
    }
    else if ( // shift assignment
             (((*__beg == '<') && (*(__beg + 1) == '<'))  ||
              ((*__beg == '>') && (*(__beg + 1) == '>'))) &&
             (((*(__beg + 2) == '=')))
            )
    {
            __res += *__beg;
            __res += *(__beg + 1);
            __res += *(__beg + 2);
            return __res;
    }
    else if ( // postfix/prefix minus/plus or left/right shift
             ((*__beg == '+')  ||
              (*__beg == '-')  ||
              (*__beg == '<')  ||
              (*__beg == '>')) &&
             (*(__beg) == *(__beg + 1))
            )
    {
            __res += *__beg;
            __res += *(__beg + 1);
            return __res;
    }
    else if ( // boolean || or &&
             ((*__beg == '&')  ||
              (*__beg == '|')) &&
             ((*__beg) == *(__beg + 1))
            )
    {
            __res += *__beg;
            __res += *(__beg + 1);
            return __res;
    }
    return {*__beg};
}

std::string Parser::__string_handler(string_iter __beg, const char symb)
{
    if (symb == '\'')
    {
        std::string __res(__beg, __string_scope_jumper(__beg + 1, '"', *__beg) + 1);
        return __res;
    }
    std::string __res(__beg, __string_scope_jumper(__beg + 1, '\'', *__beg) + 1);
    return __res;
}