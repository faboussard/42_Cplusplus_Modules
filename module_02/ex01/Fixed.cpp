#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
  std::cout << "Copy constructor called" << std::endl;
  if (&copy != this)
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &src) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->_rawBits = src.getRawBits();
  return (*this);
}

////////////////////////////////////* NEW
///*////////////////////////////////////////
Fixed::Fixed(const int int_to_convert_to_fixed)
    : _rawBits(int_to_convert_to_fixed << _frac_bit) {
  std::cout << "Int constructor called" << std::endl;
}
// Le constructeur Fixed::Fixed(const float float_to_convert_to_fixed) convertit
// une valeur flottante en une représentation fixe-point en récupérant une
// approximation de la valeur entière

// la conversion de la valeur flottante float_to_convert_to_fixed en une
// représentation fixe-point est effectuée en utilisant std::roundf pour
// arrondir le produit de float_to_convert_to_fixed par 1 << _frac_bit. Cette
// opération a pour effet de récupérer une approximation de la valeur flottante
// sous forme de nombre entier, en tenant compte du nombre de bits
// fractionnaires spécifié par _frac_bit.
Fixed::Fixed(const float float_to_convert_to_fixed)
    : _rawBits(roundf(float_to_convert_to_fixed * (1 << _frac_bit))) {
  std::cout << "Float constructor called" << std::endl;
}
////////////////////////////////////* NEW
///*////////////////////////////////////////

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (_rawBits);
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  _rawBits = raw;
}

////////////////////////////////////* NEW
///*////////////////////////////////////////
float Fixed::toFloat(void) const {
  return (((float)_rawBits / (float)(1 << _frac_bit)));
} // un int divise pqr 1 donne un float. on le shift de 2 puissance 8.

int Fixed::toInt(void) const {
  return (_rawBits >> _frac_bit);
//le raw bi test un int; sii je le shift ca fait un int
}
////////////////////////////////////* NEW
///*////////////////////////////////////////

std::ostream &operator<<(std::ostream &OUT, const Fixed &fixed) {
  OUT << fixed.toFloat();
  return OUT;
}