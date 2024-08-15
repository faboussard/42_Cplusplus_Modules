#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>

class Fixed {
private:
  int _rawBits;
  static const int _frac_bit = 8;

public:
  /* Default constructor */
  Fixed();

  /* Copy constructor */
  Fixed(const Fixed &copy);

  /* Copy assignment operator overolad*/
  Fixed &operator=(
      const Fixed &rhs); // operateur daffectation de copie pour la
                         // classe fixed. securite pour les allocations de
                         // memoire, les deux allocations seront construites et
                         // detruites independemment. rhs = "Right Hand Side

  /* Destructor */
  ~Fixed();

  /* Member Functions */
  int getRawBits(
      void) const; // const car methode constante, elle ne peut pas modifier
                   // letat interne de lobjet sur lequel elle est appelle.
  void setRawBits(int const raw);
};

#endif

/*#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
  std::cout << "Copy constructor called" << std::endl;
  *this = copy;
}

Fixed &Fixed::operator=(const Fixed &src) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->_rawBits = src.getRawBits();
  return (*this);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (this->_rawBits);
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->_rawBits = raw;
}
*/