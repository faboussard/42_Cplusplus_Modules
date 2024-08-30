#include "ClapTrap.hpp"

/*============================================================================*/
/*       Constructors 			   	                                        */
/*============================================================================*/

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	setName(src.getName());
	setHitPoints(src.getHitPoints());
	setEnergyPoints(src.getEnergyPoints());
	setAttackDamage(src.getAttackDamage());
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
};

/*============================================================================*/
/*       getter 			   	                                        */
/*============================================================================*/

std::string ClapTrap::getName() const {
	return (_name);
}
int    ClapTrap::getHitPoints() const {
	return (_hitPoints);
}

int    ClapTrap::getEnergyPoints() const {
	return (_energyPoints);
}

int    ClapTrap::getAttackDamage() const {
	return (_attackDamage);
}

/*============================================================================*/
/*       setter 			   	                                        */
/*============================================================================*/

void ClapTrap::setName(const std::string &name)
{
	_name = name;
}

void ClapTrap::setHitPoints(int hitPoints)
{
	_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
	_attackDamage = attackDamage;
}

/*============================================================================*/
/*       member functions				                                       */
/*============================================================================*/


void ClapTrap::attack(const std::string &target)
{
	if (_energyPoints <= 0)
	{
		std::cout << NO_ENERGY_MESSAGE << std::endl;
		return;
	}
	if (_hitPoints <= 0)
	{
		std::cout << getName() << NO_HIT_POINTS_MESSAGE << std::endl;
		return;
	}
	_energyPoints -= 1;
	CLAPTRAP_ATTACK_MESSAGE(getName(), target, getAttackDamage());
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > 1000)
		amount = 1000;
	if (_hitPoints == 0)
	{
		std::cout << _name << NO_HIT_POINTS_MESSAGE << std::endl;
		std::cout << "cannot take any damage" << std::endl;
		return;
	}
	if (_hitPoints < 0)
		_hitPoints = 0;
	if (amount >= static_cast<unsigned int>(_hitPoints))
		_hitPoints = 0;
	else
		_hitPoints -= static_cast<int>(amount);
	CLAPTRAP_DAMAGE_MESSAGE(_name, amount);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (amount > 1000)
		amount = 1000;
	if (_energyPoints <= 0)
	{
		std::cout << NO_ENERGY_MESSAGE << std::endl;
		std::cout << "cannot be repaired" << std::endl;
		return;
	}
	_energyPoints -= 1;
	_hitPoints += static_cast<int>(amount);
	if (_hitPoints > MAX_HIT_POINTS)
		_hitPoints = MAX_HIT_POINTS;
	CLAPTRAP_REPAIRED_MESSAGE(_name, amount);
}

/*============================================================================*/
/*       Class overload		                                       */
/*============================================================================*/

std::ostream  &operator<<(std::ostream &stream, ClapTrap &clapTrap)
{
	stream << " Name: " << clapTrap.getName() << \
	" Hitpoints: " << clapTrap.getHitPoints() << \
	" Energy Points: " << clapTrap.getEnergyPoints() << \
	" Attack Damage: " << clapTrap.getAttackDamage();
	return (stream);
}