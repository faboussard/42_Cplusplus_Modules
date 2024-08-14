#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>

class Fixed {
private:
  int _fixed_point_number;
  static const int _frac_bit = 8;

public:
  Fixed();                  // Default constructor
  Fixed(const Fixed &copy); // copy constructor
  ~Fixed();                 // Destructor
  Fixed &operator=(
      const Fixed &rhs); // operateur daffectation de copie pour la
                         // classe fixed. securite pour les allocations de
                         // memoire, les deux allocations seront construites et
                         // detruites independemment. rhs = "Right Hand Side

  int getRawBits(
      void) const; // const car methode constante, elle ne peut pas modifier
                   // letat interne de lobjet sur lequel elle est appelle.
  void setRawBits(int const raw);
};

#endif