#include "Zombie.h"

int main()
{
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;

	randomChump("Stackzombie");
}