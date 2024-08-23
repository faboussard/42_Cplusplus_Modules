#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

#define CAT_MESSAGE \
	std::cout << "Meow 🐱" << std::endl;

class Cat : public Animal
{
public:

	Cat();
	~Cat();
	Cat(const Cat &cpy);
	Cat &operator=(const Cat &src);

	void makeSound() const;
};

#endif
