#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define ANIMAL_MAKE_SOUND std::cout << "generic animal sound" << std::endl;

class Animal {
protected:
  std::string _type;

public:
  Animal();
  virtual ~Animal();
  Animal(const Animal &cpy);
  Animal &operator=(const Animal &src);

  std::string const &getType() const;
  virtual void makeSound() const;
};

std::ostream &operator<<(std::ostream &stream, Animal &Animal);

#define DEFAULT_CONSTRUCTOR_MESSAGE                                            \
  std::cout << "Default Constructor called" << std::endl;
#define CONSTRUCTOR_MESSAGE std::cout << "Constructor called" << std::endl;
#define COPY_CONSTRUCTOR_MESSAGE                                               \
  std::cout << "Copy Constructor called" << std::endl;
#define COPY_ASSIGNMENT_MESSAGE                                                \
  std::cout << "Copy Assignment operator called" << std::endl;
#define DESTRUCTOR_MESSAGE std::cout << "Destructor called" << std::endl;

#endif
