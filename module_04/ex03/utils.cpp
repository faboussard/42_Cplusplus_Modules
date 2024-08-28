
#include <iostream>
#include <string>
#include "utils.hpp"

void constructor_message(std::string &name, const std::string &color)
{
	std::cout << color << name << " : Constructor called" << RESET << std::endl;
}

#define DEFAULT_CONSTRUCTOR_MESSAGE \
	std::cout << "Default Constructor called" << std::endl;
#define CONSTRUCTOR_MESSAGE \
#define COPY_CONSTRUCTOR_MESSAGE \
	std::cout << "Copy Constructor called" << std::endl;
#define COPY_ASSIGNMENT_MESSAGE \
	std::cout << "Copy Assignment operator called" << std::endl;
#define DESTRUCTOR_MESSAGE \
	std::cout << "Destructor called" << std::endl;

