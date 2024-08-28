#ifndef CURE_MATERIA_CLASS_H
# define CURE_MATERIA_CLASS_H

#include <iostream>

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	~Cure();
	Cure(const Cure &src);
	Cure &operator=(const Cure &sc);

	AMateria * clone() const;
	void use(ICharacter& target);
};

#endif
