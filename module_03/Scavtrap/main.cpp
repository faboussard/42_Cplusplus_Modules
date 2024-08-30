#include "ScavTrap.hpp"

int	main()
{
	std::cout << "---- ScavTrap MAIN ----\n" << std::endl;

	ScavTrap ScavRobot1("ScavRobot1");
	ScavTrap ScavRobot2("ScavRobot2");

	ScavTrap ClapRobot3(ScavRobot1);

	std::cout << ScavRobot1 << std::endl << ScavRobot2 <<  std::endl << ClapRobot3 << std::endl;

	ScavRobot1.attack("ScavRobot2");
	ScavRobot2.takeDamage(ScavRobot1.getAttackDamage());

	std::cout << ScavRobot1 << std::endl << ScavRobot2 <<  std::endl << ClapRobot3 << std::endl;

	ScavRobot2.beRepaired(100);

	std::cout << ScavRobot1 << std::endl << ScavRobot2 <<  std::endl << ClapRobot3 << std::endl;

	ScavRobot1.attack("ScavRobot2");
	ScavRobot2.takeDamage(1000);

	std::cout << ScavRobot1 << std::endl << ScavRobot2 <<  std::endl << ClapRobot3 << std::endl;

	ScavRobot2.beRepaired(5);

	std::cout << ScavRobot1 << std::endl << ScavRobot2 <<  std::endl << ClapRobot3 << std::endl;

	ScavRobot2.guardGate();

	std::cout << std::endl;

	return (0);
}
