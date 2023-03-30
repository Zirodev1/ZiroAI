#pragma once

#ifndef VOCABULARY_H
#define VOCABULARY_H

#include <string>
#include <unordered_map>
#include <vector>

class Vocabulary {
public:
	Vocabulary(bool lowercase = false);

	void add_word(const std::string& word);
	int word_to_index(const std::string& word) const;
	std::string index_to_word(int index) const;
	size_t size() const;

private:
	std::unordered_map<std::string, int> word_to_index_map;
	std::vector<std::string> index_to_word_map;
	bool lowercase;
};

#endif // VOCABULARY_H

