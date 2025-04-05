//------------------------------------------------------------------------
// Copyright(c) 2025 MaxDev0101.
//------------------------------------------------------------------------

#include "maxdev0101/plugin-core/circularbuffer.h"
#include "gtest/gtest.h"

using namespace Maxdev0101::Plugin_core;
//------------------------------------------------------------------------
TEST (TestSuite, SumTest)
{
	CircularBuffer circularBuffer(44100);
    EXPECT_EQ (circularBuffer.read(0), 0);
}
