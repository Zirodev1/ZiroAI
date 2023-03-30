#include "layers.h"
#include <cmath>
#include <random>

using namespace std;

Dense::Dense(int inputSize, int outputSize)
	: weights(outputSize, vector<double>(inputSize)), biases(outputSize) {
	// Initialize weights and biases with small random values
	default_random_engine generator;
	uniform_real_distribution<double> distribution(-0.1, 0.1);

	for (auto& row : weights) {
		for (auto& weight : row) {
			weight = distribution(generator);
		}
	}

	for (auto& bias : biases) {
		bias = distribution(generator);
	}
}

vector<double> Dense::forward(const vector<double>& input) {
	inputCache = input;
	vector<double> output(weights.size());

	for (size_t i = 0; i < weights.size(); ++i) {
		double sum = 0.0;
		for (size_t j = 0; j < input.size(); ++j) {
			sum += input[j] * weights[i][j];
		}
		output[i] = sum + biases[i];
	}

	return output;
}