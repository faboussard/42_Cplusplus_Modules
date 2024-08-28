#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

#define AANIMAL_MAKE_SOUND std::cout << "generic animal sound" << std::endl;

class AAnimal {
protected:
  std::string _type;

public:
  AAnimal();
  virtual ~AAnimal();
  AAnimal(const AAnimal &cpy);
  AAnimal &operator=(const AAnimal &src);

  std::string const &getType() const;
  virtual void makeSound() const = 0;
};

std::ostream &operator<<(std::ostream &stream, AAnimal &AAnimal);

#endif
