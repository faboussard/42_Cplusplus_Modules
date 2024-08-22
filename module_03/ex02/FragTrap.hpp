#ifndef FRAGTRAP_H
#define  FRAGTRAP_H

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
  public:
      FragTrap(const std::string &name);
      FragTrap(const FragTrap &copy);
      FragTrap &operator=(const FragTrap &rhs);
      ~FragTrap();

      void attack(const std::string &target);
      void highFivesGuys(void);

};

#endif