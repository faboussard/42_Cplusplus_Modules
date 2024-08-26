#include "Bureaucrat.hpp"

/*============================================================================*/
/*       Constructors 			   	                                        */
/*============================================================================*/


ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = copy._name;
	this->_attackDamage = copy._attackDamage;
	this->_energyPoints = copy._energyPoints;
	this->_hitPoints = copy._hitPoints;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
};

/*============================================================================*/
/*       member functions				                                       */
/*============================================================================*/


void ClapTrap::attack(const std::string &target)
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
		_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
	std::cout << " ClapTrap " << _name << " took " << amount << " damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= 0)
	{
		std::cout << " NO ENERGY" << std::endl;
		return;
	}
	_energyPoints -= 1;
	_hitPoints += amount;
	std::cout << " ClapTrap " << _name << " repaired itself with " << amount << " hit points!" << std::endl;
}