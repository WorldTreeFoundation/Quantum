# TODO

- class `World`:
  - points: array[Point]
  - quants: array[Quant]
  - entanglements: dict[Point, set[Point]] (with coloring to track cycles)
- class `Point` (n-dimensional)
  - basic structure ✅
  - implementation
- class `Quant`:
  - `float measure_at(Point p) { return wave_function.measure_at(p) }`
  - wave_function: WaveFunction
- class `WaveFunction` (interface) ✅
  - measure_at method ✅
  - complementary_events_sum method ✅
  - tests ✅
