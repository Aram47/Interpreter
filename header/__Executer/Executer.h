#ifndef EXECUTER_H
#define EXECUTER_H

#include "../__Parser/Parser.h"
#include "../__Types/__Base_Type/Base_Type.h"
#include "../__Types/__Number/Number.h"
#include "../__Cache/Cache.h"
#include "../__AST/AST.h"

class Executer
{
    Parser* __prs = nullptr;
    Cache* __cch  = nullptr;
    AST*   __ast  = nullptr;
public:
    Executer();
    ~Executer();
public:
    void __execute(std::string&);
private:
    std::pair<std::vector<std::string>::iterator, std::vector<std::string>> __instruction_cutter(std::vector<std::string>::iterator);
};

#endif // EXECUTER_H