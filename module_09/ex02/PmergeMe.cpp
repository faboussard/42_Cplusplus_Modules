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
#include <set>

/*============================================================================*/
/*       Constructors */
/*============================================================================*/

PmergeMe::PmergeMe()
		: _vector(), _s(), _pend(), _deq(), _straggler(-1), _sortedPairs() {}

PmergeMe::PmergeMe(int argc, char **argv) : _straggler(-1), _sortedPairs() {
	if (argc < 3) {
			throw std::runtime_error("usage: ./PmergeMe int1 int2 ... ");
		}
	for (int i = 1; i < argc; i++) {
		char *end;
		errno = 0;
		unsigned long value = std::strtoul(argv[i], &end, 10);
		if (end == argv[i] || *end != '\0' || errno == ERANGE) {
			throw std::runtime_error("Invalid argument: " + std::string(argv[i]));
		}
		if (value > std::numeric_limits<unsigned int>::max()) {
			throw std::range_error("Invalid argument: " + std::string(argv[i]));
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

const std::vector<unsigned int> &PmergeMe::getMyVector() const { return _vector; }

const std::deque<unsigned int> &PmergeMe::getMyDeque() const { return _deq; }

long int PmergeMe::getMyStraggler() const { return _straggler; }

const vectorPairs &PmergeMe::getSortedPairs() const { return _sortedPairs; }

std::vector<unsigned int> &PmergeMe::getMyVector() { return _vector; }

std::deque<unsigned int> &PmergeMe::getMyDeque() { return _deq; }

long int &PmergeMe::getMyStraggler() { return _straggler; }

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
			if (_vector[i] < _vector[i + 1]) {
				_sortedPairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
			} else {
				_sortedPairs.push_back(std::make_pair(_vector[i + 1], _vector[i]));
			}
	}

	sortPairsRecursively(_sortedPairs);

//	std::cout << "print _sortedPairs: ";
//	for (const auto &pair : _sortedPairs) {
//		std::cout << "(" << pair.first << ", " << pair.second << ") ";
//	}
//	std::cout << std::endl;
}

struct ComparePairs {
	bool operator()(const std::pair<unsigned int, unsigned int>& a, const std::pair<unsigned int, unsigned int>& b) {
		return std::max(a.first, a.second) < std::max(b.first, b.second);
	}
};

void PmergeMe::sortPairsRecursively(vectorPairs &pairs) {
	if (pairs.size() <= 1) return;

	// Diviser en deux moitiés
	vectorPairs firstHalf(pairs.begin(), pairs.begin() + pairs.size() / 2);
	vectorPairs secondHalf(pairs.begin() + pairs.size() / 2, pairs.end());

	// Appel récursif pour trier chaque moitié
	sortPairsRecursively(firstHalf);
	sortPairsRecursively(secondHalf);

	// Fusionner les deux moitiés
	pairs.clear();
	pairs.reserve(firstHalf.size() + secondHalf.size()); // Réserve de l'espace
	pairs.insert(pairs.end(), firstHalf.begin(), firstHalf.end());
	pairs.insert(pairs.end(), secondHalf.begin(), secondHalf.end());

	// Trier les paires après la fusion
	std::sort(pairs.begin(), pairs.end(), ComparePairs());
}

void PmergeMe::s_sortedLargestValues() {

	for (size_t i = 0; i < _sortedPairs.size(); ++i) {
		_s.push_back(_sortedPairs[i].second); // Ajouter la première valeur de chaque paire
	}

//	std::cout << "print _s : ";
//	std::cout << _s << std::endl;
}

void PmergeMe::pend_smallestValues() {
	for (size_t i = 0; i < _sortedPairs.size(); ++i) {
		_pend.push_back(_sortedPairs[i].first);
	}
//	std::cout << "print _pend : ";
//	std::cout << _pend << std::endl;
}

std::vector<unsigned int> PmergeMe::generateJacobsthal() {
	std::vector<unsigned int> jacobsthal;
	jacobsthal.push_back(0); // J(0)
	jacobsthal.push_back(1); // J(1)

	for (unsigned int i = 2; i < _pend.size(); ++i) {
		unsigned int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		jacobsthal.push_back(next);
	}
//
//	std::cout << "print jacobsthal : ";
//	std::cout << jacobsthal << std::endl;

	return jacobsthal;
}

// lower bound utilise binary search pour trouver le lower range juste avant
void PmergeMe::insertUsingBinarySearch(unsigned int element) {
	// Vérifie si l'élément n'existe pas déjà dans _s
	if (std::find(_s.begin(), _s.end(), element) == _s.end()) {
		std::vector<unsigned int>::iterator it = std::lower_bound(_s.begin(), _s.end(), element);
		_s.insert(it, element);
	}
}


void PmergeMe::insertAndMerge() {
	std::vector<unsigned int> jacobsthal = generateJacobsthal();

	if (!_pend.empty()) {
		insertUsingBinarySearch(_pend[0]);
	}

	std::set<unsigned int> insertedElements;

	for (size_t i = 0; i < _pend.size(); ++i) {
		unsigned int elementToInsert = _pend[i];

			insertUsingBinarySearch(elementToInsert);
			insertedElements.insert(elementToInsert);
	}
	_vector.clear();
	_vector = _s;
}




void PmergeMe::insertStraggler() {
	if (_straggler != -1) {
		vector::iterator it = std::lower_bound(_vector.begin(), _vector.end(), _straggler);
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
/*       Class overload                                                       */
/*============================================================================*/

std::ostream &operator<<(std::ostream &os, const PmergeMe &pmergeMe) {
	os << pmergeMe.getMyVector() << std::endl;
	// os << pmergeMe.getMyDeque() << std::endl;
	return os;
}

std::ostream &operator<<(std::ostream &os, const std::vector<unsigned int> &vec) {
	for (std::vector<unsigned int>::const_iterator it = vec.begin(); it != vec.end(); it++) {
		os << *it << " ";
	}
	return os;
}

std::ostream &operator<<(std::ostream &os, const std::deque<unsigned int> &deque) {
	for (std::deque<unsigned int>::const_iterator it = deque.begin(); it != deque.end(); it++) {
		os << *it << " ";
	}
	return os;
}
