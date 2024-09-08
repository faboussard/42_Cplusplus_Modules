#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	try {
		std::vector<int> numbers;
		numbers.push_back(1);
		numbers.push_back(2);
		numbers.push_back(3);
		numbers.push_back(4);
		numbers.push_back(5);
		numbers.push_back(6);

		std::cout << "\n\t\t TEST FOR ELEMENT FOUND     \n";
		std::vector<int>::iterator it = easyfind(numbers, 3);
		std::cout << "Element found: " << *it << std::endl;

		std::cout << "\n\t\t TEST FOR ELEMENT NOT FOUND     \n";

		it = easyfind(numbers, 10);
		std::cout << "Element found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
