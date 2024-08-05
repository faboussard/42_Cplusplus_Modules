#ifndef CPP_WEAPON_HPP
#define CPP_WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string _type;

public:
	Weapon(void);
	Weapon(const std::string &type);
	~Weapon(void);
	const std::string &getType(void) const;
	void setType(const std::string &type);
};

#endif //CPP_WEAPON_HPP
