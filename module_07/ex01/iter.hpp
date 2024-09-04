#pragma once

#include <iostream>

 template <typename T>
void iter(T arr[], int size, void (*func)(T const &))
{
	for (int i = 0; i < size; i++)
		func(arr[i]);
}

