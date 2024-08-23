#include "WrongCat.hpp"
#include "Cat.hpp"

WrongCat::WrongCat()
{
  std::cout << "WrongCat constructor called" << std::endl;
  _type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal()
{
   std::cout << "WrongCat copy constructor called" << std::endl;
   *this = copy;
}
WrongCat &WrongCat::operator=(const WrongCat &src)
{
  std::cout << "WrongCat copy assignment operator called" << std::endl;
  _type = src._type;
  return (*this);
}

WrongCat::~WrongCat()
{
   std::cout << " WrongCat destructor called" << std::endl;
}
void WrongCat::makeSound(void) const
{
  CAT_MESSAGE;
}