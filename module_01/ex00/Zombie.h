#ifndef CPP_MODULES_ZOMBIE_H
#define CPP_MODULES_ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string _name;

public:
	Zombie (const std::string &name);
	~Zombie (void);
	void announce (void) ;
};

Zombie* newZombie(const std::string &name);
void    randomChump(const std::string &name);

#endif //CPP_MODULES_ZOMBIE_H
