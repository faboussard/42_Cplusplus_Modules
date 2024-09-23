#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	try {
		PmergeMe pm(argc, argv);
	} catch (const std::invalid_argument &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
