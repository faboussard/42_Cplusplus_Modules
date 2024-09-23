#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	try {
		PmergeMe pm(argc, argv);
		std::cout << "Before sorting, my vector and deque are:" << std::endl;
		std::cout << pm << std::endl;
	} catch (const std::invalid_argument &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
