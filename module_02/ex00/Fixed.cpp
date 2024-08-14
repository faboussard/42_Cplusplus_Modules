#include "Fixed.h"

Fixed::Fixed(void) : _fixed_point_number(0) {
  std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &copy) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

Default constructor called Copy constructor called Copy assignment
operator called // <-- This line may be missing depending on your implementation
    getRawBits member function called

        Default constructor called Copy assignment operator called getRawBits
            member function called getRawBits member function
                called 0 getRawBits member function called 0 getRawBits member
                    function called 0

    Destructor called Destructor called Destructor called