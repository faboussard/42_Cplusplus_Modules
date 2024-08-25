
#ifndef CPP_BRAIN_HPP
#define CPP_BRAIN_HPP

#include <string>

class Brain
{
private:
	std::string ideas[100];

public :

	Brain();
	~Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);

	std::string &getIdea(int index);
	void setIdea(int index, const std::string &idea);
};

#endif //CPP_BRAIN_HPP
