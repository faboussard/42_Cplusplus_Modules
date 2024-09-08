#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::Span(const Span& other) : _vector(other._vector), _maxSize(other._maxSize)
{
}

Span::~Span()
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_vector = other._vector;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (_vector.size() >= _maxSize)
	{
		throw Span::SpanIsFullException();
	}
	_vector.push_back(n);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_vector.size() + std::distance(begin, end) > _maxSize)
	{
		throw Span::SpanIsFullException();
	}
	_vector.insert(_vector.end(), begin, end);
}

unsigned int Span::shortestSpan() const
{
	if (this->_vector.size() < 2)
	{
		throw Span::SizeTooSmallException();
	}

	std::vector<int> copy = _vector;
	std::sort(copy.begin(), copy.end());

	unsigned int shortest = *(copy.begin() + 1) - *copy.begin();
	for (std::vector<int>::iterator it = copy.begin(); it != copy.end() - 1; ++it)
	{
		unsigned int span = *(it + 1) - *it;
		if (span < shortest)
		{
			shortest = span;
		}
	}
	return shortest;
}

unsigned int Span::longestSpan() const
{
	if (this->_vector.size() < 2)
	{
		throw Span::SizeTooSmallException();
	}
	return *std::max_element(_vector.begin(), _vector.end())
	       - *std::min_element(_vector.begin(), _vector.end());
}

const char* Span::SpanIsFullException::what() const throw()
{
	return "Span is full, cannot add more numbers";
}

const char* Span::SizeTooSmallException::what() const throw()
{
	return "Not enough elements to calculate a span";
}

/*
 *utiliser  minmax_element
Return smallest and largest elements in range
Returns a pair with an iterator pointing to the element with the smallest value in the range [first,last) as first element, and the largest as second.

The comparisons are performed using either operator< for the first version, or comp for the second.

If more than one equivalent element has the smallest value, the first iterator points to the first of such elements.

If more than one equivalent element has the largest value, the second iterator points to the last of such elements.
*/
