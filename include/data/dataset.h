#pragma once

#ifndef DATASET_H
#define DATASET_H

#include "data/vocabulary.h"
#include "data/tokenizer.h"
#include <string>
#include <vector>

class Dataset {
public:
	Dataset(const std::string& text, bool lowercase = false);

	const std::vector<int>& get_data() const;

private:
	std::vector<int> data;
	Vocabulary vocabulary;
	Tokenizer tokenizer;
};

#endif // !DATASET_H

