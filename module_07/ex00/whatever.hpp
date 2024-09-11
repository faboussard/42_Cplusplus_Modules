#pragma once

#include <iostream>

template<typename T>
void swap(T& a, T& b) 
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const & max(T const & x, T const & y)
{
	if (x > y) return x;
	return y;
}

template<typename T>

T const & min(T const & x, T const & y)
{
	if (x < y) return x;
	return y;
}
