#pragma once
#include <vector>

using namespace std;

class Layer {
public:
	virtual vector<double> forward(const vector<double>& input) = 0;
	virtual vector<double> backward(const vector<double>& gradiant) = 0;
};

class Dense : public Layer {
public:
	Dense(int inputSize, int outputSize);
	vector<double> forward(const vector<double>& input) override;
	vector<double> backward(const vector<double>& gradient) override;

private:
	vector<vector<double>> weights;
	vector<double> biases;
	vector<double> inputCache;
};

class Activation : public Layer {
public:
	virtual vector<double> forward(const vector<double>& input) = 0;
	virtual vector<double> backward(const vector<double>& gradient) = 0;
};

class Sigmoid : public Activation {
public:
	vector<double> forward(const vector<double>& input) override;
	vector<double> backward(const vector<double>& gradiant) override;

private:
	vector<double> outputCache;
};

class Loss {
public:
	virtual double forward(const vector<double>& predicted, const vector<double>& target) = 0;
	virtual vector<double> backward() = 0;
};

class MeanSquaredError : public Loss {
public:
	double forward(const vector<double>& predicted, const vector<double>& target) override;
	vector<double> backward() override;

private:
	vector<double> predictedCache;
	vector<double> targetCache;
};
