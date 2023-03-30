#pragma once

#include <vector>
#include <memory>
#include "layers.h"

namespace ZiroAI {

    class Model {
    public:
        Model();
        ~Model();

        void AddLayer(std::unique_ptr<Layer> layer);
        void Compile();
        void Train(const std::vector<float>& input, const std::vector<float>& output, int epochs, float learning_rate);
        std::vector<float> Predict(const std::vector<float>& input);

    private:
        std::vector<std::unique_ptr<Layer>> layers_;

        void ForwardPass(const std::vector<float>& input);
        void BackwardPass(const std::vector<float>& output, float learning_rate);
    };

} // namespace ZiroAI
