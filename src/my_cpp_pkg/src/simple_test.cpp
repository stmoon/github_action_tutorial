#include <gtest/gtest.h>

TEST(simple, test1)
{
    ASSERT_EQ(4, 2 + 2);
}

TEST(simple, test2)
{
    ASSERT_EQ(1, 2 / 2);
}


int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}