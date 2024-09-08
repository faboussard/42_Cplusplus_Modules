#include "Span.hpp"
#include <iostream>

void printVector(std::vector<int> myvector)
{
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

int main()
{
	std::cout << "\n\t\t SUBJECT TESTS" << std::endl;
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "\n\t\t ADDRANGE TESTS" << std::endl;
	{
		Span sp = Span(10);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		printVector(sp.getVector());
		sp.addRange(s)
	}

	return 0;
}