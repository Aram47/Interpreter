#include "./local_main.h"

Local_Main::Local_Main(int __arg_cnt, char** __file_nm) noexcept
    : __arg_cnt { __arg_cnt }
    , __file_nms {__file_nm}
{

}

bool Local_Main::operator()() try {

    if (__arg_cnt == 1)
    {
        std::cerr << "Please get file/files for interpretation" << std::endl;
        throw 1; 
    }

    Execution_Engine __execute(__arg_cnt, __file_nms);

    if (__execute.__Code_runer())
        throw 1;

    return 0;

} catch (...) {
    return 1;
}