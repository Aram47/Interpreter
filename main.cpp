/*
    class File_Handler for extentions +
    class (functional object) Execution_Engine for execution programm +
    class Syntax_Checker for validation syntax +
    class Code_Catter for cat code line or block +
    class Code_Block and his derived classes Line and Block +
    class Key_Words and his derived classes Const and Conditionals +
    class Control_Block for controlling variables, objects, literals values +
    class Cache for caching variables and controle they +
    class Garbage_Collector for clearing unusable memory +
    class Abstract_Syntax_Tree for generation A_S_T for current expression +
    class General_Types and his derived classes -
    {
        class User_Defined_Type and his derived class Class
        class Fundamental_Types and his derived classes
        {
            class String for storing characters/symbols
            class Boolean for storing boolean expression true/false
            class Null for storing empty values
            class Number and his derived classes 
            {
                class Integer for storing decimal values
                class Floating_Point for storing floating values float/double
            }
            class Object and his derived classes
            {
                class Array for storing more elements in array
                class Function for function calling
            }
        }
    } // for working with values

    class Operations for defining operations with types
*/
#include <iostream>

int main(int argc, char** argv) 
{
    if (argc == 1)
    {
        std::cerr << "Please get file/files for interpretation" << std::endl;
        return 0; 
    }

    return 0;
}