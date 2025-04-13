#include "AMateria.hpp"
#include "Utils.hpp"

/**
 * @brief Default constructor for AMateria
 */
AMateria::AMateria() : _type("")
{
	DEBUG_PRINT(YELLOW << "Default Constructor called of AMateria" << R << std::endl);
}

/**
 * @brief Constructor with type for AMateria
 * @param type The type of the materia
 */
AMateria::AMateria(std::string const &type) : _type(type)
{
	DEBUG_PRINT(YELLOW << "Type Constructor called of AMateria with type: " << _type << R << std::endl);
}

/**
 * @brief Copy constructor for AMateria
 * @param copy The AMateria to copy
 */
AMateria::AMateria(const AMateria &copy) : _type(copy._type)
{
	DEBUG_PRINT(YELLOW << "Copy Constructor called of AMateria with type: " << _type << R << std::endl);
}

/**
 * @brief Destructor for AMateria
 */
AMateria::~AMateria()
{
	DEBUG_PRINT(RED << "Destructor called of AMateria with type: " << _type << R << std::endl);
}

/**
 * @brief Assignment operator for AMateria
 * @param assign The AMateria to assign from
 * @return Reference to the assigned AMateria
 */
AMateria &AMateria::operator=(const AMateria &assign)
{
	if (this != &assign)
	{
		_type = assign._type;
		DEBUG_PRINT(YELLOW << "Assignment operator called of AMateria, type set to: " << _type << R << std::endl);
	}
	return *this;
}

/**
 * @brief Get the type of the AMateria
 * @return The type as a const reference to a string
 */
std::string const &AMateria::getType() const
{
	return _type;
}

/**
 * @brief Use the materia on a target
 * @param target The character to use the materia on
 */
void AMateria::use(ICharacter &target)
{
	DEBUG_PRINT("\e[0;33mAMateria use function called\e[0m" << std::endl);
	DEBUG_PRINT("\e[0;33m" << target.getName() << " is the target of AMateria\e[0m" << std::endl);
}
