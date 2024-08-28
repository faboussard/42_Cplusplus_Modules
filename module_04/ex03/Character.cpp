

#include "Character.hpp"
#include "utils.hpp"

/*============================================================================*/
/*       Constructors */
/*============================================================================*/


Character::Character() : _name("Unknown")
{
	initMaterias(_inventory);
	construct_message("Character", CYAN, DEFAULT_CONSTRUCTOR_MESSAGE);
}

Character::Character(const std::string & newName) : _name(newName)
{
	initMaterias(_inventory);
	construct_message("Character", CYAN, CONSTRUCTOR_MESSAGE);
}

Character::~Character()
{
	deleteMaterias(_inventory);
	construct_message("Character", CYAN, DESTRUCTOR_MESSAGE);
}

Character::Character(const Character &src)
{
	copyMaterias(_inventory, src._inventory);
	construct_message("Character", CYAN, COPY_CONSTRUCTOR_MESSAGE);
}

Character &Character::operator=(const Character &src)
{
	if (this != &src)
	{
		deleteMaterias(_inventory);
		copyMaterias(_inventory, src._inventory);
		construct_message("Character", CYAN, COPY_ASSIGNMENT_MESSAGE);
	}
	return *this;
}

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/


std::string const &	Character::getName(void) const
{
	return (_name);
}

void	Character::setName(std::string const & newName)
{
	_name = newName;
	return ;
}

/*============================================================================*/
/*       member functions */
/*============================================================================*/


void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int index)
{
	if (index < 0 || index > 3 || _inventory[index] == NULL)
	{
		std::cerr << "Invalid inventory index" << std::endl;
		return ;
	}
	_inventory[index] = NULL;
}

void	Character::use(int index, ICharacter& target)
{
	if (index < 0 || index > 3 || this->_inventory[index] == NULL)
	{
		std::cerr << "Invalid inventory index" << std::endl;
		return ;
	}
	_inventory[index]->use(target);
}
