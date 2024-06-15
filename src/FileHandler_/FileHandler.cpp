#include "../../header/FileHandler_/FileHandler.h"

File_Handler::File_Handler(int __fl_cnt, char** __fls)
    : __files_count {__fl_cnt}
    , __files_name {__fls}
{

}

File_Handler::~File_Handler()
{
    this->__files_count = 0;
    this->__files_name = nullptr;
}

bool File_Handler::__files_checker()
{
    for (std::size_t i = 1; i < this->__files_count; ++i) {
        if (!(this->__extention_checker(__files_name[i])))
            return false;
    }
    return true;
}

bool File_Handler::__extention_checker(const char* const __fl)
{
    std::string __file_nm = __fl;
    std::string __extention = ".am";
    
    auto __ext_it = __extention.end() - 1;
    auto __fl_it = __file_nm.end() - 1;
    std::size_t i = __extention.size();

    while (i) 
    {
        if (*__ext_it != *__fl_it)
            return false;

        --(__ext_it);
        --(__fl_it);
        --i;
    }

    for (auto it = __file_nm.begin(); it != __fl_it; ++it) {
        if ((*it == '_') 
           || (*it >= 'A' && *it <= 'Z') 
           || (*it >= 'a' && *it <= 'z') 
           || (*it >= '0' && *it <= '9'))
        {
            continue;
        }
        return false;
    }

    return true;
}