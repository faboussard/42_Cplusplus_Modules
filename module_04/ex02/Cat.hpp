#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

#define CAT_MESSAGE \
	std::cout << "Meow 🐱" << std::endl;

class Cat : public Animal
{
private:
	Brain *_brain;

public:

	Cat();
	virtual ~Cat();
	Cat(const Cat &cpy);
	Cat &operator=(const Cat &src);

	void makeSound() const;

	Brain &getBrain() const;
};

#endif
