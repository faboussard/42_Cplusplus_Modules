#include "Zombie.h"

int main() {
	int N1 = 5;
	int N2 = 0;
	int N3 = -5;

	Zombie* horde1 = zombieHorde(N1, "first_horde");
	Zombie* horde2 = zombieHorde(N2, "second_horde");
	Zombie* horde3 = zombieHorde(N3, "third_horde");
	for (int i = 0; i < N1; i++)
		horde1[i].announce();
	delete[] horde1;

	int i = 0;
	horde2[i].announce();
	delete[] horde2;

	for (int i = 0; i > N3; i--)
		horde3[i].announce();
	delete[] horde3;

	return 0;
}
