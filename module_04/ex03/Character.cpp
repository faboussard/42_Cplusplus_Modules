#include "Character.hpp"
#include "utils.hpp"

/*============================================================================*/
/*       Constructors */
/*============================================================================*/

Character::Character() : _name("Unknown") {
	initMaterias(4, _inventory);
	initMaterias(MAX_ITEMS_NUMBERS, _groundInventory);

	construct_message("Character", CYAN, DEFAULT_CONSTRUCTOR_MESSAGE);
}

Character::Character(const std::string &newName) : _name(newName) {
	initMaterias(4, _inventory);
	initMaterias(MAX_ITEMS_NUMBERS, _groundInventory);

	construct_message("Character", CYAN, CONSTRUCTOR_MESSAGE);
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i]) {
			for (int j = 0; j < MAX_ITEMS_NUMBERS; j++) {
				if (_inventory[i] == _groundInventory[j]) {
					_groundInventory[j] = NULL;
				}
			}
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	deleteMaterias(MAX_ITEMS_NUMBERS, _groundInventory);
	construct_message("Character", CYAN, DESTRUCTOR_MESSAGE);
}

Character::Character(const Character &src) : _name(src._name) {
	initMaterias(4, _inventory);
	initMaterias(MAX_ITEMS_NUMBERS, _groundInventory);
	copyMaterias(4, _inventory, src._inventory);
	copyMaterias(MAX_ITEMS_NUMBERS, _groundInventory, src._groundInventory);

	construct_message("Character", CYAN, COPY_CONSTRUCTOR_MESSAGE);
}

Character &Character::operator=(const Character &src) {
	if (this != &src) {
		_name = src._name;
		deleteMaterias(4, _inventory);
		deleteMaterias(MAX_ITEMS_NUMBERS, _groundInventory);
		copyMaterias(4, _inventory, src._inventory);
		copyMaterias(MAX_ITEMS_NUMBERS, _groundInventory, src._groundInventory);
		construct_message("Character", CYAN, COPY_ASSIGNMENT_MESSAGE);
	}
	return *this;
}

/*============================================================================*/
/*       Accessors                                                             */
/*============================================================================*/

std::string const &Character::getName(void) const {
	return _name;
}

void Character::setName(std::string const &newName) {
	_name = newName;
}

/*============================================================================*/
/*       Member functions */
/*============================================================================*/

void Character::equip(AMateria *m) {
	if (m == NULL) {
		std::cerr << "Invalid materia" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			std::cout << getName() << " equips " << m->getType() << std::endl;
			_inventory[i] = m;
			return;
		}
	}
	std::cerr << "Inventory is full" << std::endl;
	delete m;
}

void Character::unequip(int index) {
	if (index < 0 || index > 3 || _inventory[index] == NULL) {
		std::cerr << "Invalid inventory index" << std::endl;
		return;
	}

	std::cout << getName() << " unequips " << _inventory[index]->getType() << std::endl;

	for (int i = 0; i < MAX_ITEMS_NUMBERS; i++) {
		if (_groundInventory[i] == NULL) {
			_groundInventory[i] = _inventory[index];
			_inventory[index] = NULL;
			return;
		}
	}
	std::cerr << "Ground inventory is full, cannot unequip" << std::endl;
}

void Character::use(int index, ICharacter &target) {
	if (index < 0 || index > 3 || _inventory[index] == NULL) {
		std::cerr << "Invalid inventory index" << std::endl;
		return;
	}
	_inventory[index]->use(target);
}
