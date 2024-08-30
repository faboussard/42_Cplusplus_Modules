#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "---- CLAPTRAP MAIN ----\n" << std::endl;

	ClapTrap ClapRobot1("ClapRobot1");
	ClapTrap ClapRobot2("ClapRobot2");

	ClapTrap ClapRobot3(ClapRobot1);

	std::cout << ClapRobot1 << std::endl << ClapRobot2 <<  std::endl << ClapRobot3 << std::endl;

	ClapRobot1.attack("ClapRobot2");
	ClapRobot2.takeDamage(ClapRobot1.getAttackDamage());

	std::cout << ClapRobot1 << std::endl << ClapRobot2 <<  std::endl << ClapRobot3 << std::endl;

	ClapRobot2.beRepaired(100);

	std::cout << ClapRobot1 << std::endl << ClapRobot2 <<  std::endl << ClapRobot3 << std::endl;

	ClapRobot1.attack("ClapRobot2");
	ClapRobot2.takeDamage(1000);

	std::cout << ClapRobot1 << std::endl << ClapRobot2 <<  std::endl << ClapRobot3 << std::endl;

	ClapRobot2.beRepaired(5);

	std::cout << ClapRobot1 << std::endl << ClapRobot2 <<  std::endl << ClapRobot3 << std::endl;


	return (0);
}
