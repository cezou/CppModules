#include "Base.hpp"
#include <cstdlib>   // For rand()
#include <exception> // For std::exception
#include <iostream>  // For std::cout, std::endl

/**
 * @brief Virtual destructor for the Base class.
 */
Base::~Base()
{
}

/**
 * @brief Randomly instantiates A, B, or C.
 * @return A Base pointer to the newly created instance.
 */
Base * generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
}

#define IDENTIFY "Identified "
#define IDENTIFY_REF IDENTIFY GREEN BOLD "&" RESET " : "
#define IDENTIFY_PTR IDENTIFY MAGENTA BOLD "*" RESET " : "
/**
 * @brief Identifies the actual type of the object pointed to by p.
 * @param p Pointer to a Base object.
 */
void identify(Base* p)
{
	if (!p)
		return (v("Pointer is NULL"));
	if (dynamic_cast<A*>(p))
		std::cout << IDENTIFY_PTR "A";
	else if (dynamic_cast<B*>(p))
		std::cout << IDENTIFY_PTR "B";
	else if (dynamic_cast<C*>(p))
		std::cout << IDENTIFY_PTR "C";
	else
		std::cout << IDENTIFY_PTR "Unknown type";
	std::cout << std::endl;
}

/**
 * @brief Identifies the actual type of the object referenced by p.
 * @param p Reference to a Base object.
 * Using a pointer inside this function is forbidden.
 * Including the typeinfo header is forbidden
 */
void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << IDENTIFY_REF "A" << std::endl;
		return;
	}
	catch (const std::exception& e) { (void)e; }
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << IDENTIFY_REF "B" << std::endl;
		return;
	}
	catch (const std::exception& e) { (void)e; }
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << IDENTIFY_REF "C" << std::endl;
		return;
	}
	catch (const std::exception& e) { (void)e; }
	std::cout << IDENTIFY_REF "Unknown type" << std::endl;
}
