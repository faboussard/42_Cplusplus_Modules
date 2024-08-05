#include "Zombie.h"

void randomChump(const std::string &name)
{
	Zombie newZombie(name);
	newZombie.announce();
}