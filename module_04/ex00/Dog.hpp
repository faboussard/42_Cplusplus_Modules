#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

#define DOG_MESSAGE \
	std::cout << "Woof woof 🐶" << std::endl;

class Dog : public Animal
{
public:

	Dog();
	virtual ~Dog();
	Dog(const Dog &cpy);
	Dog &operator=(const Dog &src);

	void makeSound() const;
};

#endif
