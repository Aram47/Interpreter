#ifndef __INPUT_LOADER_HPP__
#define __INPUT_LOADER_HPP__

#include <string>
#include <fstream>
#include <utility>

class InputLoader {
public:
	InputLoader() = delete;
	InputLoader(const InputLoader&) = delete;
	InputLoader(InputLoader&&) = delete;
	InputLoader& operator=(const InputLoader&) = delete;
	InputLoader& operator=(InputLoader&&) = delete;
	InputLoader(const char* filePath);
	~InputLoader() = default;
public:
	std::pair<bool, std::string> start_file_processing();
	const std::string& get_file_info() const;
private:
	void start_file_checking() const;
	void is_valid_file_extension() const;
	void open_file();
	void read_from_file();
	const std::string single_comments_removal(const std::string&);
	void multi_comments_removal();
	void close_file();
private:
	std::string __file_name;
	std::string __file_extension;
	std::string __file_info;
	std::ifstream __file_stream;
};

#endif