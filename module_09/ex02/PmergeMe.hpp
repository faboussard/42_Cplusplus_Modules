#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <vector>

typedef std::vector<unsigned int> vector;
typedef std::deque<unsigned int> deque;
typedef std::vector<std::pair<unsigned int, unsigned int> > sortedPairs;


class PmergeMe
{
private:
	vector _vector;
	deque _deq;
	unsigned int _straggler;
	sortedPairs _sortedPairs;

	public:

	/* constructors */
	PmergeMe();
	PmergeMe(int argc, char **argv);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &rhs);
	PmergeMe(const PmergeMe &rhs);

	/* getters */
	const vector &getMyVector() const;
	const deque &getMyDeque() const;
	unsigned int getMyStraggler() const;

	vector &getMyVector();
	deque &getMyDeque() ;
	unsigned int getMyStraggler();

	/* member functions */

	void sort();
	void createStraggler();
	void makeSortedPairs();

};

std::ostream &operator<<(std::ostream &os, const vector &vec);
std::ostream &operator<<(std::ostream &os, const deque &deq);

std::ostream &operator<<(std::ostream &os, const PmergeMe &pmergeMe);


#endif // PMERGEME_HPP