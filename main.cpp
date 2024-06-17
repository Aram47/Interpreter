#include <iostream>
#include "./local_main/local_main.h"

int main(int argc, char** argv) {

    Local_Main __main(argc, argv);

    if (__main())
        std::cerr << "Programm crashed..." << std::endl;

    return 0;
}