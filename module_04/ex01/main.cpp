#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include "utils.hpp"
int main()
{
	std::cout <<  CYAN << "\tSUBJECT TESTS "  << RESET <<  std::endl;
	std::cout << std::endl;

	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	std::cout << std::endl;
	std::cout <<  CYAN << "\tCUSTOM TESTS " << RESET << std::endl;
	std::cout << std::endl;

	std::cout <<  CYAN << "\t TEST 1" << RESET << std::endl;
	std::cout << std::endl;


	{
		const int numAnimals = 4;
		Animal* animals[numAnimals];



		for (int i = 0; i < numAnimals / 2; ++i) {
			animals[i] = new Dog();
		}
		for (int i = numAnimals / 2; i < numAnimals; ++i) {
			animals[i] = new Cat();
		}

		for (int i = 0; i < numAnimals; ++i) {
			delete animals[i];
		}
	}
	{
		std::cout << std::endl;
		std::cout <<  CYAN << "\t TEST 2" << RESET << std::endl;
		std::cout << std::endl;

		Cat *Cat1 = new Cat;
		std::cout << std::endl << "\t-- IDEAS cat 1..." << std::endl;
		Cat1->getBrain().setIdea(0, "HELLO");
		Cat1->getBrain().setIdea(1, "MY");
		Cat1->getBrain().setIdea(2, "FRIEND");

		std::cout << "Cat1 idea 0: \"" << Cat1->getBrain().getIdea(0) << "\"" << std::endl;
		std::cout << "Cat1 idea 1: \"" << Cat1->getBrain().getIdea(1) << "\"" << std::endl;
		std::cout << "Cat1 idea 2: \"" << Cat1->getBrain().getIdea(2) << "\"" << std::endl;
		std::cout << std::endl;


		Cat * Cat2 = new Cat(*Cat1);

		std::cout << std::endl;
		std::cout << std::endl << "\t-- IDEAS cat 2..." << std::endl;
		std::cout << std::endl;

		std::cout << "Cat2 idea 0: \"" << Cat2->getBrain().getIdea(0) << "\"" << std::endl;
		std::cout << "Cat2 idea 1: \"" << Cat2->getBrain().getIdea(1) << "\"" << std::endl;
		std::cout << "Cat2 idea 2: \"" << Cat2->getBrain().getIdea(2) << "\"" << std::endl;
		std::cout << std::endl << "\t-- new IDEAS cat 1 ..." << std::endl;


		Cat1->getBrain().setIdea(0, "HOW");
		Cat1->getBrain().setIdea(1, "ARe");
		Cat1->getBrain().setIdea(2, "YOU");
		std::cout << std::endl << "\t-- IDEAS cat 1..." << std::endl;

		std::cout << "Cat1 idea 0: \"" << Cat1->getBrain().getIdea(0) << "\"" << std::endl;
		std::cout << "Cat1 idea 1: \"" << Cat1->getBrain().getIdea(1) << "\"" << std::endl;
		std::cout << "Cat1 idea 2: \"" << Cat1->getBrain().getIdea(2) << "\"" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl << "\t-- IDEAS cat 2... have not changed" << std::endl;
		std::cout << std::endl;

		std::cout << "Cat2 idea 0: \"" << Cat2->getBrain().getIdea(0) << "\"" << std::endl;
		std::cout << "Cat2 idea 1: \"" << Cat2->getBrain().getIdea(1) << "\"" << std::endl;
		std::cout << "Cat2 idea 2: \"" << Cat2->getBrain().getIdea(2) << "\"" << std::endl;

		*Cat2 = *Cat1;

		std::cout << std::endl;
		std::cout << std::endl << "\t-- IDEAS cat 2... are now the same as cat 1" << std::endl;
		std::cout << std::endl;

		std::cout << "Cat2 idea 0: \"" << Cat2->getBrain().getIdea(0) << "\"" << std::endl;
		std::cout << "Cat2 idea 1: \"" << Cat2->getBrain().getIdea(1) << "\"" << std::endl;
		std::cout << "Cat2 idea 2: \"" << Cat2->getBrain().getIdea(2) << "\"" << std::endl;
		std::cout << std::endl;

		std::cout << std::endl;

		std::cout << std::endl;


		delete Cat1;
		delete Cat2;
	}
	return 0;

}