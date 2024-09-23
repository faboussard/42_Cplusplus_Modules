#include "PmergeMe.hpp"
#include <algorithm>

void removeDuplicates(PmergeMe &pm) {
	vector uniqueValues;
	for (size_t i = 0; i < pm.getMyVector().size(); ++i) {
		if (std::find(uniqueValues.begin(), uniqueValues.end(), pm.getMyVector()[i]) == uniqueValues.end()) {
			uniqueValues.push_back(pm.getMyVector()[i]);
		}
	}
	pm.getMyVector() = uniqueValues;
}


int main(int argc, char **argv) {
	try {
		PmergeMe pm(argc, argv);
		std::cout << "Before: " << std::endl;
		std::cout << pm << std::endl;

		removeDuplicates(pm);
		pm.sort();

		std::cout << "After: " << std::endl;
		std::cout << pm << std::endl;

	} catch (const std::invalid_argument &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
