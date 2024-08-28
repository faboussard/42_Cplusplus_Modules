//#include "Character.hpp"
//#include "Colors.h"
#include "Cure.hpp"
#include "Ice.hpp"
#include "utils.hpp"
//#include "MateriaSource.hpp"
#include <iostream>

int main()
{
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
}

//void	testMateriaSource(void)
//{
//	std::cout << YELLOW << std::endl <<  "-------------------------------" << std::endl
//		<< "\tMATERIA SOURCE TEST" << std::endl
//		<<  "-------------------------------" << RESET << std::endl;
//	std::cout << std::endl << "-- MATERIA SOURCE CREATION" << std::endl;
////	MateriaSource * source = new MateriaSource();
//	Ice Ice1;
//}
//
//int	main(void)
//{
//	testMateriaSource();
//	return (0);
//}
