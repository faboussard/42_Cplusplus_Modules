#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <vector>

typedef std::vector<unsigned int> myVector;
typedef std::deque<unsigned int> myDeque;

class PmergeMe
{
private:
	myVector _vector;
	myDeque _deq;

	public:

	/* constructors */
	PmergeMe();
	PmergeMe(int argc, char **argv);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &rhs);
	PmergeMe(const PmergeMe &rhs);

	/* getters */
	const myVector &getMyVector() const;
	const myDeque &getMyDeque() const;

	/* member functions */

};

std::ostream &operator<<(std::ostream &os, const myVector &vec);
std::ostream &operator<<(std::ostream &os, const myDeque &deq);

std::ostream &operator<<(std::ostream &os, const PmergeMe &pmergeMe);


#endif // PMERGEME_HPP