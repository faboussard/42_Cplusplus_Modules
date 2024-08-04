#ifndef CPP_MODULES_ZOMBIE_H
#define CPP_MODULES_ZOMBIE_H

#include <iostream>
#include <string>

class zombie
{
private:
	std::string _name;

public:
	void announce (void) ;
	zombie (const std::string &name);
	~zombie (void);
};

#endif //CPP_MODULES_ZOMBIE_H
