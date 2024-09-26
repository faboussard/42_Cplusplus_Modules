#include "PmergeMe.hpp"


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
/*       global Member Functions */
/*============================================================================*/

void PmergeMe::insertUsingBinarySearch(unsigned int element) {
	if (std::find(_s_vector.begin(), _s_vector.end(), element) == _s_vector.end()) {
		vector::iterator it = std::lower_bound(_s_vector.begin(), _s_vector.end(), element);
		_s_vector.insert(it, element);
	}
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
		_s_vector.push_back(_sortedPairs_vector[i].second);
	}

//	std::cout << "print _s_vector : ";
//	std::cout << _s_vector << std::endl;
}

void PmergeMe::pend_smallestValues() {
	for (size_t i = 0; i < _sortedPairs_vector.size(); ++i) {
		_pend_vector.push_back(_sortedPairs_vector[i].first);
	}
	// std::cout << "print _pend_vector : ";
	// std::cout << _pend_vector << std::endl;
}

vector PmergeMe::generateJacobsthal() {
	vector jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);

	for (unsigned int i = 2; i < _pend_vector.size(); ++i) {
		unsigned int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		jacobsthal.push_back(next);
	}

//	std::cout << "print jacobsthal: ";
//	for (size_t i = 0; i < jacobsthal.size(); ++i) {
//		std::cout << jacobsthal[i] << " ";
//	}
//	std::cout << std::endl;

	return jacobsthal;
}

void  PmergeMe::insert_pend_In_s(){
	vector jacobsthal = generateJacobsthal();
	unsigned int element;

	for (size_t i = 0; i < jacobsthal.size(); i++) {
		if (jacobsthal[i] < _pend_vector.size()) {
			unsigned int jacobIndex = jacobsthal[i];
			element = _pend_vector[jacobIndex];
			insertUsingBinarySearch(element);
		} else {
			break;
		}
	}

	for (size_t i = 0; i < _pend_vector.size(); i++) {
		element = _pend_vector[i];

		if (std::find(_s_vector.begin(), _s_vector.end(), element) == _s_vector.end()) {
			insertUsingBinarySearch(element);
		}
	}
}


/*============================================================================*/
/*       Deque Member Functions */
/*============================================================================*/


void PmergeMe::sortVector() {
	createStraggler(_vector);
	makeSortedPairs(_vector);
	s_sortedLargestValues();
	pend_smallestValues();
	insert_pend_In_s();
	_vector.clear();
	_vector = _s_vector;
	insertStraggler(_vector);
}

void PmergeMe::sortDeque() {
	_sortedPairs_vector.clear();
	_s_vector.clear();
	_pend_vector.clear();

	createStraggler(_deq);
	makeSortedPairs(_deq);
	s_sortedLargestValues();
	pend_smallestValues();
	insert_pend_In_s();
	_deq.clear();
	_deq.assign(_s_vector.begin(), _s_vector.end());
	insertStraggler(_deq);
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
