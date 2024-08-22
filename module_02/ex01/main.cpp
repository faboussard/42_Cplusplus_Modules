#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	Fixed e = Fixed(5);
	a = Fixed(318.28f);

	std::cout << "round of 10859.52 is " << roundf(10859.52) << std::endl;

	std::cout << "a is " << a << std::endl; // on obient 318.281 car ya 1 de bruit qui sest cree dans la conversion
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl; // on obient 318.281 car ya 1 de bruit qui sest cree dans la conversion
	std::cout << "e is " << e.toInt() << std::endl; // on obient 318.281 car ya 1 de bruit qui sest cree dans la conversion
	std::cout << "e is " << e.toFloat() << std::endl; // on obient 318.281 car ya 1 de bruit qui sest cree dans la conversion

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}