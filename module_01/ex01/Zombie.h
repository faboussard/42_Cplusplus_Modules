#ifndef CPP_MODULES_ZOMBIE_H
#define CPP_MODULES_ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string _name;
	int _horde_index;

public:
	Zombie(void);
	Zombie (std::string &name);
	~Zombie (void);
	void announce (void);
	void setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name);

#endif //CPP_MODULES_ZOMBIE_H
