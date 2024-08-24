
#ifndef CPP_BRAIN_HPP
#define CPP_BRAIN_HPP

#include <string>

class Brain
{
public :

	Brain();
	~Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);

	std::string ideas[100];
};

#endif //CPP_BRAIN_HPP
