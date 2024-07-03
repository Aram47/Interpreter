#ifndef PARSER_H
#define PARSER_H

#include <unordered_map>
#include <vector>
#include <string>
#include <functional>
#include "../__Types/__Base_Type/Base_Type.h"
#include "../__Types/__Number/Number.h"
#include "../__Cache/Cache.h"
#include "../__AST/AST.h"

class Parser {
    using string_iter = std::string::iterator;
    Cache* __cch  = nullptr;
    AST*   __ast  = nullptr;
    std::vector<std::string> __key_words = {
        "const",
        "for",
        "while",
        "do" 
        // ,
        // "func"
    };
public:
    Parser();
    ~Parser();
    void __parse(const std::string&);
    void __withe_space_deleter(std::string&);
private:
    std::vector<std::string> __tokenizer(const std::string&);
    void __number_literal_handler(string_iter, std::function<void(std::string)>);
    std::string __var_name_handler(string_iter);
    std::string __operator_handler(string_iter);
    std::string __string_handler(string_iter);
    std::string __scope_handler(string_iter);
    std::string __array_scope_resolution_handler(string_iter);
    std::string __object_scope_handler(string_iter);
};

#endif // PARSER_H