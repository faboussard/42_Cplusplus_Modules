#include "Span.hpp"
#include <iostream>
#include <stdexcept>

void printVector(const std::vector<int> &myvector)
{
	std::cout << "myvector contains:";
	for (std::vector<int>::const_iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

int main()
{
	std::cout << "\n\t\t SUBJECT TEST\n" << std::endl;
	{
		try
		{
			Span sp = Span(5);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			printVector(sp.getVector());

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\n\t\t NOT ENOUGH SIZE TEST\n" << std::endl;
	{
		try
		{
			Span sp = Span(3);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			printVector(sp.getVector());

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e) // Catch any other exceptions
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\n\t\t ADDNUMBER WHEN VECTOR IS FULL TEST\n" << std::endl;
	{
		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.addNumber(20);

			printVector(sp.getVector());
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\n\t\t ADDRANGE 1 SIZE TEST\n" << std::endl;
	{
		try
		{
			Span spFirst = Span(1);

			Span sp = spFirst;
			sp.addNumber(20);

			printVector(sp.getVector());
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\n\t\t ADDRANGE 0 SIZE TEST\n" << std::endl;
	{
		try
		{
			Span spFirst = Span(0);

			Span sp = spFirst;
			sp.addNumber(20);

			printVector(sp.getVector());

			std::cout << sp.shortestSpan() << std::endl;

		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	// Uncomment and test further if needed
	// std::cout << "\n\t\t ADDRANGE TEST\n" << std::endl;
	// {
	//     try
	//     {
	//         Span spFirst(15000);
	//
	//         Span sp = spFirst;
	//
	//         std::vector<int> values;
	//
	//         for (int i = 1; i <= 15000; i++)
	//             values.push_back(i);
	//         sp.addRange(values.begin(), values.end());
	//
	//         printVector(sp.getVector());
	//     }
	//     catch (const std::exception &e)
	//     {
	//         std::cerr << e.what() << std::endl;
	//     }
	// }
	std::cout << "\n\t\t ADDRANGE NO MORE PLACE TEST\n" << std::endl;
	{
		try
		{
			Span spFirst(15000);

			Span sp = spFirst;

			std::vector<int> values;

			for (int i = 1; i <= 16000; i++)
				values.push_back(i);
			sp.addRange(values.begin(), values.end()); // This should throw

			printVector(sp.getVector());
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}
