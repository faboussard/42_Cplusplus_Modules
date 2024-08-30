#include "FragTrap.hpp"

int	main()
{
	std::cout << "---- FragTrap MAIN ----\n" << std::endl;

	FragTrap FragRobot1("FragRobot1");
	FragTrap FragRobot2("FragRobot2");

	FragTrap ClapRobot3(FragRobot1);

	std::cout << FragRobot1 << std::endl << FragRobot2 <<  std::endl << ClapRobot3 << std::endl;

	FragRobot1.attack("FragRobot2");
	FragRobot2.takeDamage(FragRobot1.getAttackDamage());

	std::cout << FragRobot1 << std::endl << FragRobot2 <<  std::endl << ClapRobot3 << std::endl;

	FragRobot2.beRepaired(100);

	std::cout << FragRobot1 << std::endl << FragRobot2 <<  std::endl << ClapRobot3 << std::endl;

	FragRobot1.attack("FragRobot2");
	FragRobot2.takeDamage(1000);

	std::cout << FragRobot1 << std::endl << FragRobot2 <<  std::endl << ClapRobot3 << std::endl;

	FragRobot2.beRepaired(5);

	std::cout << FragRobot1 << std::endl << FragRobot2 <<  std::endl << ClapRobot3 << std::endl;

	FragRobot2.highFivesGuys();

	std::cout << std::endl;

	return (0);
}
