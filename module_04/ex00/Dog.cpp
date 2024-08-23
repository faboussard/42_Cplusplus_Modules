#include "Animal.hpp"
#include "Dog.hpp"
#include "general.hpp"

/*============================================================================*/
/*       Constructors 			   	                                        */
/*============================================================================*/

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog : ";
	DEFAULT_CONSTRUCTOR_MESSAGE;
}

Dog::Dog( const Dog& src) : Animal(src)
{
	std::cout << "Dog : ";
	COPY_CONSTRUCTOR_MESSAGE;
	*this =src;
}

Dog &Dog::operator= (const Dog &src)
{
	std::cout << "Dog : ";
	COPY_ASSIGNMENT_MESSAGE;
	if (this != &src) {
		_type = src._type;
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog : ";
	DESTRUCTOR_MESSAGE;
}

/*============================================================================*/
/*       member functions				                                       */
/*============================================================================*/

void	Dog::makeSound( void ) const
{
	DOG_MESSAGE;
}