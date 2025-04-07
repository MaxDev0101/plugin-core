//------------------------------------------------------------------------
// Copyright(c) 2025 MaxDev0101.
//------------------------------------------------------------------------

#include "maxdev0101/plugin-core/circularbuffer.h"
#include "gtest/gtest.h"

using namespace MaxDev0101::Plugin_core;
//------------------------------------------------------------------------
TEST (TestSuite, SumTest)
{
	CircularBuffer circularBuffer;
    circularBuffer.setup(44100);
    EXPECT_EQ (circularBuffer.process(0), 0);
}
