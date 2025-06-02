#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "../../include/Input_Loader/Input_Loader.hpp"

InputLoader::InputLoader(const char* filePath)
	: __file_name{ filePath }
	, __file_extension{ ".hyb" } 
{}

std::pair<bool, std::string> 
InputLoader::start_file_processing() {
	try {
		this->start_file_checking();
		this->open_file();
		this->read_from_file();
		this->multi_comments_removal();
		this->close_file();
		return std::pair<bool, std::string>(true, "File processing finished successfully.");
	} catch (const std::exception& e) {
		// e.what() will give to custom Loger class to log the error in file
		return std::pair<bool, std::string>(false, e.what());
	}
}

const std::string& InputLoader::get_file_info() const {
	return this->__file_info;
}

void InputLoader::start_file_checking() const {
	this->is_valid_file_extension();
}

void InputLoader::is_valid_file_extension() const {
	if (this->__file_name.size() <= this->__file_extension.size() &&
			this->__file_name.substr(this->__file_name.size() - this->__file_extension.size()) != this->__file_extension) {
		// throw custom exception and log the error
	}
}

void InputLoader::open_file() {
	this->__file_stream.open(this->__file_name);
	if (this->__file_stream.is_open() == false) {
		// throw custom exception and log the error
	}
}

void InputLoader::read_from_file() {
	std::string line;
	while (std::getline(this->__file_stream, line)) {
		if (line.empty()) {
			line.clear();
			continue; // skip empty lines
		}
		this->__file_info += this->single_comments_removal(line);
		line.clear();
	}
}

const std::string InputLoader::single_comments_removal(const std::string& line) {
	for (std::size_t i = 0; i < line.size() - 1; ++i) {
		if (line[i] == '/' && line[i + 1] == '/') {
			return line.substr(0, i) + "\n";
		}
	}
	return line + "\n";
}

void InputLoader::multi_comments_removal() {
	std::string temp_code = "";
	std::size_t file_size = this->__file_info.size();
	bool has_multi_comment = false;

	for (std::size_t i = 0; i < file_size - 1; ++i) {
		if (this->__file_info[i] == '/' && this->__file_info[i + 1] == '*') {
			has_multi_comment = true;
			i += 2;
			while (i < file_size - 1 && this->__file_info[i] != '*' && this->__file_info[i + 1] != '/') {
				++i;
			}
			++i;
			
			if (this->__file_info[i] != '/') {
				// throw custom exception and log the error
				// exception("Multi-line comment not closed properly.");
			}
		}else {
			temp_code += this->__file_info[i];
		}
	}

	if (has_multi_comment) {
		this->__file_info = std::move(temp_code);
	}
	
}

void InputLoader::close_file() {
	if (this->__file_stream.is_open() == false) {
		// throw custom exception and log the error
	}
	this->__file_stream.close();
}