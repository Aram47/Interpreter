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

    std::string line;
    std::string res;

    while (getline(fs, line)) try {
        for (auto i = line.begin(); i != line.end(); ++i) {
            if ((i + 1 != line.end()) && (*i == '/' && *(i + 1) == '/'))
            {
                line.erase(i, line.end());
                break;
            }
        }
        res += line;
    } catch (std::exception e) {
        fs.close();
        return 0;
    }
    // std::cout << res << std::endl;
    fs.close();

    Executer __execute_code;

    try {
        __execute_code.__execute(res);
    } catch (std::exception e) {
        std::cerr << "Something is doesn't OK!" << std::endl;
        fs.close();
        return 0;
    }

    std::cout << "Ok" << std::endl;
    return 0;
}