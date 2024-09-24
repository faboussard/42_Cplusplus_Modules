#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>
#include <set>
#include <vector>

template<typename T>
void removeDuplicates(T &container)
{
	std::set<typename T::value_type> uniqueValues;
	typename T::iterator it = container.begin();  // Note the use of `typename`

	while (it != container.end())
	{
		if (uniqueValues.find(*it) == uniqueValues.end())
		{
			uniqueValues.insert(*it);  // Insert unique value
			++it;  // Move to the next element
		} else
		{
			it = container.erase(it);  // Erase duplicates and move iterator
		}
	}
}


void check_sorting(PmergeMe &pm)
{
	vector newVector = pm.getMyVector();

	vector::iterator first = newVector.begin();

	vector::iterator last = newVector.end();
	std::sort(first, last);
	removeDuplicates(newVector);

	std::cout << "newVector: " << std::endl;
	std::cout << newVector << std::endl;
	std::cout << std::endl;

	if (newVector == pm.getMyVector())
		std::cout << "******************* OK for sorting *************************" << std::endl;
	else
		std::cout << "******************* NOK for sorting *************************" << std::endl;


	std::cout << std::endl;

}


int main(int argc, char **argv)
{

	PmergeMe pm(argc, argv);

	/* vector sort */
	removeDuplicates(pm.getMyVector());
	std::cout << "Before: " << std::endl;
	std::cout << pm << std::endl;

	clock_t startTime = clock();
	pm.sortVector();
	clock_t endTime = clock();

	check_sorting(pm);
	double elapsed = static_cast<float>(endTime - startTime) / (CLOCKS_PER_SEC / 1000000.0);
	std::cout << "After: " << std::endl;

	std::cout << pm << std::endl;


	std::cout << std::endl;
	std::cout << "Time to process a range of " << pm.getMyVector().size()
			  << " elements with std::vector : " << elapsed << " us" << std::endl;


	/* deque sort */
//	startTime = clock();
//	removeDuplicates(pm.getMyDeque());
//	pm.sortDeque();
//	endTime = clock();
//	elapsed = static_cast<float>(endTime - startTime) / (CLOCKS_PER_SEC / 1000000.0);
//	std::cout << "Time to process a range of " << pm.getMyDeque().size()
//			  << " elements with std::deque : " << elapsed << " us" << std::endl;


	return 0;
}
