#include <iostream>
#include "quantum/Quantum.h"
using namespace std;

class TestWF : public WaveFunction<int, 1>
{
public:
    float measure_at(Point<int, 1> &p) const override
    {
        return (p[0] == 1) ? 1 : 0;
    }
    float complementary_events_sum() const override { return 1; }
};

int main(int argc, char *argv[])
{
    World<int, 1> w;
    // TODO
    auto quant = w.create_quant<TestWF>();
    auto point1 = w.create_point({0});
    auto point2 = w.create_point({0});
    w.place_quant(quant, {point1, point2});

    return 0;
}