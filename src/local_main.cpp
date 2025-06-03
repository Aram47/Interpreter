#include <iostream>
#include "../include/local_main.hpp"
#include "../include/Input_Loader/Input_Loader.hpp"
#include "../include/Parser/Lexical_Analyzer/Lexical_Analyzer.hpp"

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
	const std::string pure_file_info = input_loader.get_file_info();
	// in this step will work lexer and parser classes
	LexicalAnalyzer lexer { pure_file_info };
	lexer.start_analysing();
	// const auto& tokens = lexer.get_tokens();

	// std::cout << "File processed successfully. File info: " << input_loader.get_file_info() << std::endl;
	std::cout << "File processed successfully" << std::endl;
	return 0;	
}