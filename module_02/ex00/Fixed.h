#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>

class Fixed {
private:
  int x;
  static const int frac_bit = 8;

public:
  Fixed();                  // Default constructor
  Fixed(const Fixed &copy); // copy constructor
  ~Fixed();                 // Destructor
  Fixed &operator=(
      const Fixed &src); // operateur daffectation de copie pour la classe fixed

  int getRawBits(
      void) const; // const car methode constante, elle ne peut pas modifier
                   // letat interne de lobjet sur lequel elle est appelle.
  void setRawBits(int const raw);
};

#endif