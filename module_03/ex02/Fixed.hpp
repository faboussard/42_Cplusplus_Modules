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

  /*The 6 comparison operators: >, <, >=, <=, == and != member functions*/

  bool operator==(
      const Fixed &equal) const; // ca fait gagner en performance de passer la
                                 // reference (lecture seule plutot que copie)
                                 // Utiliser que des références constantes,
                                 // sinon utiliser des pointeurs
  bool operator!=(const Fixed &f2) const;
  bool operator>(const Fixed &f2) const;
  bool operator<(const Fixed &f2) const;
  bool operator>=(const Fixed &f2) const;
  bool operator<=(const Fixed &f2) const;

  /* The 4 arithmetic operators member functions */

  Fixed operator+(const Fixed &f2) const;
  Fixed operator-(const Fixed &f2) const;
  Fixed operator*(const Fixed &f2) const;
  Fixed operator/(const Fixed &f2) const;

  /* The 4 increment/decrement operators member functions */

  Fixed &operator++(void); // Il retourne une référence à Fixed, ce qui signifie
                           // que l'opérateur modifie l'objet original et
                           // retourne une référence à cet objet modifié.
  Fixed operator++(int);
  Fixed &operator--(void);
  Fixed operator--(int);

  // verifier bien pourquoi retourner une reference ou pas.

  /* overloaded member functions */

  static Fixed &min(Fixed &f1, Fixed &f2);
  static const Fixed &min(const Fixed &f1, const Fixed &f2);
  static Fixed &max(Fixed &f1, Fixed &f2);
  static const Fixed &max(const Fixed &f1, const Fixed &f2);
};

std::ostream &operator<<(std::ostream &OUT, const Fixed &fixed);

#endif
