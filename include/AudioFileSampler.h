// AudioFileSampler parses a .wav audio file 
// and stores the samples as accessible data
#pragma once

#include <vector>
#include <string>

class AudioFileSampler {
    public:
        void load(const std::string& pathToFile);
        std::size_t numSamples() const noexcept;

    private:
        std::vector<float> m_samples;


};