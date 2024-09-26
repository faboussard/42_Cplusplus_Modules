#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <vector>
#include <set>
#include "PmergeMe.hpp"
#include <algorithm>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>
#include <deque>

typedef std::vector<unsigned int> vector;
typedef std::deque<unsigned int> deque;
typedef std::vector<std::pair<unsigned int, unsigned int> > vectorPairs;

class PmergeMe
{
private:
	vector _vector;
	vector _s_vector;
	vector _pend_vector;
	deque _deq;
	long _straggler;
	vectorPairs _sortedPairs_vector;
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

	long int getMyStraggler() const;

	const vectorPairs &getSortedPairs() const;

	vector &getMyVector();

	deque &getMyDeque();

	long int &getMyStraggler();

	vectorPairs &getSortedPairs();

	/* global member functions */

	void sortVector();
	void sortDeque();


	void s_sortedLargestValues();

	void pend_smallestValues();

	vector generateJacobsthal();

	void merge(const vectorPairs &firstHalf, const vectorPairs &secondHalf, vectorPairs &result);

	void sortAndMerge(vectorPairs &pairs);

	void insert_pend_In_s();

	void insertUsingBinarySearch(unsigned int element);

	/* templates */
template <typename T>
void insertStraggler(T &container) {
    if (_straggler != -1) {
        typename T::iterator it = std::lower_bound(container.begin(), container.end(),
                                                             static_cast<unsigned int>(_straggler));
        container.insert(it, _straggler);
    }
}

	template <typename T>
	void createStraggler(T &container){
		if (getMyVector().size() % 2 != 0) {
			_straggler = container.back();
			container.pop_back();
		}
	}

	template <typename T>
	void makeSortedPairs(T &container){
		for (size_t i = 0; i < container.size(); i += 2) {
			if (i + 1 < container.size()) {
				if (container[i] < container[i + 1]) {
					_sortedPairs_vector.push_back(std::make_pair(container[i], container[i + 1]));
				} else {
					_sortedPairs_vector.push_back(std::make_pair(container[i + 1], container[i]));
				}
			}
		}
		sortAndMerge(_sortedPairs_vector);
	}

};

std::ostream &operator<<(std::ostream &os, const vector &vec);

std::ostream &operator<<(std::ostream &os, const deque &deq);

template<typename T>
void removeDuplicates(T &container)
{
	std::set<typename T::value_type> uniqueValues;
	typename T::iterator it = container.begin();
	while (it != container.end())
	{
		if (uniqueValues.find(*it) == uniqueValues.end())
		{
			uniqueValues.insert(*it);
			++it;
		} else
		{
			it = container.erase(it);
		}
	}
}


#endif // PMERGEME_HPP