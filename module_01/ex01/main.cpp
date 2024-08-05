#include "Zombie.h"

int main() {
	int N1 = 100;

	Zombie* horde1 = zombieHorde(N1, "first_horde");
	if (N1 > 0 && horde1 != NULL)
	{
		for (int i = 0; i < N1; i++
				)
		{
			std::cout << i << std::endl;
			horde1[i].announce();
		}
		delete[] horde1;
	}


	std::cout << "\n\n\n\n\n\n\n" << "NEXT HORDE" << std::endl;
	int N2 = 100;

	Zombie* horde2 = zombieHorde(N1, "second_horde");
	if (N1 > 0 && horde2 != NULL)
	{
		for (int i = 0; i < N2; i++
				)
		{
			std::cout << i << std::endl;
			horde2[i].announce();
		}
		delete[] horde2;
	}
	return 0;
}
