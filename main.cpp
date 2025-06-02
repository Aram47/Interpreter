#include <iostream>
#include <exception>
#include "./include/local_main.hpp"
#include "./include/Data_Types/Value/Value.hpp"

int main(int argc, char** argv) {
	try {
		local_main(argc, argv);
		std::cout << "Program executed successfully." << std::endl;
	} catch (const std::exception& err) {
		std::cerr << "An error occurred: " << err.what() << std::endl;
		return EXIT_FAILURE;
	} catch (...) {
		std::cerr << "An unknown error occurred." << std::endl;
		return EXIT_FAILURE;
	}
}