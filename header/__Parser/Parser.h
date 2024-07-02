#ifndef PARSER_H
#define PARSER_H

#include <unordered_map>
#include <vector>
#include <string>
#include "../__Types/__Base_Type/Base_Type.h"
#include "../__Types/__Number/Number.h"
#include "../__Cache/Cache.h"
#include "../__AST/AST.h"

class Parser {
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
private:
    std::vector<std::string> __tokenizer(const std::string&);

};

#endif // PARSER_H