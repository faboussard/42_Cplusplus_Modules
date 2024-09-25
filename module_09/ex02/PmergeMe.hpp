#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <vector>
#include <set>

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

	void s_sortedLargestValues();

	void pend_smallestValues();

	vector generateJacobsthal();

	void merge(const vectorPairs &firstHalf, const vectorPairs &secondHalf, vectorPairs &result);

	void sortAndMerge(vectorPairs &pairs);

	/* vector member functions */

	void sortVector();

	void VcreateStraggler();

	void VmakeSortedPairs();

	void VinsertAndMerge();

	void VinsertUsingBinarySearch(unsigned int element);


	void VinsertStraggler();


	/* deque member functions */


	void sortDeque();

	void DcreateStraggler();

	void DmakeSortedPairs();

	void DinsertAndMerge();

	void DinsertUsingBinarySearch(unsigned int element);

	void DinsertStraggler();

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