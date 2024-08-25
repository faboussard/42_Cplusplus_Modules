#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	// Création d'un Dog spécifique
	Dog myDog;
	std::cout << "Type: " << myDog.getType() << std::endl;
	std::cout << "Sound: ";
	myDog.makeSound();

	// Utilisation du constructeur par copie
	Dog copiedDog = myDog;
	std::cout << "Type: " << copiedDog.getType() << std::endl;
	std::cout << "Sound: ";
	copiedDog.makeSound();

	// Utilisation de l'opérateur d'affectation par copie
	Dog anotherDog;
	anotherDog = myDog;
	std::cout << "Type: " << anotherDog.getType() << std::endl;
	std::cout << "Sound: ";
	anotherDog.makeSound();

	/*			CAT 		*/

	Cat myCat;
	std::cout << "Type: " << myCat.getType() << std::endl;
	std::cout << "Sound: ";
	myCat.makeSound();

	// Utilisation du constructeur par copie
	Cat copiedCat = myCat;
	std::cout << "Type: " << copiedCat.getType() << std::endl;
	std::cout << "Sound: ";
	copiedCat.makeSound();

	// Utilisation de l'opérateur d'affectation par copie
	Cat anotherCat;
	anotherCat = myCat;
	std::cout << "Type: " << anotherCat.getType() << std::endl;
	std::cout << "Sound: ";
	anotherCat.makeSound();

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