#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <limits>
#include <string>

#include "PmergeMe.hpp"

/*============================================================================*/
/*       Constructors 			   	                                        */
/*============================================================================*/

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr << "usage: ./PmergeMe int1 int2 ... " << std::endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 1; i < argc; i++)
	{
		char *end;
		errno = 0;
		unsigned long value = std::strtoul(argv[i], &end, 10);
		if (end == argv[i] || *end != '\0' || errno == ERANGE) // return value in case of error is 0, so we have to get the error differently
		{
			std::cerr << "Invalid argument: " << argv[i] << std::endl;
			exit(EXIT_FAILURE);
		}
		if (value > std::numeric_limits<unsigned int>::max())
		{
			std::cerr << "value out of range"  << argv[i] << std::endl;
			exit(EXIT_FAILURE);
		}

		unsigned int unsignedValue = static_cast<unsigned int>(value);
		_vector.push_back(unsignedValue);
		_deq.push_back(unsignedValue);
	}
}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		_vector = rhs._vector;
		_deq = rhs._deq;
	}
	return *this;
}

/*============================================================================*/
/*       getter 			   	                                        */
/*============================================================================*/

/*============================================================================*/
/*       setter 			   	                                        */
/*============================================================================*/


/*============================================================================*/
/*       member functions				                                       */
/*============================================================================*/


/*============================================================================*/
/*       Class overload		                                       */
/*============================================================================*/