#include <iostream>
#include <vector>
#include <fstream>

#include "./header/Interpreter.h"

int main(int argc, char** argv) {
    if (argc != 2)
    {
        std::cerr << "Something is doesn't OK!" << std::endl;
        return 0;
    }

    std::ifstream fs (argv[1]);
    
    if (!fs.is_open())
    {
        std::cerr << "Something is doesn't OK!" << std::endl;
        return 0;
    }

    Parser prs;
    std::string line;

    while (!fs.eof()) try {
        getline(fs, line);
        prs.__parse(line);
    } catch (...) {
        std::cerr << "Something is doesn't OK!" << std::endl;
        prs.~Parser();
        return 0;
    }

    return 0;
}