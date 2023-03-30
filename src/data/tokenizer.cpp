// src/data/tokenizer.cpp

#include "data/tokenizer.h"
#include <algorithm>
#include <cctype>
#include <sstream>

Tokenizer::Tokenizer() {}

std::vector<std::string> Tokenizer::tokenize(const std::string& text) const {
    std::vector<std::string> tokens;
    std::string current_token;

    for (char c : text) {
        if (is_whitespace(c)) {
            if (!current_token.empty()) {
                tokens.push_back(current_token);
                current_token.clear();
            }
        }
        else {
            current_token.push_back(c);
        }
    }

    if (!current_token.empty()) {
        tokens.push_back(current_token);
    }

    return tokens;
}

std::vector<std::string> Tokenizer::tokenize_lowercase(const std::string& text) const {
    std::string lowercase_text = text;
    std::transform(lowercase_text.begin(), lowercase_text.end(), lowercase_text.begin(),
        [](unsigned char c) { return std::tolower(c); });

    std::istringstream iss(lowercase_text);
    std::vector<std::string> tokens;
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

bool Tokenizer::is_whitespace(char c) const {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}