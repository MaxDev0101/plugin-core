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
    CircularBuffer (int samplerate)
    : maxSize (samplerate * 2)
    , buffer (maxSize, 0.f)
    , writeIndex(0)
    {}
    
    void resizeBufferOnSampleRateChange (int samplerate);
    void write (float sample);
    float read (int delaySamples) const;
    float readInterpolated (float delaySamples) const;
    
private:
    int maxSize;
    std::vector<float> buffer;
    int writeIndex;
};

} // namespace Plugin_core
} // namespace MaxDev0101
