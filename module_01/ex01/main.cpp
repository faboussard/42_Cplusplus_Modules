#include "Zombie.h"

int main() {
	int N = 5;
	Zombie* horde = zombieHorde(N, "Zombie");
	delete[] horde;
	return 0;
}
