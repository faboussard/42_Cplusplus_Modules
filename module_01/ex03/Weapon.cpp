

#include "Weapon.hpp"

Weapon::Weapon(void) : _type("") {
	std::cout << "The object Weapon has been created" << std::endl;
}

Weapon::Weapon(const std::string &type) : _type(type) {
	std::cout << "The object Weapon has been created" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "The object Weapon has been destroyed" << std::endl;
}

const std::string &Weapon::getType(void) const
{
	return (_type);
}

void Weapon::setType(const std::string &type)
{
	_type = type;
}
