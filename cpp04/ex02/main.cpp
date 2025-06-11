#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

int main()
{
	// Instanciate a simple animal
	// Animal *animal = new Animal();
	// Animal squid;

	// Instanciate a simple cat
	Cat *cat = new Cat();
	cat->makeSound();
	delete cat;
	return 0;
}