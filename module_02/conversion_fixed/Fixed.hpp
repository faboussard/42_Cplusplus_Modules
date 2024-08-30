#ifndef FIXED_H
#define FIXED_H

#include <cmath>
#include <iostream>
#include <string>

class Fixed {
private:
  int _rawBits;
  static const int _frac_bit = 8;

public:
  /* Default constructor */
  Fixed();

  /* Int constructor */
  Fixed(const int int_to_convert_to_fixed);

  /* Float constructor */
  Fixed(const float float_to_convert_to_fixed);

  /* Copy constructor */
  Fixed(const Fixed &copy);

  /* Copy assignment operator overload*/
  Fixed &operator=(const Fixed &rhs);

  /* Destructor */
  ~Fixed();

  /* Member Functions */
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream &
operator<<(std::ostream &OUT,
           const Fixed &fixed); // le nom out est en majustcule car cest un type

#endif

/*
1111'1111'111|00000
0000'0000'000|11111

00........000|1111'1111
*/

/*
Conversion de 42 en Flottant
Si 42 est stocké comme une valeur entière dans une représentation fixe-point
avec un certain nombre de bits après la virgule, la conversion de cette valeur
en un nombre flottant dépend du nombre de bits après la virgule. Par exemple, si
_frac_bit = 8, alors 42 reste 42 dans la partie entière, et la partie
fractionnaire est 0. Multiplier 42 par 2^8 (pour ajuster la partie
fractionnaire) donne 2688, qui est la représentation fixe-point de 42.0.

Conversion de 5 en Flottant
De même, si 5 est stocké comme une valeur entière dans une représentation
fixe-point avec _frac_bit = 8, alors 5 reste 5 dans la partie entière, et la
partie fractionnaire est 0. Multiplier 5 par 2^8 donne 320, qui est la
représentation fixe-point de 5.0.

Relation Entre 42 et 5
La relation entre 42 et 5 dans une représentation fixe-point dépend de la
manière dont ils sont interprétés et convertis. Si 42 est converti en flottant
et ensuite arrondi à l'entier le plus proche, il donne 5. */