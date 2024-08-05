
#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL)
{
	std::cout << "HumanB entered the game" << std::endl;
}

HumanB::~HumanB() {
	std::cout << "HumanB died" << std::endl;
}

void HumanB::attack()
{
	if (_weapon != NULL && _weapon->)
	std::cout << _name << " attacks with their " << _weapon << std::endl;

}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}