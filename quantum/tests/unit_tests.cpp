#include <gtest/gtest.h>

class ExampleTests : public ::testing::Test
{
};

TEST_F(ExampleTests, example_test_name)
{
    EXPECT_EQ(1, 1);
}