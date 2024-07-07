#ifndef EXECUTER_H
#define EXECUTER_H

#include "../__Parser/Parser.h"
#include "../__Types/__Base_Type/Base_Type.h"
#include "../__Types/__Number/Number.h"
#include "../__Cache/Cache.h"
#include "../__Copywriter/Copywriter.h"
#include "../__AST/AST.h"


class Executer
{
    Parser*      __prs = nullptr;
    Cache*       __cch  = nullptr;
    Copywriter*  __cpw  = nullptr;
    AST*         __ast  = nullptr;
public:
    Executer();
    ~Executer();
public:
    void __execute(std::string&);
private:
};

#endif // EXECUTER_H