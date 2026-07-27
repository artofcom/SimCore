#include <gtest/gtest.h>
#include "../include/Simulation.h"

TEST(MathTest, Add)
{
    // EXPECT_EQ(1 + 1, 2);

    Simulation sim;
    sim.Update(0.1f);
    SUCCEED();
}