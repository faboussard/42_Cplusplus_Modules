#include "zombie.h"

Zombie::Zombie(std::string &zombie_name) : _name(zombie_name) {}

~Zombie(void) {};

void Zombie::announce(void)
{
	std::cout << this->_name << std::endl;
}