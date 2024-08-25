#include "Brain.hpp"
#include "general.hpp"

Brain::Brain() {
	std::cout << "Brain: ";
	DEFAULT_CONSTRUCTOR_MESSAGE; }

	Brain::~Brain() {
	std::cout << "Brain: ";
	DESTRUCTOR_MESSAGE;
}

Brain::Brain(const Brain &other){
	std::cout << "Brain: ";
	*this = other;
	COPY_CONSTRUCTOR_MESSAGE;
}

Brain &Brain::operator=(const Brain &other){
	std::cout << "Brain: ";
	if (this != &other)
	{
		for (unsigned int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	COPY_ASSIGNMENT_MESSAGE;
	return *this;
}

