#ifndef EXECUTER_H
#define EXECUTER_H

#include "../__Parser/Parser.h"
#include "../__Cache/Cache.h"
#include "../__Copywriter/Copywriter.h"
#include "../__Intersection/Intersection.h"

class Executer
{
    Parser*        __prs  = nullptr;
    Cache*         __cch  = nullptr;
    Copywriter*    __cpw  = nullptr;
    Intersection*  __ist  = nullptr;
public:
    Executer();
    ~Executer();
public:
    void __execute(std::string&);
};

#endif // EXECUTER_H