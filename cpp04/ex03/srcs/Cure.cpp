#include "Cure.hpp"

/**
 * @brief Default constructor for Cure
 */
Cure::Cure() : AMateria("cure")
{
	DEBUG_PRINT(GREEN << "Default Constructor called of Cure" << R << std::endl);
}

/**
 * @brief Copy constructor for Cure
 * @param copy The Cure to copy
 */
Cure::Cure(const Cure &copy) : AMateria(copy)
{
	DEBUG_PRINT(GREEN << "Copy Constructor called of Cure" << R << std::endl);
}

/**
 * @brief Destructor for Cure
 */
Cure::~Cure()
{
	DEBUG_PRINT(RED << "Destructor called of Cure" << R << std::endl);
}

/**
 * @brief Assignment operator for Cure
 * @param assign The Cure to assign from
 * @return Reference to the assigned Cure
 */
Cure &Cure::operator=(const Cure &assign)
{
	if (this != &assign)
		AMateria::operator=(assign);
	return *this;
}

/**
 * @brief Clone the Cure materia
 * @return Pointer to a new Cure instance
 */
AMateria *Cure::clone() const
{
	return new Cure(*this);
}

/**
 * @brief Use the Cure materia on a target
 * @param target The character to use the materia on
 */
void Cure::use(ICharacter &target)
{
	std::cout << GREEN << "* heals " YELLOW I << target.getName() << R GREEN "'s wounds *" << R << std::endl;
}
