#ifndef GENERAL_HPP
#define GENERAL_HPP

#include <iostream>
#include <string>

#define DEFAULT_CONSTRUCTOR_MESSAGE \
	std::cout << "Default Constructor called" << std::endl;
#define CONSTRUCTOR_MESSAGE \
	std::cout << "Constructor called" << std::endl;
#define COPY_CONSTRUCTOR_MESSAGE \
	std::cout << "Copy Constructor called" << std::endl;
#define COPY_ASSIGNMENT_MESSAGE \
	std::cout << "Copy Assignment operator called" << std::endl;
#define DESTRUCTOR_MESSAGE \
	std::cout << "Destructor called" << std::endl;

#define LOWEST_GRADE 150
#define HIGHEST_GRADE 1

#endif
