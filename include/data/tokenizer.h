
#ifndef ZIROAI_TOKENIZER_H
#define ZIROAI_TOKENIZER_H

#include <string>
#include <vector>

class Tokenizer {
public:
	Tokenizer();
	std::vector<std::string> tokenize(const std::string& text) const;
	std::vector<std::string> tokenize_lowerCase(const std::string& text) const;

private:
	bool is_whitespace(char c) const;
};

#endif // ZIROAI_TOKENIZER_H
