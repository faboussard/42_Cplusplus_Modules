#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

#define CAT_MESSAGE std::cout << "Meow 🐱" << std::endl;

class Cat : public AAnimal {
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
