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

PmergeMe::PmergeMe() : _vector(), _deq(), _straggler(0), _sortedPairs()
{}

PmergeMe::PmergeMe(int argc, char **argv) : _straggler(0), _sortedPairs()
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

PmergeMe::PmergeMe(const PmergeMe &rhs) : _vector(rhs._vector), _deq(rhs._deq)
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		_vector = rhs._vector;
		_deq = rhs._deq;
		_straggler = rhs._straggler;
		_sortedPairs = rhs._sortedPairs;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}
/*============================================================================*/
/*       getter 			   	                                        */
/*============================================================================*/

const vector &PmergeMe::getMyVector() const
{
	return _vector;
}

const deque &PmergeMe::getMyDeque() const
{
	return _deq;
}

unsigned int PmergeMe::getMyStraggler() const
{
	return _straggler;
}


vector &PmergeMe::getMyVector() {
	return _vector;
}

deque &PmergeMe::getMyDeque() {
	return _deq;
}

unsigned int PmergeMe::getMyStraggler() {
	return _straggler;
}


/*============================================================================*/
/*       member functions				                                       */
/*============================================================================*/

void PmergeMe::createStraggler()
{
	if (getMyVector().size() % 2 != 0)
	{
		_straggler = getMyVector().back();
		getMyVector().pop_back();
	}
}


void PmergeMe::makeSortedPairs()
{
	size_t size = _vector.size();

	for (size_t i = 0; i < size; i += 2)
	{
		if (_vector[i] < _vector[i + 1])
			_sortedPairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
		else
		{
			_sortedPairs.push_back(std::make_pair(_vector[i + 1], _vector[i]));
		}
	}
	std::cout << "Sorted pairs:" << std::endl;
	for (size_t j = 0; j < _sortedPairs.size(); ++j) {
		std::cout << "(" << _sortedPairs[j].first << ", " << _sortedPairs[j].second << ")" << std::endl;
	}
}

void sequencePulledOutLargestValueFromPairs()
{

}

void PmergeMe::sort()
{
	createStraggler();
	makeSortedPairs();
	sequencePulledOutLargestValueFromPairs();
}

/*============================================================================*/
/*       Class overload		                                       */
/*============================================================================*/

std::ostream &operator<<(std::ostream &os, const PmergeMe &pmergeMe)
{
	os << pmergeMe.getMyVector() << std::endl;
	return os;
}


std::ostream &operator<<(std::ostream &os, const vector &vec)
{
	for (vector::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		os << *it << " ";
	}
	return os;
}

std::ostream &operator<<(std::ostream &os, const deque &deque)
{
	for (deque::const_iterator it = deque.begin(); it != deque.end(); it++)
	{
		os << *it << " ";
	}
	return os;
}


