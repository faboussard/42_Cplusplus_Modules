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

ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	setName(src.getName());
	setAttackDamage(src.getAttackDamage());
	setEnergyPoints(src.getEnergyPoints());
	setHitPoints(src.getHitPoints());
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
		std::cout << NO_ENERGY_MESSAGE << std::endl;
		return;
	}
	if (_hitPoints <= 0)
	{
		std::cout << _name << NO_HIT_POINTS_MESSAGE << std::endl;
		return;
	}
	_energyPoints -= 1;
	SCAVTRAP_ATTACK_MESSAGE(_name, target, _attackDamage);
}

void ScavTrap::guardGate()
{
  std::cout << "ScavTrap " << _name << " is now in gate keeper mode" << std::endl;
}
