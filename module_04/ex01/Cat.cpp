#include "Animal.hpp"
#include "Cat.hpp"
#include "general.hpp"

/*============================================================================*/
/*       Constructors 			   	                                        */
/*============================================================================*/

Cat::Cat()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat : ";
	DEFAULT_CONSTRUCTOR_MESSAGE;
}

Cat::Cat( const Cat& src) : Animal(src)
{
	_type = src._type;
	_brain = new Brain(*src._brain);
	std::cout << "Cat : ";
	COPY_CONSTRUCTOR_MESSAGE;
}

Cat &Cat::operator= (const Cat &src)
{
	_type = src._type;
	delete _brain;
	_brain = new Brain(*src._brain);
	std::cout << "Cat : ";
	COPY_ASSIGNMENT_MESSAGE;

	return *this;
}

Cat::~Cat(void)
{
	delete _brain;
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

Brain &Cat::getBrain() const
{
	return (*_brain);
}