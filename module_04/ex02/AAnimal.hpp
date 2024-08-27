#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

#define AANIMAL_MAKE_SOUND std::cout << "generic animal sound" << std::endl;

class AAnimal {
protected:
  std::string _type;

public:
  AAnimal(void);
  virtual ~AAnimal();
  AAnimal(const AAnimal &cpy);
  AAnimal &operator=(const AAnimal &src);

  std::string const &getType(void) const;
  virtual void makeSound(void) const = 0;
};

std::ostream &operator<<(std::ostream &stream, AAnimal &AAnimal);

#endif
