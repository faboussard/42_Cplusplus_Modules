#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

#define DOG_MESSAGE std::cout << "Woof woof 🐶" << std::endl;

class Dog : public AAnimal {
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
