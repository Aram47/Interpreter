#ifndef AST_H
#define AST_H

#include <vector>
#include <string>
#include "../__Types/__Base_Type/Base_Type.h"
#include "../__Types/__Fundamental_Type/Fundamental_Type.h"
#include "../__Types/__Fundamental_Type/__Number/Number.h"
#include "../__Cache/Cache.h"

class AST
{
private:
    struct Tree_Node
    {
        std::string __value;
        bool is_const;
        bool __is_operator;
    };
    std::vector<std::string> __expression;
    Cache* __cch  = nullptr;
    Tree_Node* __root = nullptr;
public:
    AST() = delete;
    AST(const AST&) = delete;
    AST(AST&&) = delete;
    AST(const std::vector<std::string>&);
    ~AST();
    // void __tree_generator(std::vector<std::string>);
    // std::pair<std::string, Base_Type*> __get_result();
};

#endif // AST_H