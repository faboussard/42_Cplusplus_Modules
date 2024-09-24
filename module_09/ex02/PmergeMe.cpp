#include "PmergeMe.hpp"
#include <algorithm>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>
#include <bits/stdc++.h>

/*============================================================================*/
/*       Constructors */
/*============================================================================*/

PmergeMe::PmergeMe()
    : _vector(), _s(), _pend(), _deq(), _straggler(-1), _sortedPairs() {}

PmergeMe::PmergeMe(int argc, char **argv) : _straggler(-1), _sortedPairs() {
  if (argc < 3) {
    std::cerr << "usage: ./PmergeMe int1 int2 ... " << std::endl;
    exit(EXIT_FAILURE);
  }
  for (int i = 1; i < argc; i++) {
    char *end;
    errno = 0;
    unsigned long value = std::strtoul(argv[i], &end, 10);
    if (end == argv[i] || *end != '\0' || errno == ERANGE) {
      std::cerr << "Invalid argument: " << argv[i] << std::endl;
      exit(EXIT_FAILURE);
    }
    if (value > std::numeric_limits<unsigned int>::max()) {
      std::cerr << "value out of range" << argv[i] << std::endl;
      exit(EXIT_FAILURE);
    }

    unsigned int unsignedValue = static_cast<unsigned int>(value);
    _vector.push_back(unsignedValue);
    _deq.push_back(unsignedValue);
  }
}

PmergeMe::PmergeMe(const PmergeMe &rhs)
    : _vector(rhs._vector), _s(rhs._s), _pend(rhs._pend), _deq(rhs._deq),
      _straggler(rhs._straggler), _sortedPairs(rhs._sortedPairs) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
  if (this != &rhs) {
    _vector = rhs._vector;
    _deq = rhs._deq;
    _straggler = rhs._straggler;
    _sortedPairs = rhs._sortedPairs;
    _s = rhs._s;
    _pend = rhs._pend;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

/*============================================================================*/
/*       Getter Functions                                                    */
/*============================================================================*/

const vector &PmergeMe::getMyVector() const { return _vector; }

const deque &PmergeMe::getMyDeque() const { return _deq; }

unsigned int PmergeMe::getMyStraggler() const { return _straggler; }

const vectorPairs &PmergeMe::getSortedPairs() const { return _sortedPairs; }

vector &PmergeMe::getMyVector() { return _vector; }

deque &PmergeMe::getMyDeque() { return _deq; }

unsigned int PmergeMe::getMyStraggler() { return _straggler; }

vectorPairs &PmergeMe::getSortedPairs() { return _sortedPairs; }

/*============================================================================*/
/*       Vector Member Functions */
/*============================================================================*/

void PmergeMe::createStraggler() {
  if (getMyVector().size() % 2 != 0) {
    _straggler = _vector.back();
    _vector.pop_back();
  }
}

void PmergeMe::makeSortedPairs() {
	size_t size = _vector.size();

	for (size_t i = 0; i < size; i += 2) {
		if (i + 1 < size) {
			if (_vector[i] < _vector[i + 1]) {
				_sortedPairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
			} else {
				_sortedPairs.push_back(std::make_pair(_vector[i + 1], _vector[i]));
			}
		} else {
			// If there's an odd element at the end, add it as a pair with itself
			_sortedPairs.push_back(std::make_pair(_vector[i], _vector[i]));
		}
	}

	// Sort pairs recursively by their larger element
	sortPairsRecursively(_sortedPairs);
}

// Functor for comparing pairs based on the largest element in each pair
struct ComparePairs {
	bool operator()(const std::pair<unsigned int, unsigned int>& a, const std::pair<unsigned int, unsigned int>& b) {
		return std::max(a.first, a.second) < std::max(b.first, b.second);
	}
};

void PmergeMe::sortPairsRecursively(std::vector<std::pair<unsigned int, unsigned int> >& pairs) {
	if (pairs.size() <= 1) return; // Base case

	// Sort pairs based on the largest element in each pair using the functor
	std::sort(pairs.begin(), pairs.end(), ComparePairs());

	// Recursively call sort on the first half and second half
	vectorPairs firstHalf(pairs.begin(), pairs.begin() + pairs.size() / 2);
	vectorPairs secondHalf(pairs.begin() + pairs.size() / 2, pairs.end());

	sortPairsRecursively(firstHalf);
	sortPairsRecursively(secondHalf);

	// Combine sorted halves back into pairs
	pairs.clear();
	pairs.insert(pairs.end(), firstHalf.begin(), firstHalf.end());
	pairs.insert(pairs.end(), secondHalf.begin(), secondHalf.end());
}


/* changer en recursif. est ce que ca reduit le nombre doperation ? en iteratif
 * : 46 us
 *
 * Recursively sort the [n/2] larger elements from each pair,
 * creating a sorted sequence S of [n/2] of the input elements, in ascending
 * order.*/


// s est trie

void PmergeMe::s_sortedLargestValues() {
	for (size_t i = 0; i < _sortedPairs.size(); ++i) {
		unsigned int largest = _sortedPairs[i].second;
		// Trouver la position où insérer "largest" pour maintenir _s trié
		vector::iterator pos = std::lower_bound(_s.begin(), _s.end(), largest);
		_s.insert(pos, largest); // Insérer à la position correcte
	}

	std::cout << "print _s : ";
	std::cout << _s << std::endl;
}


void PmergeMe::pend_smallestValues() {
  for (size_t i = 0; i < _sortedPairs.size(); ++i) {
    _pend.push_back(_sortedPairs[i].first);
  }
	std::cout << "print _pend : ";
	std::cout << _pend << std::endl;

}

vector PmergeMe::generateJacobsthal() {
	vector jacobsthal;
	jacobsthal.push_back(0); // J(0)
	jacobsthal.push_back(1); // J(1)

	for (unsigned int i = 2; i < _pend.size(); ++i) {
		unsigned int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		jacobsthal.push_back(next);
	}

	std::cout << "print jacobsthal : ";
	std::cout << jacobsthal << std::endl;

	return jacobsthal;
}



// lower bound utilise binary search pour trouver le lower range juste avant

void PmergeMe::insertUsingBinarySearch(unsigned int element) {
  vector::iterator it = std::lower_bound(_s.begin(), _s.end(), element);
  _s.insert(it, element);
}

void PmergeMe::insertAndMerge() {
	vector jacobsthal = generateJacobsthal();

	if (!_pend.empty()) {
		insertUsingBinarySearch(_pend[0]);
	}

	for (size_t i = 1; i < _pend.size(); ++i) {
		// If your sequence has more elements than the available Jacobsthal numbers, this logic
		// ensures that you can still
		// insert the remaining elements by falling back to a straightforward
		// insertion based on the current index (i).
		unsigned int jacobsthalIndex = (i < jacobsthal.size()) ? jacobsthal[i] : i;

		jacobsthalIndex = jacobsthalIndex % _pend.size();
/*
 * For example, if _pend.size() is 5 and jacobsthalIndex becomes 7, the result of 7 % 5 is 2.
 * This means that
 * instead of accessing an out-of-bounds index, it will point to the third element (index 2) in
 * the _pend vector.
 */
		insertUsingBinarySearch(_pend[jacobsthalIndex]);
	}

_vector.clear();
	_vector = _s;
}


void PmergeMe::insertStraggler() {
  if (_straggler != -1) {
    vector::iterator it =
        std::lower_bound(_vector.begin(), _vector.end(), _straggler);
    _vector.insert(it, _straggler);
  }
}

void PmergeMe::sortVector() {
  createStraggler();
  makeSortedPairs();
  s_sortedLargestValues();
  pend_smallestValues();
  insertAndMerge();
  insertStraggler();
}

/*============================================================================*/
/*       deque Member Functions */
/*============================================================================*/

/*============================================================================*/
/*       Class overload                                                       */
/*============================================================================*/

std::ostream &operator<<(std::ostream &os, const PmergeMe &pmergeMe) {
  os << pmergeMe.getMyVector() << std::endl;
  //	os << pmergeMe.getMyDeque() << std::endl;

  return os;
}

std::ostream &operator<<(std::ostream &os, const vector &vec) {
  for (vector::const_iterator it = vec.begin(); it != vec.end(); it++) {
    os << *it << " ";
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, const deque &deque) {
  for (deque::const_iterator it = deque.begin(); it != deque.end(); it++) {
    os << *it << " ";
  }
  return os;
}
