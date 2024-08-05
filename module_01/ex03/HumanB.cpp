
#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL)
{
	std::cout << _name << " entered the game" << std::endl;
}

HumanB::~HumanB() {
	std::cout << _name << " died" << std::endl;

}

void HumanB::attack()
{
	if (_weapon != NULL && _weapon->getType() != "")
		std::cout << _name << " attacks with " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has not weapon ! " << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}