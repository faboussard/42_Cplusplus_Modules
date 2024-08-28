
#include <iostream>
#include <string>
#include "utils.hpp"
#include "AMateria.hpp"

void construct_message(const std::string &name, const std::string &color, const std::string message)
{
	std::cout << color << name << message << RESET << std::endl;
}

void copyMaterias(AMateria *dest[4], AMateria* const src[4])
{
	for (int i = 0; i < 4; ++i)
	{
		if (src[i] != NULL)
			dest[i] = src[i]->clone();
		else
			dest[i] = NULL;
	}
}

void initMaterias(AMateria *materia[4])
{
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
}

void deleteMaterias(AMateria *materia[4])
{
	for (int i =0; i < 4; i++)
	{
		if (materia[i] != NULL)
			delete materia[i];
	}
}