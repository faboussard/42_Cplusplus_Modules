#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <vector>

class PmergeMe
{
private:
	std::vector<unsigned int> _vector;
	std::deque<unsigned int> _deq;

	public:
	PmergeMe();
	PmergeMe(int argc, char **argv);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &rhs);
	PmergeMe(const PmergeMe &rhs);
};

#endif