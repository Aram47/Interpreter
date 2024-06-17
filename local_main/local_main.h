#ifndef LOCAL_MAIN_H
#define LOCAL_MAIN_H

#include "../header/ExecutionEngine_/ExecutionEngine.h"

class Local_Main
{
    int __arg_cnt = 0;
    char** __file_nms = nullptr;
public:
    Local_Main(int, char**) noexcept;
    bool operator()();
};

#endif // LOCAL_MAIN_H