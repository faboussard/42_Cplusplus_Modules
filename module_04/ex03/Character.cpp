

#include "Character.hpp"
#include "utils.hpp"

/*============================================================================*/
/*       Constructors */
/*============================================================================*/


Character::Character() : _name("Unknown")
{
	_initInventory();
	construct_message("Character", CYAN, DEFAULT_CONSTRUCTOR_MESSAGE);
}

Character::Character(const std::string & newName) : _name(newName)
{
	_initInventory();
	construct_message("Character", CYAN, CONSTRUCTOR_MESSAGE);
}

Character::~Character()
{
	_deleteInventory();
	construct_message("Character", CYAN, DESTRUCTOR_MESSAGE);
}

Character::Character(const Character &src)
{
	_copyInventory(src);
	construct_message("Character", CYAN, COPY_CONSTRUCTOR_MESSAGE);
}

Character &Character::operator=(const Character &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		_deleteInventory();
		_copyInventory(src);
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
	_inventory[index]->use(target); // ????
}

void Character::_copyInventory(const Character &src)
{
	for (int i = 0; i < 4; ++i)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();  // Clone each AMateria
		else
			_inventory[i] = nullptr;  // Initialize to nullptr if the source has no item
	}
}


void Character::_deleteInventory()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = nullptr;
		}
	}
}

void Character::_initInventory()
{
	for (int i = 0; i < 4; ++i)
	{
		_inventory[i] = nullptr;
	}
}
