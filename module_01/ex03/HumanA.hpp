
#ifndef CPP_HUMANA_HPP
#define CPP_HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	const std::string _name;
	Weapon &_weapon;

public:
	HumanA(void);
	HumanA(const std::string &name, Weapon &Weapon);
	~HumanA();

	void attack();
};

#endif //CPP_HUMANA_HPP
