#include "AudioFileSampler.h"

#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <cstdint>
#include <cstring>

namespace fs = std::filesystem;

void AudioFileSampler::load(const std::string& pathToFile)
{
    m_samples.clear(); // clear the old data samples

    if (!fs::exists(pathToFile))
        throw std::runtime_error("File does not exist: " + pathToFile);

    std::ifstream file(pathToFile, std::ios::binary);
    if (!file)
        throw std::runtime_error("Failed to open audio file");

    char riff[4];
    file.read(riff, 4);
    if (std::strncmp(riff, "RIFF", 4) != 0)
        throw std::runtime_error("Not RIFF");

    file.ignore(4);

    char wave[4];
    file.read(wave, 4);
    if (std::strncmp(wave, "WAVE", 4) != 0)
        throw std::runtime_error("Not WAVE");

    while (file)
    {
        char id[4];
        uint32_t size;

        file.read(id, 4);
        file.read(reinterpret_cast<char*>(&size), 4);

        if (std::strncmp(id, "data", 4) == 0)
        {
            std::vector<int16_t> temp(size / 2);
            file.read(reinterpret_cast<char*>(temp.data()), size);

            m_samples.reserve(temp.size());
            for (auto s : temp)
                m_samples.push_back(static_cast<float>(s) / 32768.0f);

            break;
        }
        else
        {
            file.ignore(size);
        }
    }

    if (m_samples.empty())
        throw std::runtime_error("No data chunk found");
}

std::size_t AudioFileSampler::numSamples() const noexcept {
    return m_samples.size();
}