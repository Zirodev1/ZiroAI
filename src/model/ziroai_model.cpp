#include "ziroai_model.h"

namespace ZiroAI {

    Model::Model() {}

    Model::~Model() {}

    void Model::AddLayer(std::unique_ptr<Layer> layer) {
        layers_.push_back(std::move(layer));
    }

    void Model::Compile() {
        for (size_t i = 1; i < layers_.size(); ++i) {
            layers_[i]->Connect(layers_[i - 1].get());
        }
    }

    void Model::Train(const std::vector<float>& input, const std::vector<float>& output, int epochs, float learning_rate) {
        for (int epoch = 0; epoch < epochs; ++epoch) {
            ForwardPass(input);
            BackwardPass(output, learning_rate);
        }
    }

    std::vector<float> Model::Predict(const std::vector<float>& input) {
        ForwardPass(input);
        return layers_.back()->GetOutput();
    }

    void Model::ForwardPass(const std::vector<float>& input) {
        layers_[0]->SetInput(input);
        for (auto& layer : layers_) {
            layer->Forward();
        }
    }

    void Model::BackwardPass(const std::vector<float>& output, float learning_rate) {
        layers_.back()->ComputeGradients(output);
        for (int i = static_cast<int>(layers_.size()) - 2; i >= 0; --i) {
            layers_[i]->Backward(layers_[i + 1].get(), learning_rate);
        }
    }

} // namespace ZiroAI
