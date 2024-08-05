
#ifndef CPP_HUMANB_HPP
#define CPP_HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

/*
 * Reference: Once bound to an object, it cannot be changed to refer to another object.
 * Ensuring Validity: A reference must always refer to a valid Weapon
 *  References guarantee that they cannot be null.
 *
 * Pointer: Can be reassigned to point to different objects throughout its lifetime.
 * If the object might be created and destroyed dynamically, pointers are appropriate.
 * When working with base and derived classes, pointers are often used to achieve polymorphism.
 * For instance, if Weapon objects are created using new, a pointer is needed to manage these objects.
 */
class HumanB
{
private:
	const std::string &_name;
	Weapon *_weapon;

public:
	HumanB(void);
	HumanB(const std::string &name);
	~HumanB(void);

	void setWeapon(Weapon &weapon);
	void attack();
};
#endif //CPP_HUMANB_HPP
