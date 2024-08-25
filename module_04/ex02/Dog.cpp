#include "Animal.hpp"
#include "Dog.hpp"
#include "general.hpp"

/*============================================================================*/
/*       Constructors 			   	                                        */
/*============================================================================*/

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog : ";
	DEFAULT_CONSTRUCTOR_MESSAGE;
}

Dog::Dog( const Dog& src) : Animal(src)
{
	_type = src._type;
	_brain = new Brain(*src._brain); // deep copy
	std::cout << "Dog : ";
	COPY_CONSTRUCTOR_MESSAGE;
}

Dog &Dog::operator= (const Dog &src)
{
	_type = src._type;
	delete _brain;
	_brain = new Brain(*src._brain);
	std::cout << "Dog : ";
	COPY_ASSIGNMENT_MESSAGE;

	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog : ";
	DESTRUCTOR_MESSAGE;
}

/*============================================================================*/
/*       member functions				                                       */
/*============================================================================*/

void	Dog::makeSound(  ) const
{
	DOG_MESSAGE;
}

Brain &Dog::getBrain() const
{
	return (*_brain);
}

/*============================================================================*/
/*     example of shallow copy			                                       */
/*============================================================================*/


//Dog(const Dog &copy) {
//	std::cout << "Dog shallow copy constructor called" << std::endl;
//	this->brain = copy.brain;  // Shallow copy: just copying the pointer
//}
//
//Dog &operator=(const Dog &src) {
//	std::cout << "Dog shallow copy assignment operator called" << std::endl;
//	if (this != &src) {
//		this->brain = src.brain;  // Shallow copy: just copying the pointer
//	}
//	return *this;
//}