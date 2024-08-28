#ifndef AMATERIA_CLASS_H
# define AMATERIA_CLASS_H

#include <iostream>

#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string _type;

public:
	AMateria();
	AMateria(std::string const & type);
	virtual ~AMateria();
	AMateria(const AMateria &src);
	AMateria &operator=(const AMateria & src);

	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif
