#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <functional>
#include "../__Types/Types.h"
#include "../__Cache/Cache.h"

class Parser {
    using string_iter = std::string::iterator;
    std::vector<std::string> __tokenized_expression;
public:
    Parser();
    ~Parser();
    void __parse(const std::string&);
    void __withe_space_deleter(std::string&);
    std::vector<std::string> __get_tokenized_expression();
private:
    std::vector<std::string> __tokenizer(const std::string&);
    std::string::iterator __string_scope_jumper (string_iter, char, char);
    void __number_literal_handler(string_iter, std::function<void(std::string)>);
    std::string __var_name_handler(string_iter);
    std::string __operator_handler(string_iter);
    std::string __string_handler(string_iter, const char);
};

#endif // PARSER_H