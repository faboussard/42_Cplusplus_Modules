#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>


#define NO_ENERGY_MESSAGE " No energy points left!"
#define NO_HIT_POINTS_MESSAGE " No hit points left!"
#define CLAPTRAP_ATTACK_MESSAGE(name, target, damage) \
    std::cout << "ClapTrap " << (name) << " attacks " << (target) << " causing " << (damage) << " points of damage!" << std::endl;
#define CLAPTRAP_DAMAGE_MESSAGE(name, amount) \
	std::cout << " ClapTrap " << (name) << " took " << (amount) << " damage!" << std::endl;
#define CLAPTRAP_REPAIRED_MESSAGE(name, amount) \
	std::cout << " ClapTrap " << (name) << " repaired itself with " << (amount) << " hit points!" << std::endl;
#define MAX_HIT_POINTS 10


class ClapTrap
{
protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

public:
	/* Default constructor */
	ClapTrap(const std::string &name);

	/* Copy constructor */
	ClapTrap(const ClapTrap &copy);

	/* Copy assignment operator overload */
	ClapTrap &operator=(const ClapTrap &rhs);

	/* Destructor */
	~ClapTrap();

	/* Member Functions */
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
