# TODO

- class `World`:
  - points: array[Point]
  - quants: array[Quant]
  - entanglements: dict[Point, set[Point]] (with coloring to track cycles)
- class `Point` (n-dimensional)
- class `Quant`:
  - `float measure_at(Point p) { return wave_function.measure_at(p) }`
  - wave_function: WaveFunction
- class `WaveFunction` (interface):
  - `float measure_at(Point) == 0`
  - (?) check if == 1
