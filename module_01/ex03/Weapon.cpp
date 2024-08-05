

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type) {
	std::cout << "a weapon with type " << _type << "has been created" << std::endl;
}

const std::string &Weapon::getType(void) const
{
	return (_type);
}

void Weapon::setType(const std::string &type)
{
	_type = type;
}
