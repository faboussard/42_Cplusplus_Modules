#include "Animal.hpp"
#include "general.hpp"

/*============================================================================*/
/*       Constructors */
/*============================================================================*/

Animal::Animal() : _type("Animal") {
  std::cout << "Animal : ";
  DEFAULT_CONSTRUCTOR_MESSAGE;
}

Animal::Animal(const Animal &cpy) : _type(cpy._type) {
  std::cout << "Animal : ";
  COPY_CONSTRUCTOR_MESSAGE;
}

Animal &Animal::operator=(const Animal &src) {
  if (this != &src) {
    std::cout << "Animal : ";
    COPY_ASSIGNMENT_MESSAGE;
    _type = src._type;
  }
  return *this;
}

Animal::~Animal() {
  std::cout << "Animal : ";
  DESTRUCTOR_MESSAGE;
}

/*============================================================================*/
/*       member functions */
/*============================================================================*/

void Animal::makeSound(void) const { ANIMAL_MAKE_SOUND; }

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

std::string const &Animal::getType(void) const { return (_type); }

/*============================================================================*/
/*       Class overload		                                       */
/*============================================================================*/

std::ostream &operator<<(std::ostream &stream, Animal &animal) {
  stream << " Type: " << animal.getType();
  std::cout << "Sound";
  animal.makeSound();
  return (stream);
}
