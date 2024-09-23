#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>


template <typename T>
void removeDuplicates(T& container) {
	std::vector<typename T::value_type> uniqueValues;
	for (size_t i = 0; i < container.size(); ++i) {
		if (std::find(uniqueValues.begin(), uniqueValues.end(), container[i]) == uniqueValues.end()) {
			uniqueValues.push_back(container[i]);
		}
	}
	container.clear();

	for (size_t j = 0; j < uniqueValues.size(); ++j)
		container.push_back(uniqueValues[j]);
}


int main(int argc, char **argv) {

		PmergeMe pm(argc, argv);
		std::cout << "Before: " << std::endl;
		std::cout << pm << std::endl;


		/* vector sort */
		clock_t startTime = clock();
		removeDuplicates(pm.getMyVector());
		pm.sortVector();
		clock_t endTime = clock();
	double elapsed =
			static_cast<float>(endTime - startTime) / (CLOCKS_PER_SEC / 1000000.0);
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
