//------------------------------------------------------------------------
// Copyright(c) 2025 MaxDev0101.
//------------------------------------------------------------------------
#include "maxdev0101/plugin-core/circularbuffer.h"

namespace Maxdev0101 {
namespace Plugin_core {

//------------------------------------------------------------------------
// CircularBuffer Implementation
//------------------------------------------------------------------------
 
//--------------------------------------------------
void CircularBuffer::resizeBufferOnSampleRateChange (int samplerate)
{
    maxSize = samplerate * 2;
    buffer.assign (maxSize, 0.f);
    writeIndex = 0;
}

//--------------------------------------------------
void CircularBuffer::write (float sample)
{
    buffer[writeIndex] = sample;
    writeIndex = (writeIndex + 1) % maxSize;
}

//--------------------------------------------------
float CircularBuffer::read (int delaySamples) const
{
    int readIndex = (writeIndex - delaySamples + maxSize) % maxSize;
    return buffer[readIndex];
}

//--------------------------------------------------
float CircularBuffer::readInterpolated (float delaySamples) const
{
    int d1 = static_cast<int>(delaySamples);
    int d2 = d1 + 1;
    float frac = delaySamples - d1;
    
    float sample1 = read (d1);
    float sample2 = read (d2);
    return sample1 + frac + (sample2 - sample1);
}

} // namespace Plugin_core
} // namespace MaxDev0101
