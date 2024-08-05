
#include "HumanA.hpp"

HumanA::HumanA (const std::string &name, Weapon &weapon) : _name(name), _weapon(weapon) { std::cout << "HumanA entered the game" << std::endl;}

HumanA::~HumanA()
{
	std::cout << "HumanA died" << std::endl;
}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}