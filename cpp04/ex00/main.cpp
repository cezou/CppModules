#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();	
	std::cout << BLUE "end of subject's exemple" RESET << std::endl;
	delete meta;
	delete j;
	delete i;

	const WrongAnimal *meta2 = new WrongAnimal();
	const WrongAnimal *i2 = new WrongCat();
	std::cout << i2->getType() << " " << std::endl;
	i2->makeSound(); // will output wrong sound
	std::cout << std::endl
			  << YELLOW
			  << "                   🡅 " << std::endl
			  << "this is the wrong sound, the makeSound() used is the one" << std::endl
			  << " from the WrongAnimal class, and not the WrongCat class" << RESET << std::endl
			  << std::endl;
	meta2->makeSound();
	delete meta2;
	delete i2;
	return 0;
}