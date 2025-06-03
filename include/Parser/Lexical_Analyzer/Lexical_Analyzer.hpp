#ifndef __LEXICAL_ANALYZER_HPP__
#define __LEXICAL_ANALYZER_HPP__

#include <vector>
#include <string>

class LexicalAnalyzer {
public:
	LexicalAnalyzer() = delete;
	LexicalAnalyzer(const LexicalAnalyzer&) = delete;
	LexicalAnalyzer(LexicalAnalyzer&&) = delete;
	LexicalAnalyzer& operator=(const LexicalAnalyzer&) = delete;
	LexicalAnalyzer& operator=(LexicalAnalyzer&&) = delete;
	LexicalAnalyzer(const std::string&);
	~LexicalAnalyzer() = default;
public:
	void start_analysing(); // Method to start the lexical analysis
	const std::vector<std::string>& get_tokens() const; // Method to retrieve the tokens
private:
	void tokenize(); // Method to perform tokenization
private:
	std::vector<std::string> tokens; // Vector to store tokens
	std::string pure_file; // The pure file content to analyze
};

#endif // __LEXICAL_ANALYZER_HPP__