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
	vector _s; // the extracted largest values from pairs
	vector _pend; // first : the smallest values are extracted and then largest values are inserted in this vector using jacobsthal
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
	const sortedPairs &getSortedPairs() const;


	vector &getMyVector();
	deque &getMyDeque() ;
	unsigned int getMyStraggler();
	sortedPairs &getSortedPairs();


	/* member functions */

	void sort();
	void createStraggler();
	void makeSortedPairs();
	void largestValues();
	void smallestValues();
	void insertAndMerge();
	void insertStraggler();


};

std::ostream &operator<<(std::ostream &os, const vector &vec);
std::ostream &operator<<(std::ostream &os, const deque &deq);

std::ostream &operator<<(std::ostream &os, const PmergeMe &pmergeMe);


#endif // PMERGEME_HPP