#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clapRobot("Romulus");
	clapRobot.attack("Target_1");
	clapRobot.attack("");
	clapRobot.takeDamage(3); // hitpoints : 7
	clapRobot.beRepaired(1); // hitpoints : 8
	clapRobot.attack("Target_2");
	clapRobot.beRepaired(1); // hitpoints : 8
	clapRobot.takeDamage(9); // hitpoints : 0
	clapRobot.attack("Target_3");
	clapRobot.beRepaired(10); // hitpoints 10
	return (0);
}
