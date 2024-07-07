#ifndef COPYWRITER_H
#define COPYWRITER_H

#include <vector>
#include <string>
#include <unordered_map>

class Copywriter
{
private:
    std::unordered_map<std::string, std::string> __key_words = {
        {"extends", "extends"},
        {"class",     "class"},
        {"const",     "const"},
        {"while",     "while"},
        {"func",       "func"},
        {"else",       "else"},
        {"for",         "for"},
        {"if",           "if"}
    };
private:
    std::vector<std::string>::iterator __brecket_handler(std::vector<std::string>::iterator);
public:
    std::vector<std::string> __function_hoisting_handler(std::vector<std::string>&);
    std::pair<std::vector<std::string>::iterator, std::vector<std::string>> __instruction_cutter(std::vector<std::string>::iterator);
    std::string __instruction_type_deducetor(std::vector<std::string>);
    bool __is_func(std::vector<std::string>);
    bool __is_name(const std::string&);
};


#endif // COPYWRITER_H