#include "../../header/__Executer/Executer.h"

Executer::Executer()
    : __cch{Cache::__get_cahce_instance()}
    , __prs{new Parser()}
    , __cpw{new Copywriter()}
    // , __ast{new AST()}
{

}

Executer::~Executer()
{
    delete __ast;
    delete __prs;
    __cch->__delete_cache_instance();
    __ast = nullptr;
    __prs = nullptr;
    __cch = nullptr;
}
#include <iostream>
void Executer::__execute(std::string& code) 
{
    __prs->__withe_space_deleter(code);
    __prs->__parse(code);
    std::vector<std::string> __tokenized_expression = __prs->__get_tokenized_expression();
    __tokenized_expression = __cpw->__function_hoisting_handler(__tokenized_expression);

    for (auto i : __tokenized_expression)
        std::cout << i << " ";

    std::cout << std::endl;
    // for (auto it = __tokenized_expression.begin(); it != __tokenized_expression.end(); ++it)
    // {
    //     std::pair<std::vector<std::string>::iterator, std::vector<std::string>> __instruction = __cpw->__instruction_cutter(it);
    //     it = __instruction.first;
        
    // }

}