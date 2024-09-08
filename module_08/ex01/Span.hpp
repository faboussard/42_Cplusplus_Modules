
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

	class SpanIsFullException : public std::exception
	{
	public: virtual const char* what() const throw();
	};

	class SizeTooSmallException : public std::exception
	{
	public: virtual const char* what() const throw();
	};

private:
	std::vector<int> _vector;
	unsigned int _maxSize;
};

#endif
