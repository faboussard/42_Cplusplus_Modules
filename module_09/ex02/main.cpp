#include "PmergeMe.hpp"


//The management of errors related to duplicates is left to your
//discretion.


int main(int argc, char **argv) {
	try {
		PmergeMe pm(argc, argv);
		std::cout << "Before: " << std::endl;
		std::cout << pm << std::endl;

		pm.sort();

		std::cout << "After: " << std::endl;
		std::cout << pm << std::endl;

	} catch (const std::invalid_argument &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
