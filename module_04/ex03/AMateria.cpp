#include "AMateria.hpp"
#include "utils.hpp"

AMateria::AMateria() : _type("unknown")
{
	constructor_message("AMateria", GREEN);
}

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria::~AMateria()
{}

AMateria::AMateria(const AMateria &src)
{
	if (this != &src)
	{
		_type = src._type;
	}
}

AMateria &AMateria::operator=(AMateria const &src)
{
	_type = src._type;
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
