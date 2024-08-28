#include "AMateria.hpp"
#include "utils.hpp"

AMateria::AMateria() : _type("unknown")
{
	construct_message("AMateria", GREEN, DEFAULT_CONSTRUCTOR_MESSAGE);
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	construct_message("AMateria", GREEN, CONSTRUCTOR_MESSAGE);
}

AMateria::~AMateria()
{
	construct_message("AMateria", GREEN, DESTRUCTOR_MESSAGE);
}

AMateria::AMateria(const AMateria &src) : _type(src._type)
{
	if (this != &src)
	{
		*this = src;
	}
	construct_message("AMateria", GREEN, COPY_CONSTRUCTOR_MESSAGE);
}

AMateria &AMateria::operator=(AMateria const &src)
{
	construct_message("AMateria", GREEN, COPY_ASSIGNMENT_MESSAGE);
	return *this;
}

void AMateria::use(ICharacter &target)
{
	std::cout << RED "* An unknown materia is being used against"
			  << target.getName() << " *" RESET << std::endl;
	return;
}

std::string const &AMateria::getType(void) const
{
	return (_type);
}
