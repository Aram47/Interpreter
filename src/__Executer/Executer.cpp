#include "../../header/__Executer/Executer.h"

Executer::Executer()
    : __prs{new Parser()}
    , __cch{Cache::__get_cahce_instance()}
    , __cpw{new Copywriter()}
    , __ist{new Intersection()}
{

}

Executer::~Executer()
{
    delete __prs;
    __cch->__delete_cache_instance();
    delete __cpw;
    delete __ist;

    __prs = nullptr;
    __cch = nullptr;
    __cpw = nullptr;
    __ist = nullptr;
}
#include <iostream>
void Executer::__execute(std::string& code) 
{
    using pair_vec_str_iter__vec_str = std::pair<std::vector<std::string>::iterator, std::vector<std::string>>;

    __prs->__withe_space_deleter(code);
    __prs->__parse(code);
    std::vector<std::string> __tokenized_expression = __prs->__get_tokenized_expression();
    __cpw->__double_comments_deleter(__tokenized_expression);
    __tokenized_expression = __cpw->__comma_adder(__tokenized_expression);
    __tokenized_expression = __cpw->__function_hoisting_handler(__tokenized_expression);

    for (auto it = __tokenized_expression.begin(); it != __tokenized_expression.end(); ++it)
    {
        pair_vec_str_iter__vec_str __instruction = __cpw->__instruction_cutter(it, __tokenized_expression.end());
        it = __instruction.first;
        // __ist->resolv(__instruction.second);
    }

}