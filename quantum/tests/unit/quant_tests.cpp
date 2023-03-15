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

class QuantumTests : public ::testing::Test
{
protected:
    Quant<int, 1> *q;

    virtual void SetUp()
    {
        q = new Quant<int, 1>(new TestWF);
    }
    virtual void TearDown()
    {
        delete q;
    }
};

TEST_F(QuantumTests, measure_at_test)
{
    Point<int, 1> p({0});

    for (int i = -1; i < 3; i++)
    {
        p = Point<int, 1>({i});
        int expected = (i == 1) ? 1 : 0;
        EXPECT_EQ(q->measure_at(p), expected);
    }
}
