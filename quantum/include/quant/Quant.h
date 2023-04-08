#pragma once
#include "wave_function/wave_function.h"

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

    template <typename Tt, unsigned int nn>
    friend size_t quant_hasher(const Quant<T, n> quant);
};

template <typename T, unsigned int n>
size_t quant_hasher(const Quant<T, n> quant)
{
    // NOTE (Timur): better to check one more time
    // or use boost::hash
    std::hash<T> hasher;
    size_t result = 144451;
    for (size_t i = 0; i < quant.coords.size(); ++i)
    {
        result = (result << 1) ^ hasher(quant[i]);
    }
    return result;
}

template <typename T, unsigned int n>
class QuantHash
{
public:
    size_t operator()(const Quant<T, n> quant) const
    {
        return quant_hasher<T, n>(quant);
    }
};

template <typename T, unsigned int n>
class QuantPtrHash
{
public:
    size_t operator()(const Quant<T, n> *quant) const
    {
        return quant_hasher<T, n>(*quant);
    }
};