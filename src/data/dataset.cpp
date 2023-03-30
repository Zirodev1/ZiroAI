#include "data/dataset.h"

Dataset::Dataset(const std::string& text, bool lowercase) : vocabulary(lowercase), tokenizer(lowercase) {
	std::vector<std::string> tokens = tokenizer.tokenize(text);

	for (const auto& token : tokens) {
		vocabulary.add_word(token);
		data.push_back(vocabulary.word_to_index(token));
	}
}

const std::vector<int>& Dataset::get_data()	const {
	return data;
}