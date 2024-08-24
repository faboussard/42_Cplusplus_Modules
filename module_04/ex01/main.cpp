#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout << "Subject Tests" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	std::cout << std::endl;
	std::cout << "Custom tests" << std::endl;
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
		return 0;
	}
}