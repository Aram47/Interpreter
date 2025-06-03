#include <iostream>
#include <vector>
#include <string>
#include "../../../include/Parser/Lexical_Analyzer/Lexical_Analyzer.hpp"

LexicalAnalyzer::LexicalAnalyzer(const std::string& pure_file) 
	: pure_file{pure_file} 
{}

void LexicalAnalyzer::start_analysing() {
	// Start the tokenization process
	this->tokenize();
}

const std::vector<std::string>& LexicalAnalyzer::get_tokens() const {
	return this->tokens; // Return the tokens vector
}

void LexicalAnalyzer::tokenize() {
	auto start = pure_file.begin();
	auto end = pure_file.end() - 1;

	while (start < end && *start == ' ') {
		++start; // Skip leading spaces
	}

	while (end > start && *end == ' ') {
		--end; // Skip trailing spaces
	}

	while (start <= end) {
		if (*start == ' ' || *start == '\n' || *start == '\t') {
			++start;
			continue;
		}
		auto it = start;
		while (it <= end && *it != ' ' && *it != '\n' && *it != '\t') {
			++it;
		}

		this->tokens.emplace_back(start, it); // Add the token to the vector
		start = it;
	}
}