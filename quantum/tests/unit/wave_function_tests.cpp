#include <gtest/gtest.h>
#include "quantum/Quantum.h"
#include <iostream>

class TestWF : public WaveFunction<int, 1>
{
public:
    float measure_at(Point<int, 1> &p) const override
    {
        return (p[0] == 1) ? 1 : 0;
    }
    float complementary_events_sum() const override { return 1; }
};

class WaveFunctonTests : public ::testing::Test
{
protected:
    TestWF *wf;

    virtual void SetUp()
    {
        wf = new TestWF;
    }
    virtual void TearDown()
    {
        delete wf;
    }
};

TEST_F(WaveFunctonTests, measure_at_test)
{
    Point<int, 1> p({0});

    for (int i = -1; i < 3; i++)
    {
        p = Point<int, 1>({i});
        int expected = (i == 1) ? 1 : 0;
        EXPECT_EQ(wf->measure_at(p), expected);
    }
}

TEST_F(WaveFunctonTests, complementary_events_sum_test)
{
    EXPECT_EQ(wf->complementary_events_sum(), 1);
}
