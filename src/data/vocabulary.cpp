#include "data/vocabulary.h"
#include <algorithm>
#include <cctype>

Vocabulary::Vocabulary(bool lowercase) : lowercase(lowercase) {}

void Vocabulary::add_word(const std::string& word) {
	std::string processed_word = word;

	if (lowercase) {
		std::transform(processed_word.begin(), processed_word.end(), processed_word.begin(),
			[](unsigned char c) {return std::tolower(c); });
	}

	if (word_to_index_map.find(processed_word) == word_to_index_map.end()) {
		word_to_index_map[processed_word] = index_to_word_map.size();
		index_to_word_map.push_back(processed_word);
	}
}

int Vocabulary::word_to_index(const std::string& word) const {
	std::string processed_word = word;

	if (lowercase) {
		std::transform(processed_word.begin(), processed_word.end(), processed_word.begin(),
			[](unsigned char c) {return std::tolower(c);  });
	}

	auto it = word_to_index_map.find(processed_word);
	return it != word_to_index_map.end() ? it->second : -1;
}

std::string Vocabulary::index_to_word(int index) const {
	return index >= 0 && index < static_cast<int>(index_to_word_map.size()) ? index_to_word_map[index] : "";
}

size_t Vocabulary::size() const {
	return index_to_word_map.size();
}