#include <iostream>
#include <functional>
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

    while (getline(fs, line)) try {
        prs.__withe_space_deleter(line);
        prs.__parse(line);
    } catch (std::exception e) {
        std::cerr << "Something is doesn't OK!" << std::endl;
        fs.close();
        return 0;
    }

    fs.close();
    std::cout << "Ok" << std::endl;
    return 0;
}