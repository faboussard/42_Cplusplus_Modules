#include "Zombie.h"

Zombie::Zombie() {}

Zombie::Zombie(std::string &zombie_name)
    : _name(zombie_name), _horde_index(0) {}

Zombie::~Zombie(void) {
  std::cout << _horde_index++ << " " << this->_name << " is destroyed"
            << std::endl;
};

void Zombie::announce(void) {
  std::cout << this->_name << ": BraiiiiiiinnnzzzZ.." << std::endl;
}

void Zombie::setName(std::string name) { this->_name = name; }