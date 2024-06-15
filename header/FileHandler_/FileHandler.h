#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <iostream>
#include <string>

class File_Handler
{
    int __files_count = 0;
    char** __files_name = nullptr;
public:
    File_Handler() = delete;
    File_Handler(const File_Handler&) = delete;
    File_Handler(File_Handler&&) = delete;
    File_Handler& operator=(const File_Handler&) = delete;
    File_Handler& operator=(File_Handler&&) = delete;
    File_Handler(int, char**);
    ~File_Handler();
    bool __files_checker();
private:
    bool __extention_checker(const char* const);
};

#endif // FILE_HANDLER_H