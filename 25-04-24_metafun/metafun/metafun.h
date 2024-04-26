#pragma once
template <unsigned int N> struct getDigit;
template <unsigned int N> struct divNum;

template <unsigned int N> struct sumDigits
{
	static constexpr unsigned int value = getDigit<N>::value + sumDigits<N / 10>::value;
};

template <> struct sumDigits<0>
{
	static constexpr unsigned int value = 0;
};
template <unsigned int N> struct getDigit
{
	static constexpr unsigned int value = N % 10;
};


template <unsigned int N>
struct Fac {
	static constexpr unsigned int value = N * Fac<N - 1>::value;
};

template <>
struct Fac<0> {
	static constexpr unsigned int value = 1;
};