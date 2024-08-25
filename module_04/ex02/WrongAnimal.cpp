#include "WrongAnimal.hpp"
#include "Animal.hpp"

WrongAnimal::WrongAnimal() : _type("wrong animal")
{
  std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
   std::cout << "WrongAnimal copy constructor called" << std::endl;
   *this = copy;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
  std::cout << "WrongAnimal copy assignment operator called" << std::endl;
  _type = src._type;
  return (*this);
}

WrongAnimal::~WrongAnimal()
{
   std::cout << " WrongAnimal destructor called" << std::endl;
}
void WrongAnimal::makeSound(void) const
{
  ANIMAL_MAKE_SOUND;
}
std::string WrongAnimal::getType(void) const
{
  return (_type);
}