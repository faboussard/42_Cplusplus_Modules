#include "Ice.hpp"
#include "utils.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {
  construct_message("Ice", MAGENTA, DEFAULT_CONSTRUCTOR_MESSAGE);
}

Ice::~Ice() { construct_message("ice", MAGENTA, DESTRUCTOR_MESSAGE); }

Ice::Ice(const Ice &src) : AMateria("ice") {
  *this = src;
  construct_message("ice", MAGENTA, COPY_CONSTRUCTOR_MESSAGE);
}

Ice &Ice::operator=(Ice const &src) {
  if (this != &src)
    _type = src._type;
  construct_message("ice", MAGENTA, COPY_ASSIGNMENT_MESSAGE);
  return *this;
}

AMateria *Ice::clone(void) const {
  AMateria *iceClone = new Ice();
  return (iceClone);
}

void Ice::use(ICharacter &target) {
  std::cout << MAGENTA "* shoots an ice bolt at " << target.getName()
            << " *" RESET << std::endl;
}
