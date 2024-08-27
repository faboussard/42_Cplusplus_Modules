#include "AAnimal.hpp"
#include "general.hpp"

/*============================================================================*/
/*       Constructors */
/*============================================================================*/

AAnimal::AAnimal() : _type("AAnimal") {
  std::cout << "AAnimal : ";
  DEFAULT_CONSTRUCTOR_MESSAGE;
}

AAnimal::AAnimal(const AAnimal &cpy) : _type(cpy._type) {
  std::cout << "AAnimal : ";
  COPY_CONSTRUCTOR_MESSAGE;
}

AAnimal &AAnimal::operator=(const AAnimal &src) {
  std::cout << "AAnimal : ";
  COPY_ASSIGNMENT_MESSAGE;
  if (this != &src) {
    _type = src._type;
  }
  return *this;
}

AAnimal::~AAnimal() {
  std::cout << "AAnimal : ";
  DESTRUCTOR_MESSAGE;
}

/*============================================================================*/
/*       member functions */
/*============================================================================*/

void AAnimal::makeSound(void) const { AANIMAL_MAKE_SOUND; }

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

std::string const &AAnimal::getType(void) const { return (_type); }

/*============================================================================*/
/*       Class overload		                                       */
/*============================================================================*/

std::ostream &operator<<(std::ostream &stream, AAnimal &AAnimal) {
  stream << " Type: " << AAnimal.getType();
  std::cout << "Sound";
  AAnimal.makeSound();
  return (stream);
}
