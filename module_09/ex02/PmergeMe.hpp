#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <vector>

typedef std::vector<unsigned int> vector;
typedef std::deque<unsigned int> deque;
typedef std::vector<std::pair<unsigned int, unsigned int> > vectorPairs;

class PmergeMe {
private:
  vector _vector;
  vector _s_vector;    // the extracted largest values from pairs
  vector _pend; // first : the smallest values are extracted and then largest
                // values are inserted in this vector using jacobsthal
  deque _deq;
//  deque _s_deque;
  long _straggler;
	vectorPairs _sortedPairs;
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

  /* vector member functions */

  void sortVector();

  void createStraggler();
  void makeSortedPairs();
  void s_sortedLargestValues();
  void pend_smallestValues();
  void VinsertAndMerge();
  void VinsertStraggler();
  vector generateJacobsthal();
  void insertUsingBinarySearch(unsigned int element);
	void sortPairsRecursively(vectorPairs & pairs);

	/* vector member functions */

	void sortDeque();
	void DcreateStraggler();
	void DmakeSortedPairs();
	void DinsertAndMerge();
	void DinsertStraggler();
	void DinsertUsingBinarySearch(unsigned int element);


};

std::ostream &operator<<(std::ostream &os, const vector &vec);
std::ostream &operator<<(std::ostream &os, const deque &deq);

std::ostream &operator<<(std::ostream &os, const PmergeMe &pmergeMe);

#endif // PMERGEME_HPP