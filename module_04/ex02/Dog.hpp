#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

#define DOG_MESSAGE \
	std::cout << "Woof woof 🐶" << std::endl;

class Dog : public Animal
{
private:
	Brain *_brain;

public:

	Dog();
	~Dog();
	Dog(const Dog &cpy);
	Dog &operator=(const Dog &src);

	void makeSound() const;
	Brain &getBrain() const;

};

#endif
