#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include "utils.hpp"

int main() {
	{
		std::cout <<  CYAN << "\tSUBJECT TESTS " << RESET << std::endl;

		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
	}

	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		meta->makeSound();
	}
	std::cout <<  CYAN << "\tCUSTOM TESTS " <<  RESET << std::endl;


	// Création d'un Animal générique
	Animal genericAnimal;
	std::cout << "Type: " << genericAnimal.getType() << std::endl;
	std::cout << "Sound: ";
	genericAnimal.makeSound();

	/*				DOG			*/

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

	return 0;
}
