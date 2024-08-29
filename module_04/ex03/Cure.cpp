#include "Cure.hpp"
#include "utils.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
  construct_message("Cure", BLUE, DEFAULT_CONSTRUCTOR_MESSAGE);
}

Cure::~Cure() { construct_message("cure", BLUE, DESTRUCTOR_MESSAGE); }

Cure::Cure(const Cure &src) : AMateria("cure") {
  *this = src;
  construct_message("Cure", BLUE, COPY_CONSTRUCTOR_MESSAGE);
}

Cure &Cure::operator=(Cure const &src) {
  if (this != &src)
    _type = src._type;
  construct_message("Cure", BLUE, COPY_ASSIGNMENT_MESSAGE);
  return *this;
}

// AMateria *Cure::clone(void) const {
//   AMateria *cureClone = new Cure();
//   return (cureClone);
// }

AMateria *Cure::clone(void) const { return (new Cure()); }

void Cure::use(ICharacter &target) {
  std::cout << GREEN "* heals " << target.getName() << "'s wounds *" RESET
            << std::endl;
}
