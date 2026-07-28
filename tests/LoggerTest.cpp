#include "../include/Simulation.h"
#include <gtest/gtest.h>

TEST(MathTest, Add)
{
    // EXPECT_EQ(1 + 1, 2);

    Simulation sim;
    sim.Update(0.1f);
    SUCCEED();
}