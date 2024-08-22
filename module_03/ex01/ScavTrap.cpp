#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
	{
		std::cout << "ScavTrap constructor called" << std::endl;
		_hitPoints = 100;
		_energyPoints = 50;
		_attackDamage = 20;
	}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy._name){
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	this->_name = copy._name;
	this->_attackDamage = copy._attackDamage;
	this->_energyPoints = copy._energyPoints;
	this->_hitPoints = copy._hitPoints;
	return (*this);
}

ScavTrap::~ScavTrap()
{
  std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
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
	std::cout << " ClapTrap " << _name << " attacks " << target << " causing " <<  _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
  std::cout << "ScavTrap " << _name << " is now in gate keeper mode" << std::endl;
}
