#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>

class ClapTrap
{
private:
	_Name;
	_HitPoints;
	_AttackDamage;

public:
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif