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
} // le bitshifing se fait sur le 1 puis on divise par ce chiffre total de
  // bits.Supposons que _rawBits = 42 et _frac_bit = 8. Alors, le diviseur sera
  // 1 << 8 = 256. La division de 42 par 256 donne environ 0,1640625.
  // L'expression (1 << _frac_bit) déplace les bits du nombre 1 _frac_bit
  // positions vers la gauche. Cela crée un nombre dont tous les bits après la
  // première position sont des zéros, et le nombre de bits après la virgule est
  // égal à _frac_bit. Par exemple, si _frac_bit = 8, alors 1 << _frac_bit donne
  // 256 (en notation binaire, 100000000).

int Fixed::toInt(void) const {
  return (_rawBits >> _frac_bit);
  // ex: [ 42 \times 2^{8} = 2688 ]
  // si on a 42.1 et quon decale les bits vers la guache on aura le 1 en forme
  // binaire qui va dispaitre
}
////////////////////////////////////* NEW
///*////////////////////////////////////////

std::ostream &operator<<(std::ostream &OUT, const Fixed &fixed) {
  OUT << fixed.toFloat();
  return OUT;
}