#include "../../header/__AST/AST.h"

AST::AST(const std::vector<std::string>& __inp_expression) 
    : __cch{Cache::__get_cahce_instance()} 
{
    this->__expression = __inp_expression;
}

AST::~AST()
{
    // logic
}

// void AST::__tree_generator(std::vector<std::string> __expression)
// {

// }

// std::pair<std::string, Base_Type*> AST::__get_result()
// {

// }