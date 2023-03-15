#pragma once

template <typename T, unsigned int n>
class Quant
{
public:
	// To create a Quant, you need to pass an instance of a class that 
	// implements the WaveFunction interface
	Quant(WaveFunction<T, n> *wave_function) : wave_function(wave_function) {}

	~Quant() { delete wave_function; }

	// Measure wave function at given Point
	float measure_at(Point<T, n> p) { return wave_function->measure_at(p); }

private:
    mutable WaveFunction<T, n> *wave_function;
};