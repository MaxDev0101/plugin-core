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
    const double bufSize = static_cast<double>(buffer.size() * 2);
    currentSampleDelay   = static_cast<int>(normalized * bufSize);
    if (currentSampleDelay > 0)
        writeIndex = writeIndex % currentSampleDelay;
    // maybe lower the range for security
}

//------------------------------------------------------------------------
float CircularBuffer::process(float sample)
{
    if (currentSampleDelay == 0)
        return sample;

    auto value         = buffer[writeIndex];
    buffer[writeIndex] = sample;

    writeIndex++;

    if (writeIndex >= currentSampleDelay)
        writeIndex -= currentSampleDelay;

    return value;
}

} // namespace Plugin_core
} // namespace MaxDev0101
