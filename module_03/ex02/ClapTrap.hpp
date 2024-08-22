#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

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
