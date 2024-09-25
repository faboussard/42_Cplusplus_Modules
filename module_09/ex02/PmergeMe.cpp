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
		: _vector(), _s_vector(), _pend_vector(), _deq(), _straggler(-1), _sortedPairs_vector() {}

PmergeMe::PmergeMe(int argc, char **argv) : _straggler(-1), _sortedPairs_vector() {
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
		: _vector(rhs._vector), _s_vector(rhs._s_vector), _pend_vector(rhs._pend_vector), _deq(rhs._deq),
		  _straggler(rhs._straggler), _sortedPairs_vector(rhs._sortedPairs_vector) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs) {
		_vector = rhs._vector;
		_deq = rhs._deq;
		_straggler = rhs._straggler;
		_sortedPairs_vector = rhs._sortedPairs_vector;
		_s_vector = rhs._s_vector;
		_pend_vector = rhs._pend_vector;
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

const vectorPairs &PmergeMe::getSortedPairs() const { return _sortedPairs_vector; }

std::vector<unsigned int> &PmergeMe::getMyVector() { return _vector; }

std::deque<unsigned int> &PmergeMe::getMyDeque() { return _deq; }

long int &PmergeMe::getMyStraggler() { return _straggler; }

vectorPairs &PmergeMe::getSortedPairs() { return _sortedPairs_vector; }

/*============================================================================*/
/*       Vector Member Functions */
/*============================================================================*/

void PmergeMe::VcreateStraggler() {
	if (getMyVector().size() % 2 != 0) {
		_straggler = _vector.back();
		_vector.pop_back();
	}
}

void PmergeMe::VmakeSortedPairs() {
	size_t size = _vector.size();

	for (size_t i = 0; i < size; i += 2) {
			if (_vector[i] < _vector[i + 1]) {
				_sortedPairs_vector.push_back(std::make_pair(_vector[i], _vector[i + 1]));
			} else {
				_sortedPairs_vector.push_back(std::make_pair(_vector[i + 1], _vector[i]));
			}
	}

	sortAndMerge(_sortedPairs_vector);

//	std::cout << "print _sortedPairs_vector: ";
//	for (const auto &pair : _sortedPairs_vector) {
//		std::cout << "(" << pair.first << ", " << pair.second << ") ";
//	}
//	std::cout << std::endl;
}

struct ComparePairs {
	bool operator()(const std::pair<unsigned int, unsigned int>& a, const std::pair<unsigned int, unsigned int>& b) {
		return a.second < b.second;
	}
};

void PmergeMe::sortAndMerge(vectorPairs &pairs) {
	if (pairs.size() <= 1) return;

	vectorPairs firstHalf(pairs.begin(), pairs.begin() + pairs.size() / 2);
	vectorPairs secondHalf(pairs.begin() + pairs.size() / 2, pairs.end());

	sortAndMerge(firstHalf);
	sortAndMerge(secondHalf);

	pairs.clear();
	pairs.reserve(firstHalf.size() + secondHalf.size());

	merge(firstHalf, secondHalf, pairs);
}

void PmergeMe::merge(const vectorPairs &firstHalf, const vectorPairs &secondHalf, vectorPairs &result) {
	size_t i = 0, j = 0;

	while (i < firstHalf.size() && j < secondHalf.size()) {
		if (ComparePairs()(firstHalf[i], secondHalf[j])) {
			result.push_back(firstHalf[i]);
			++i;
		} else {
			result.push_back(secondHalf[j]);
			++j;
		}
	}

	while (i < firstHalf.size()) {
		result.push_back(firstHalf[i]);
		++i;
	}

	while (j < secondHalf.size()) {
		result.push_back(secondHalf[j]);
		++j;
	}
}


void PmergeMe::s_sortedLargestValues() {

	for (size_t i = 0; i < _sortedPairs_vector.size(); ++i) {
		_s_vector.push_back(_sortedPairs_vector[i].second); // Ajouter la première valeur de chaque paire
	}

//	std::cout << "print _s_vector : ";
//	std::cout << _s_vector << std::endl;
}

void PmergeMe::pend_smallestValues() {
	for (size_t i = 0; i < _sortedPairs_vector.size(); ++i) {
		_pend_vector.push_back(_sortedPairs_vector[i].first);
	}
//	std::cout << "print _pend_vector : ";
//	std::cout << _pend_vector << std::endl;
}

std::vector<unsigned int> PmergeMe::generateJacobsthal() {
	std::vector<unsigned int> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);

	for (unsigned int i = 2; i < _pend_vector.size(); ++i) {
		unsigned int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		jacobsthal.push_back(next);
	}
//	std::cout << "print jacobsthal : ";
//	std::cout << jacobsthal << std::endl;

	return jacobsthal;
}

void PmergeMe::VinsertUsingBinarySearch(unsigned int element) {
	if (std::find(_s_vector.begin(), _s_vector.end(), element) == _s_vector.end()) {
		vector::iterator it = std::lower_bound(_s_vector.begin(), _s_vector.end(), element);
		_s_vector.insert(it, element);
	}
}

void PmergeMe::Vinsert() {
	std::vector<unsigned int> jacobsthal = generateJacobsthal();

	// Calculer le nombre d'éléments à insérer
	size_t numToInsert = (_pend_vector.size() / 2) - 1;

	// Assurer que nous ne sortons pas des limites
	numToInsert = std::max<size_t>(0, numToInsert);

	// Insérer les éléments dans l'ordre de Jacobsthal
	for (size_t i = 0; i < numToInsert && i < jacobsthal.size(); ++i) {
		unsigned int jacobIndex = jacobsthal[i];

		// Vérifier si l'indice Jacobsthal est valide pour _pend_vector
		if (jacobIndex < _pend_vector.size()) {
			unsigned int element = _pend_vector[jacobIndex]; // Obtenir l'élément à partir de _pend_vector

			// Utiliser VinsertUsingBinarySearch pour insérer l'élément
			VinsertUsingBinarySearch(element);
		}
	}

	// Vider _vector et copier les éléments triés depuis _s_vector
	_vector.clear();
	_vector = _s_vector;
}


//faire template
void PmergeMe::VinsertStraggler() {
	if (_straggler != -1) {
		vector::iterator it = std::lower_bound(_vector.begin(), _vector.end(), _straggler);
		_vector.insert(it, _straggler);
	}
}


/*============================================================================*/
/*       Deque Member Functions */
/*============================================================================*/


void PmergeMe::DcreateStraggler() {
	if (_deq.size() % 2 != 0) {
		_straggler = _deq.back();
		_deq.pop_back();
	}
}

void PmergeMe::DmakeSortedPairs() {
	for (size_t i = 0; i < _deq.size(); i += 2) {
		if (i + 1 < _deq.size()) {
			if (_deq[i] < _deq[i + 1]) {
				_sortedPairs_vector.push_back(std::make_pair(_deq[i], _deq[i + 1]));
			} else {
				_sortedPairs_vector.push_back(std::make_pair(_deq[i + 1], _deq[i]));
			}
		}
	}
	sortAndMerge(_sortedPairs_vector);
}

void PmergeMe::DinsertUsingBinarySearch(unsigned int element) {
	if (std::find(_s_vector.begin(), _s_vector.end(), element) == _s_vector.end()) {
		vector::iterator it = std::lower_bound(_s_vector.begin(), _s_vector.end(), element);
		_s_vector.insert(it, element);
	}
}

// faire un template
void PmergeMe::DinsertAndMerge() {
	std::vector<unsigned int> jacobsthal = generateJacobsthal();
	if (!_pend_vector.empty()) {
		DinsertUsingBinarySearch(_pend_vector[0]);
	}
	for (size_t i = 0; i < _pend_vector.size(); ++i)
		DinsertUsingBinarySearch(_pend_vector[i]);
	_deq.clear();
	_deq.assign(_s_vector.begin(), _s_vector.end());
}

void PmergeMe::DinsertStraggler() {
	if (_straggler != -1) {
		std::deque<unsigned int>::iterator it = std::lower_bound(_deq.begin(), _deq.end(), _straggler);
		_deq.insert(it, _straggler);
	}
}

void PmergeMe::sortVector() {
	VcreateStraggler();
	VmakeSortedPairs();
	s_sortedLargestValues();
	pend_smallestValues();
	Vinsert();
	VinsertStraggler();
}

void PmergeMe::sortDeque() {
	_sortedPairs_vector.clear();
	_s_vector.clear();
	_pend_vector.clear();

	DcreateStraggler();
	DmakeSortedPairs();
	s_sortedLargestValues();
	pend_smallestValues();
	DinsertAndMerge();
	DinsertStraggler();
}

/*============================================================================*/
/*       Class overload                                                       */
/*============================================================================*/

std::ostream &operator<<(std::ostream &os, const vector &vec) {
	for (vector::const_iterator it = vec.begin(); it != vec.end(); ++it) {
		os << *it << " ";
	}
	return os;
}

std::ostream &operator<<(std::ostream &os, const deque &deq) {
	for (deque::const_iterator it = deq.begin(); it != deq.end(); ++it) {
		os << *it << " ";
	}
	return os;
}
