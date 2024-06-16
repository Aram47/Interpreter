#include "../header/ExecutionEngine_/ExecutionEngine.h"

Execution_Engine::Execution_Engine(int __arg_cnt, char** __file_nms) noexcept
    : __arg_count  {                __arg_cnt                             }
    , __file_names {               __file_nms                             }
    , __flh        { new         File_Handler {__arg_count, __file_names} }
    , __sch        { new       Syntax_Checker {}                          }
    , __cc         { new          Code_Catter {}                          }
    , __ast        { new Abstract_Syntax_Tree {}                          }
    , __cb         { new        Control_Block {}                          }
{

}

Execution_Engine::~Execution_Engine() noexcept
{
    delete this->          __flh;
    delete this->          __sch;
    delete this->           __cc;
    delete this->          __ast;
    delete this->           __cb;

    this->__arg_count  =       0;
    this->__file_names = nullptr;
    this->__flh        = nullptr;
    this->__sch        = nullptr;
    this->__cc         = nullptr;
    this->__ast        = nullptr;
    this->__cb         = nullptr;
}

bool Execution_Engine::__Code_runer()
{

}