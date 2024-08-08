#include "Zombie.h"


//sur la stack on cree tout dans la fonction ce sera detruit a la fin de son appel
int main()
{
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;

	randomChump("Stackzombie");
}