#include <iostream>
#include "iter.hpp"

void callbackPrintInt(int const &x)
{
	std::cout << x << std::endl;
}

void callbakPrintDouble(double const &x)
{
	std::cout << x << std::endl;
}

void printString(std::string const &str)
{
	std::cout << str << std::endl;
}

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	double doubleArray[] = {1.1, 2.2, 3.3};
	std::string stringArray[] = {"Hello", "World", "from", "C++"};

	iter(intArray, 5, callbackPrintInt);

	iter(doubleArray, 3, callbakPrintDouble);

	iter(stringArray, 4, printString);

	return 0;
}
