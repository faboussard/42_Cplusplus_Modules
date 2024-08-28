#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define ANIMAL_MAKE_SOUND \
	std::cout << "generic animal sound" << std::endl;

class Animal
{
protected:
	std::string _type;

public:

	Animal ();
	virtual ~Animal();
	Animal(const Animal &cpy);
	Animal &operator=(const Animal &src);

	std::string const &getType () const;
	virtual void makeSound() const;
};

std::ostream &operator<<(std::ostream &stream, Animal &Animal);
#endif
