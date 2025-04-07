//------------------------------------------------------------------------
// Copyright(c) 2025 MaxDev0101.
//------------------------------------------------------------------------

#pragma once

#include <vector>

namespace Maxdev0101 {
namespace Plugin_core {

//------------------------------------------------------------------------
// CircularBuffer Implementation
//------------------------------------------------------------------------
class CircularBuffer
{
public:
    CircularBuffer () = default;
    
    void setup (double samplerate);
    void setDelayNormalized (double normalized);
    float process (float sample);
    
private:
    std::vector<float> buffer;
    int readIndex = 0;
    int currentSampleDelay = 44100;
};

} // namespace Plugin_core
} // namespace MaxDev0101
