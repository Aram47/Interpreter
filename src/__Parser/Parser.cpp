#include "../header/__Parser/Parser.h"

Parser::Parser()
    : __cch{Cache::__get_cahce_instance()}
    , __ast{new AST{}}
{

}

Parser::~Parser()
{
    delete __ast;
    delete __cch;
}

void Parser::__parse(const std::string& line) 
{

    std::vector<std::string> __tokenised_expression = __tokenizer(line);
    
}

std::vector<std::string> Parser::__tokenizer(const std::string& expression) 
{

}