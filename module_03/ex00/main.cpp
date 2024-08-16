#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
  Fixed a;
  Fixed b(a);
  Fixed c;
  c = b;
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
  return 0;
}
/*
Default constructor called
Copy assignment operator called
Copy constructor called
Default constructor called
Copy assignment operator called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
*/