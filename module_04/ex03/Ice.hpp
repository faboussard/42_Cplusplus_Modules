#ifndef ICE_MATERIA_CLASS_H
# define ICE_MATERIA_CLASS_H

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	virtual ~Ice();
	Ice(const Ice &src);
	Ice &operator=(const Ice &src);

	AMateria *clone() const;
	void use(ICharacter & target);
};

#endif