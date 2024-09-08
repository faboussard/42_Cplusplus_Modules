#include "Array.hpp"

int main()
{
	Array<int> myArray(10);

	myArray.print_template(42);

	int a = 5;

	myArray.print_template(a);

	return 0;
}