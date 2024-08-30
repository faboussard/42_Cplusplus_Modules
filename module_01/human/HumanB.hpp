
#ifndef CPP_HUMANB_HPP
#define CPP_HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
private:
  const std::string _name;
  Weapon *_weapon;

public:
  HumanB(void);
  HumanB(const std::string &name);
  ~HumanB(void);

  void setWeapon(Weapon &weapon);
  void attack();
};
#endif // CPP_HUMANB_HPP
