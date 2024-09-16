#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "utils.hpp"
#include <iostream>

int main() {
  {
    std::cout
        << YELLOW
        << "--------------------------------------------------------------"
        << RESET << std::endl;
    std::cout << YELLOW << "\tSUBJECT TESTS " << RESET << std::endl;
    std::cout
        << YELLOW
        << "--------------------------------------------------------------"
        << RESET << std::endl;

    std::cout << std::endl;

    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");
    AMateria *tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    std::cout << std::endl;
  }
  {
    std::cout
        << YELLOW
        << "--------------------------------------------------------------"
        << RESET << std::endl;

    std::cout << YELLOW << "\tCUSTOM TESTS " << RESET << std::endl;
    std::cout
        << YELLOW
        << "--------------------------------------------------------------"
        << RESET << std::endl;

    std::cout << std::endl;
    std::cout
        << YELLOW
        << "--------------------------------------------------------------"
        << RESET << std::endl;

    std::cout << YELLOW << "\t TEST 1 : unequip " << RESET << std::endl;
    std::cout
        << YELLOW
        << "--------------------------------------------------------------"
        << RESET << std::endl;

    ICharacter *character1 = new Character("character1");
    ICharacter *character2 = new Character("character2");

    IMateriaSource *materiaSource = new MateriaSource();

    materiaSource->learnMateria(new Ice());
    materiaSource->learnMateria(new Cure());

    AMateria *tmp1;
    AMateria *tmp2;
    AMateria *tmp3;
    AMateria *tmp4;

    tmp1 = materiaSource->createMateria("ice");
    tmp2 = materiaSource->createMateria("cure");
    tmp3 = materiaSource->createMateria("cure");
    tmp4 = materiaSource->createMateria("cure");

    character1->equip(tmp1);
    character1->equip(tmp2);
    character1->equip(tmp3);
    character1->equip(tmp4);

    std::cout << std::endl;

    character1->use(0, *character2);
    character1->use(1, *character2);
    character1->use(2, *character2);
    character1->use(3, *character2);
    std::cout << std::endl;

    character1->unequip(-1);
    character1->unequip(1000);
    character1->unequip(1000);
    character1->unequip(0);
    character1->unequip(0);

    std::cout << std::endl;

    character1->equip(tmp1);

    character1->use(0, *character2);
    character1->use(1, *character2);
    character1->use(2, *character2);
    character1->use(3, *character2);

    std::cout << std::endl;

    delete character1;
    delete character2;
    delete materiaSource;
  }
  {
    std::cout
        << YELLOW
        << "--------------------------------------------------------------"
        << RESET << std::endl;

    std::cout << YELLOW << "\tCUSTOM TESTS " << RESET << std::endl;
    std::cout
        << YELLOW
        << "--------------------------------------------------------------"
        << RESET << std::endl;

    std::cout << std::endl;
    std::cout
        << YELLOW
        << "--------------------------------------------------------------"
        << RESET << std::endl;

    std::cout << YELLOW << "\t TEST 2 : invalid materia " << RESET << std::endl;
    std::cout
        << YELLOW
        << "--------------------------------------------------------------"
        << RESET << std::endl;

    ICharacter *character1 = new Character("character1");
    ICharacter *character2 = new Character("character2");

    IMateriaSource *materiaSource = new MateriaSource();

    materiaSource->learnMateria(new Ice());
    materiaSource->learnMateria(new Cure());

    AMateria *tmp;

    tmp = materiaSource->createMateria("ukulele");

    character1->equip(tmp);
    character2->equip(tmp);

    std::cout << std::endl;

    character1->use(0, *character2);

    std::cout << std::endl;

    delete character1;
    delete character2;
    delete materiaSource;
  }
  {
    std::cout
        << YELLOW
        << "--------------------------------------------------------------"
        << RESET << std::endl;
    std::cout << YELLOW << "\t TEST 3 : too many items " << RESET << std::endl;
    std::cout
        << YELLOW
        << "--------------------------------------------------------------"
        << RESET << std::endl;

    std::cout << std::endl;
    ICharacter *character1 = new Character("character1");
    ICharacter *character2 = new Character("character2");

    IMateriaSource *materiaSource = new MateriaSource;

    materiaSource->learnMateria(new Ice());
    materiaSource->learnMateria(new Cure());

    character1->equip(materiaSource->createMateria("cure"));
    character1->equip(materiaSource->createMateria("ice"));
    character1->equip(materiaSource->createMateria("ice"));
    character1->equip(materiaSource->createMateria("ice"));
    character1->equip(materiaSource->createMateria("ice"));

    character1->use(0, *character2);
    character1->use(1, *character2);
    character1->use(2, *character2);
    character1->use(3, *character2);
    character1->use(4, *character2);

    std::cout << std::endl;
    delete character1;
    delete character2;
    delete materiaSource;
  }
  {
    std::cout
        << YELLOW
        << "--------------------------------------------------------------"
        << RESET << std::endl;

    std::cout << YELLOW << "\t TEST 4 : deep copy verification " << RESET
              << std::endl;
    std::cout
        << YELLOW
        << "--------------------------------------------------------------"
        << RESET << std::endl;

    std::cout << std::endl;

    ICharacter *original = new Character("original");
    IMateriaSource *materiaSource = new MateriaSource();
    materiaSource->learnMateria(new Ice());
    materiaSource->learnMateria(new Cure());

    original->equip(materiaSource->createMateria("ice"));
    original->equip(materiaSource->createMateria("cure"));

    ICharacter *copy = new Character(*static_cast<Character *>(original));

    std::cout << "Using materias from the original character:" << std::endl;
    original->use(0, *copy);
    original->use(1, *copy);

    std::cout << "Using materias from the copied character:" << std::endl;
    copy->use(0, *original);
    copy->use(1, *original);

    std::cout << "Changing materias in the copied character:" << std::endl;
    AMateria *newMateria = materiaSource->createMateria("ice");
    copy->equip(newMateria);
    copy->use(2, *original);

    std::cout << "Checking original character after modification in the copied "
                 "character:"
              << std::endl;
    original->use(2, *copy);

    delete original;
    delete copy;
    delete materiaSource;
  }
  return 0;
}
