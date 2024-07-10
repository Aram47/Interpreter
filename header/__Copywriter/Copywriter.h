#ifndef COPYWRITER_H
#define COPYWRITER_H

#include <vector>
#include <string>
#include <unordered_map>

class Copywriter
{
    using vec_str_iter = std::vector<std::string>::iterator;
private:
    std::unordered_map<std::string, std::string> __key_words = {
        {"extends", "extends"},
        {"return",   "return"},
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
    void __double_comments_deleter(std::string&);
    std::vector<std::string> __comma_adder(std::vector<std::string>&);
    std::vector<std::string> __function_hoisting_handler(std::vector<std::string>&);
    std::pair<std::vector<std::string>::iterator, std::vector<std::string>> __instruction_cutter(std::vector<std::string>::iterator,std::vector<std::string>::iterator);
    std::string __instruction_type_deducetor(std::vector<std::string>);
    bool __is_func(std::vector<std::string>);
    bool __is_name(const std::string&);

    std::vector<std::string>::iterator __loop_handler(vec_str_iter,vec_str_iter);
    std::vector<std::string>::iterator __func_handler(vec_str_iter,vec_str_iter);
    std::vector<std::string>::iterator __condition_handler(vec_str_iter,vec_str_iter);
    // std::vector<std::string>::iterator __class_handler(std::vector<std::string>::iterator);
};


#endif // COPYWRITER_H