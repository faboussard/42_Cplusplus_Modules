#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>

#define DEFAULT_CONSTRUCTOR_MESSAGE \
	std::cout << MAGENTA << "Default Constructor called" << RESET << std::endl;
#define CONSTRUCTOR_MESSAGE \
	std::cout << MAGENTA << "Constructor called" << RESET << std::endl;
#define COPY_CONSTRUCTOR_MESSAGE \
	std::cout << MAGENTA << "Copy Constructor called" << RESET << std::endl;
#define COPY_ASSIGNMENT_MESSAGE \
	std::cout << MAGENTA << "Copy Assignment operator called" << RESET << std::endl;
#define DESTRUCTOR_MESSAGE \
	std::cout << MAGENTA << "Destructor called" << RESET << std::endl;


#define RESET "\033[0m"
#define WHITE "\033[1;37m"
#define BLACK "\033[1;30m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define BGWHITE "\033[47m"

#endif //UTILS_HPP
