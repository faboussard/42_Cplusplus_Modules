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