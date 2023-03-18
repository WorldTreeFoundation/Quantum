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
    w.place_quant(
        {new TestWF},
        {{{1}}, {{2}}}
    );
    w.place_quant(
        {new TestWF},
        {{{2}}, {{3}}}
    );
    return 0;
}