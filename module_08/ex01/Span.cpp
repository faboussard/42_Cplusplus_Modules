#include "Span.hpp"
#include <limits>

Span::Span(unsigned int n) : _maxSize(n)
{
	if (n <= 0)
		throw Span::NoNegativeNumbers();
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
	if (_vector.size() < 2)
	{
		throw Span::SizeTooSmallException();
	}

	std::vector<int> copy = _vector;
	std::sort(copy.begin(), copy.end());

	unsigned int shortest = std::numeric_limits<unsigned int>::max();
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
	if (_vector.size() < 2)
	{
		throw Span::SizeTooSmallException();
	}
	return *std::max_element(_vector.begin(), _vector.end())
	       - *std::min_element(_vector.begin(), _vector.end());
}