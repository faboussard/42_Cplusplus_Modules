#include "Ice.hpp"
#include "utils.hpp"
#include <iostream>


Ice::Ice() : AMateria("ice")
{
	constructor_message("Ice", MAGENTA);
}

Ice::~Ice()
{
}

Ice::Ice(const Ice &src) : AMateria("ice")
{
	if (this != &src)
	{
		*this = src;
		std::cout << MAGENTA << "Ice :";
	}
}

Ice &Ice::operator=(Ice const &src)
{
	_type = src._type;
	std::cout << MAGENTA << "Ice :";
	return *this;
}



