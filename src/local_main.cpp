#include <iostream>
#include "../include/local_main.hpp"
#include "../include/Input_Loader/Input_Loader.hpp"

int local_main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;
		return 1; // will throw custom exception
	}

	InputLoader input_loader { argv[1] };
	auto [success, message] = input_loader.start_file_processing();
	if (!success) {
		std::cerr << "Error processing file: " << message << std::endl;
		return 1; // will throw custom exception
	}
	const std::string pure_file_info = input_loader.get_file_info(); // This will be used to log the file info
	// in this step will work lexer and parser classes
	std::cout << "File processed successfully. File info: " << input_loader.get_file_info() << std::endl;
	return 0;	
}