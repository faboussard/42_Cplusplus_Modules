#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
  std::cout << "FragTrap constructor called" << std::endl;
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
}
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy._name)
{
  std::cout << "FragTrap copy constructor called" << std::endl;
  *this = copy;
}
FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
  std::cout << "FragTrap copy assignment operator called" << std::endl;
  _name = rhs._name;
  _hitPoints = rhs._hitPoints;
  _energyPoints = rhs._energyPoints;
  _attackDamage = rhs._attackDamage;
  return (*this);
}

FragTrap::~FragTrap()
{
  std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (_energyPoints <= 0)
	{
		std::cout << " NO ENERGY" << std::endl;
		return;
	}
	if (_hitPoints <= 0)
	{
		std::cout << _name << " NO HIT POINTS " << std::endl;
		return;
	}
	_energyPoints -= 1;
	std::cout << " FragTrap " << _name << " attacks " << target << " causing " <<  _attackDamage << " points of damage!" << std::endl;
}


void FragTrap::highFivesGuys()
{
  std::cout << "FragTrap " << _name << " asks for a hive five, GIVE ME ONE !" << std::endl;
}