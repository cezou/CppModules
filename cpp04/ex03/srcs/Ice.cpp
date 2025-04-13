#include "Ice.hpp"

/**
 * @brief Default constructor for Ice
 */
Ice::Ice() : AMateria("ice")
{
	DEBUG_PRINT(GREEN << "Default Constructor called of Ice" << R << std::endl);
}

/**
 * @brief Copy constructor for Ice
 * @param copy The Ice to copy
 */
Ice::Ice(const Ice &copy) : AMateria(copy)
{
	DEBUG_PRINT(GREEN << "Copy Constructor called of Ice" << R << std::endl);
}

/**
 * @brief Destructor for Ice
 */
Ice::~Ice()
{
	DEBUG_PRINT(RED << "Destructor called of Ice" << R << std::endl);
}

/**
 * @brief Assignment operator for Ice
 * @param assign The Ice to assign from
 * @return Reference to the assigned Ice
 */
Ice &Ice::operator=(const Ice &assign)
{
	if (this != &assign)
		AMateria::operator=(assign);
	return *this;
}

/**
 * @brief Clone the Ice materia
 * @return Pointer to a new Ice instance
 */
AMateria *Ice::clone() const
{
	return new Ice(*this);
}

/**
 * @brief Use the Ice materia on a target
 * @param target The character to use the materia on
 */
void Ice::use(ICharacter &target)
{
	std::cout << BLUE << "* shoots an ice bolt at " YELLOW I << target.getName() << R BLUE " *" << R << std::endl;
}
