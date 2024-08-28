#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "utils.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
	std::cout <<  CYAN << "\tSUBJECT TESTS "  << RESET <<  std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout <<  CYAN << "\tCUSTOM TESTS "  << RESET <<  std::endl;
	{

	}

}