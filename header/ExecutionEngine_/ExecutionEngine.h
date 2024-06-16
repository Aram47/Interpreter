#ifndef EXECUTION_ENGINE_H
#define EXECUTION_ENGINE_H

#include                "../FileHandler_/FileHandler.h"
#include            "../SyntaxChecker_/SyntaxChecker.h"
#include                  "../CodeCatter_/CodeCatter.h"
#include  "../AbstractSyntaxTree_/AbstractSyntaxTree.h"
#include              "../ControlBlock_/ControlBlock.h"

class Execution_Engine
{
private:
    using FH  =         File_Handler;
    using SC  =       Syntax_Checker;
    using CC  =          Code_Catter;
    using AST = Abstract_Syntax_Tree;
    using CB  =        Control_Block;
private:
    int __arg_count        =       0;
    char** __file_names    = nullptr;
    FH* __flh              = nullptr;
    SC* __sch              = nullptr;
    CC* __cc               = nullptr;
    AST* __ast             = nullptr;
    CB* __cb               = nullptr;
public:
    Execution_Engine()                                    = delete;
    Execution_Engine(const Execution_Engine&)             = delete;
    Execution_Engine(Execution_Engine&&)                  = delete;
    Execution_Engine& operator=(const Execution_Engine&&) = delete;
    Execution_Engine& operator=(Execution_Engine&&)       = delete;
    Execution_Engine(int,char**) noexcept;
    ~Execution_Engine() noexcept;
public:
    bool __Code_runer();
};

#endif // EXECUTION_ENGINE_H