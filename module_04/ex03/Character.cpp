

#include "Character.hpp"
#include "utils.hpp"

/*============================================================================*/
/*       Constructors */
/*============================================================================*/

Character::Character() : _name("Unknown") {
  initMaterias(_inventory);
  initMaterias(_tmpInventory);

  construct_message("Character", CYAN, DEFAULT_CONSTRUCTOR_MESSAGE);
}

Character::Character(const std::string &newName) : _name(newName) {
  initMaterias(_inventory);
  initMaterias(_tmpInventory);

  construct_message("Character", CYAN, CONSTRUCTOR_MESSAGE);
}

Character::~Character() {
  deleteMaterias(_inventory);
  deleteMaterias(_tmpInventory);
  construct_message("Character", CYAN, DESTRUCTOR_MESSAGE);
}

Character::Character(const Character &src) {
  copyMaterias(_inventory, src._inventory);
  copyMaterias(_tmpInventory, src._tmpInventory);

  construct_message("Character", CYAN, COPY_CONSTRUCTOR_MESSAGE);
}

Character &Character::operator=(const Character &src) {
  if (this != &src) {
    deleteMaterias(_inventory);
    deleteMaterias(_tmpInventory);
    copyMaterias(_inventory, src._inventory);
    copyMaterias(_tmpInventory, src._tmpInventory);
    construct_message("Character", CYAN, COPY_ASSIGNMENT_MESSAGE);
  }
  return *this;
}

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

std::string const &Character::getName(void) const { return (_name); }

void Character::setName(std::string const &newName) {
  _name = newName;
  return;
}

/*============================================================================*/
/*       member functions */
/*============================================================================*/

void Character::equip(AMateria *m) {
  if (m == NULL) {
    std::cerr << "invalid materia" << std::endl;
    return;
  }
  for (int i = 0; i < 4; i++) {
    if (_inventory[i] == NULL) {
      std::cout << getName() << " equips " << m->getType() << std::endl;

      _inventory[i] = m;
      return;
    }
  }
  delete m;
  std::cerr << "Inventory is full" << std::endl;
}

void Character::unequip(int index) {
  if (index < 0 || index > 3 || _inventory[index] == NULL) {
    std::cerr << "Invalid inventory index" << std::endl;
    return;
  }
  std::cout << getName() << " unequips " << _inventory[index]->getType()
            << std::endl;
  if (_tmpInventory[index] != NULL)
    _tmpInventory[index + 1] = _tmpInventory[index];
  _tmpInventory[index] = _inventory[index];
  _inventory[index] = NULL;
  std::cout << getName()
            << " temp inventory is : " << _tmpInventory[index]->getType()
            << std::endl;
}

void Character::use(int index, ICharacter &target) {
  if (index < 0 || index > 3 || this->_inventory[index] == NULL) {
    std::cerr << "Invalid inventory index" << std::endl;
    return;
  }
  _inventory[index]->use(target);
}
