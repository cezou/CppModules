#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <fstream>
#include <iostream>

#ifndef TEST
#define TEST 0
#endif

/**
 * @brief Test function for unequip functionality
 */
void test_unequip()
{
	std::cout << "\n---- Test unequip et gestion du sol ----" << std::endl;
	Character *hero = new Character("Hero");
	Character target("Target");

	hero->equip(new Ice());
	hero->equip(new Cure());
	hero->equip(new Ice());
	hero->equip(new Ice());
	hero->equip(new Ice());
	hero->useAll(target);
	hero->unequip(1);
	hero->unequip(0);
	hero->unequip(2);
	hero->unequip(2);
	hero->unequip(2);
	hero->unequip(2);
	hero->unequip(2);
	hero->unequip(3);
	std::cout << "\n---- Après déséquipement ----" << std::endl;
	hero->useAll(target);
	delete hero;
}

/**
 * @brief Extended test function
 */
void d_main()
{
	std::cout << "\n\n";
	std::cout << "====================" << std::endl;
	std::cout << "===   TEST MAIN   ===" << std::endl;
	std::cout << "====================" << std::endl;
	std::cout << "\n\n";
	std::cout << "---- Test de copie profonde ----" << std::endl;

	Ice *original = new Ice();
	Ice *clone = new Ice(*original);

	std::cout << "Original type: " << original->getType() << std::endl;
	delete original;
	std::cout << "Clone type: " << clone->getType() << std::endl;
	delete clone;
	std::cout << "\n---- Test de MateriaSource ----" << std::endl;

	IMateriaSource *src = new MateriaSource();
	Character *squid = new Character("Squid");

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << "Squid's name: " << squid->getName() << std::endl;
	AMateria *iceMateria = src->createMateria("ice");
	squid->equip(iceMateria);
	AMateria *cureMateria = src->createMateria("cure");
	squid->equip(cureMateria);
	squid->equip(src->createMateria("ice"));
	squid->equip(src->createMateria("ice"));
	squid->useAll(*squid);
	std::cout << "\n---- Test unequip ----" << std::endl;

	squid->unequip(2);
	squid->unequip(2);
	squid->unequip(-2);
	squid->unequip(1);
	squid->unequip(4);
	squid->useAll(*squid);
	delete src;
	delete squid;
	test_unequip();
}

#include "unistd.h"
/**
 * @brief Main function
 */
int main()
{
	IMateriaSource *src = new MateriaSource();
	ICharacter *me = new Character("me");
	ICharacter *bob = new Character("bob");
	AMateria *tmp;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(10, *bob);

	
	delete bob;
	delete me;
	delete src;
	if (PRINT)
		d_main();
	return 0;
}