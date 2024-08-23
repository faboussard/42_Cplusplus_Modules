#include "Animal.hpp"
#include "Cat.hpp"
#include "general.hpp"

/*============================================================================*/
/*       Constructors 			   	                                        */
/*============================================================================*/

Cat::Cat()
{
	std::cout << "Cat : ";
	DEFAULT_CONSTRUCTOR_MESSAGE;
	_type = "Cat";
}

Cat::Cat( const Cat& src) : Animal(src)
{
	std::cout << "Cat : ";
	COPY_CONSTRUCTOR_MESSAGE;
	*this =src;
}

Cat &Cat::operator= (const Cat &src)
{
	std::cout << "Cat : ";
	COPY_ASSIGNMENT_MESSAGE;
	if (this != &src) {
		_type = src._type;
	}
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat : ";
	DESTRUCTOR_MESSAGE;
}

/*============================================================================*/
/*       member functions				                                       */
/*============================================================================*/

void	Cat::makeSound( void ) const
{
	CAT_MESSAGE;
}