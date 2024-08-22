#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clapRobot("Romulus");
	clapRobot.attack("Remus");
	clapRobot.takeDamage(3); // hitpoints : 7
	clapRobot.beRepaired(1); // hitpoints : 8
	clapRobot.attack("Maman");
	clapRobot.beRepaired(1); // hitpoints : 8
	clapRobot.takeDamage(9); // hitpoints : 0
	clapRobot.attack("Popi");
	clapRobot.beRepaired(10); // hitpoints 10
	return (0);
}