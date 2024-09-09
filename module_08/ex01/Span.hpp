
#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span
{
public:
	Span(unsigned int n);
	Span(const Span& other);
	~Span();

	Span &operator=(const Span& other);

	void addNumber(int n);
	void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	const std::vector<int> &getVector() const{
		return _vector;
	}

	const unsigned int &getMaxSize() const {
		return _maxSize;
	}

	class SpanIsFullException : public std::logic_error {
	public:
		SpanIsFullException() : std::logic_error("Span is full, cannot add more numbers") {}
	};

	class SizeTooSmallException : public std::logic_error {
	public:
		SizeTooSmallException() : std::logic_error("Not enough elements to calculate a span") {}
	};

class NoNegativeNumbers: public std::invalid_argument{
public:
	NoNegativeNumbers() : std::invalid_argument("positive numbers only") {};
};


private:
	std::vector<int> _vector;
	unsigned int _maxSize;
};

#endif
