#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
  std::cout << "Copy constructor called" << std::endl;
  if (&copy != this)
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->_rawBits = copy.getRawBits();
  return (*this);
}

Fixed::Fixed(const int int_to_convert_to_fixed)
    : _rawBits(int_to_convert_to_fixed << _frac_bit) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_to_convert_to_fixed)
    : _rawBits(roundf(float_to_convert_to_fixed * (1 << _frac_bit))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (_rawBits);
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  _rawBits = raw;
}

float Fixed::toFloat(void) const {
  return (((float)_rawBits / (float)(1 << _frac_bit)));
}

int Fixed::toInt(void) const { return (_rawBits >> _frac_bit); }

std::ostream &operator<<(std::ostream &OUT, const Fixed &fixed) {
  OUT << fixed.toFloat();
  return OUT;
}

////////////////////////////////////* NEW
///*/////////////////////////////////////////////////

/*============================================================================*/
/*       Comparison Operator overload                                         */
/*============================================================================*/

bool Fixed::operator==(const Fixed &f2) const {
  return (_rawBits == f2._rawBits);
}

bool Fixed::operator!=(const Fixed &f2) const { return !(*this == f2); }

bool Fixed::operator>(const Fixed &f2) const {
  return (_rawBits > f2._rawBits);
}

bool Fixed::operator<(const Fixed &f2) const {
  return (_rawBits < f2._rawBits);
};

bool Fixed::operator>=(const Fixed &f2) const {
  return (*this > f2 || *this == f2);
}

bool Fixed::operator<=(const Fixed &f2) const {
  return (*this < f2 || *this == f2);
}

/*============================================================================*/
/*       Arithmetic Operator overload                                         */
/*============================================================================*/

Fixed Fixed::operator+(const Fixed &f2) const {
  Fixed result;
  result._rawBits = this->_rawBits + f2._rawBits;
  return result; // Return by value
}

Fixed Fixed::operator-(const Fixed &f2) const {
  Fixed result;
  result._rawBits = _rawBits - f2._rawBits;
  return result;
}

Fixed Fixed::operator*(const Fixed &f2) const {
  Fixed result;
  result._rawBits = _rawBits * f2._rawBits >> Fixed::_frac_bit;
  return result;
}

Fixed Fixed::operator/(const Fixed &f2) const {
  Fixed result;
  result._rawBits = (_rawBits << Fixed::_frac_bit) / f2._rawBits;
  return result;
}

/*============================================================================*/
/*       Increment/Decrement Operator overload                                */
/*============================================================================*/

Fixed &Fixed::operator++(void) {
  _rawBits += 1;
  return (*this);
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);

  _rawBits += 1;
  return (tmp);
}

Fixed &Fixed::operator--(void) {
  _rawBits -= 1;
  return (*this);
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);

  _rawBits -= 1;
  return (tmp);
}

/*============================================================================*/
/*       Overloaded member functions                                          */
/*============================================================================*/

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
  if (f1 < f2)
    return f1;
  else
    return f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
  if (f1 > f2)
    return f1;
  else
    return f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
  if (f1 < f2)
    return f1;
  else
    return f2;
}
const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
  if (f1 > f2)
    return f1;
  else
    return f2;
}
