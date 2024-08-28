#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

class WrongAnimal 
{
  protected:
      std::string _type;

  public:
      WrongAnimal();
      WrongAnimal(const WrongAnimal &copy);
      WrongAnimal &operator=(const WrongAnimal &src);
      virtual ~WrongAnimal();

      void makeSound(void) const;
      std::string getType(void) const;
};

#endif