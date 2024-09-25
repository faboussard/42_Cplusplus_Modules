#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>
#include <set>
#include <vector>
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


void check_sorting_vector(PmergeMe &pm, vector &copy)
{

	vector::iterator first = copy.begin();
	vector::iterator last = copy.end();
	std::sort(first, last);
//	std::cout << "copy Vector: " << std::endl;
//	std::cout << copy << std::endl;
//	std::cout << std::endl;
	if (copy == pm.getMyVector())
		std::cout << "******************* OK for sorting *************************" << std::endl;
	else
		std::cout << "******************* NOK for sorting *************************" << std::endl;
	std::cout << std::endl;

}

void check_sorting_deque(PmergeMe &pm, deque &copy)
{

	deque::iterator first = copy.begin();
	deque::iterator last = copy.end();
	std::sort(first, last);
//	std::cout << "copy deque: " << std::endl;
//	std::cout << copy << std::endl;
//	std::cout << std::endl;
	if (copy == pm.getMyDeque())
		std::cout << "******************* OK for sorting *************************" << std::endl;
	else
		std::cout << "******************* NOK for sorting *************************" << std::endl;
	std::cout << std::endl;

}


int main(int argc, char **argv)
{
	try
	{
		PmergeMe pm(argc, argv);

		/* vector sort */
		removeDuplicates(pm.getMyVector());
		removeDuplicates(pm.getMyDeque());

		std::cout  << "Before: " << pm.getMyVector() << std::endl;
		vector copyVector = pm.getMyVector();
		deque copyDeque = pm.getMyDeque();

//		clock_t startTime = clock();
//		pm.sortVector();
//		clock_t endTime = clock();
//	check_sorting_vector(pm, copyVector);

		clock_t startTime = clock();
		sort(pm.getMyVector().begin(), pm.getMyVector().end());
		clock_t endTime  = clock();



		double elapsed = static_cast<float>(endTime - startTime) / (CLOCKS_PER_SEC / 1000000.0);
		std::cout << "After: " << pm.getMyVector() << std::endl;
		std::cout << "Time to process a range of " << pm.getMyVector().size()
				  << " elements with std::vector : " << elapsed << " us" << std::endl;

		/* deque sort */


//	startTime = clock();
//	pm.sortDeque();
//	endTime = clock();
		startTime = clock();
		sort(pm.getMyDeque().begin(), pm.getMyDeque().end());
		endTime = clock();
//		std::cout << "After: " << std::endl;
//		std::cout << pm.getMyDeque() << std::endl;
//	check_sorting_deque(pm, copyDeque);
	elapsed = static_cast<float>(endTime - startTime) / (CLOCKS_PER_SEC / 1000000.0);
	std::cout << "Time to process a range of " << pm.getMyDeque().size()
			  << " elements with std::deque : " << elapsed << " us" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}


	return 0;
}
