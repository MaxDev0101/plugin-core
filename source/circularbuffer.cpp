//------------------------------------------------------------------------
// Copyright(c) 2025 MaxDev0101.
//------------------------------------------------------------------------
#include "maxdev0101/plugin-core/circularbuffer.h"

namespace MaxDev0101 {
namespace Plugin_core {

//------------------------------------------------------------------------
// CircularBuffer Implementation
//------------------------------------------------------------------------
void CircularBuffer::setup(double samplerate)
{
    int maxSize = static_cast<int>(samplerate * 2.f);
    buffer.assign(maxSize, 0.f);
}

//------------------------------------------------------------------------
void CircularBuffer::setDelayNormalized(double normalized)
{
    // e.g. 1.0f = 44100 kHz * 2
    currentSampleDelay = normalized * buffer.size() * 2;
    // maybe lower the range for security
}

//------------------------------------------------------------------------
float CircularBuffer::process(float sample)
{
    int writeIndex = readIndex + currentSampleDelay;

    if (writeIndex >= currentSampleDelay)
        writeIndex -= currentSampleDelay;

    buffer[writeIndex] = sample;

    float value = buffer[readIndex];
    readIndex++;

    if (readIndex >= currentSampleDelay)
        readIndex -= currentSampleDelay;

    return value;
}

} // namespace Plugin_core
} // namespace MaxDev0101
