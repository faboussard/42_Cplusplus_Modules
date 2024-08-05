#include "Zombie.h"

void randomChump( std::string name)
{
	Zombie newZombie(name);
	newZombie.announce();
}