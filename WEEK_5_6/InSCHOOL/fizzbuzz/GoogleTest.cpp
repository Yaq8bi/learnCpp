#include <iostream>
#include <string>
#include <gtest/gtest.h>

void func(int x)
{
    if (x < 0)
    {
        std::cerr << "BAD BASE" << std::endl;
        exit(1);
    }
}

TEST(MyTestSuite, Test1)
{
    EXPECT_EQ(1, 1) << "1 is not equal to 2";
}

TEST(example_DeathTest, SimpleDeath)
{
    // thread safe
    EXPECT_DEATH(func(10), "BAD THING1");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}