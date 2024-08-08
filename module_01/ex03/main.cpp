#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
	std::cout << "BASIC TEST WITH WEAPONG\n\n";
	{
		Weapon club = Weapon("a crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();

		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << "\n\n";
	{
		Weapon club = Weapon("a crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << "TEST HUMAN B WITH NULL WEAPON\n\n";
	try {
		Weapon validWeapon("a sharp sword");
		Weapon emptyWeapon(""); // Arme avec une chaîne vide pour test

		HumanA alice("Alice", validWeapon); // Devrait réussir
		alice.attack();

		HumanA invalidHuman("InvalidHuman", emptyWeapon);
		invalidHuman.attack();
	} catch (const std::invalid_argument &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "\n\n";
		Weapon validWeapon("a blunt club");
		Weapon emptyWeapon("");

		HumanB bob("Bob");
		bob.setWeapon(validWeapon);
		bob.attack();

		bob.setWeapon(emptyWeapon);
		bob.attack();
	return 0;
}