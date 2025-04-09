#include "AMateria.hpp"

// Constructors
AMateria::AMateria()
{
	std::cout << "\e[0;33mDefault Constructor called of AMateria\e[0m" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	(void)copy;
	std::cout << "\e[0;33mCopy Constructor called of AMateria\e[0m" << std::endl;
}

// Destructor
AMateria::~AMateria()
{
	std::cout << "\e[0;31mDestructor called of AMateria\e[0m" << std::endl;
}

// Operators
AMateria &AMateria::operator=(const AMateria &assign)
{
	(void)assign;
	return *this;
}


// Member functions

// squid norm
/**
 * @brief Returns the materia type
 */
std::string const &AMateria::getType() const
{
	return _type;
}

/**
 * @brief Use the materia on the target
 * @param target The target to use the materia on
 */
void AMateria::use(ICharacter &target)
{
	std::cout << "\e[0;33mAMateria use function called\e[0m" << std::endl;
	std::cout << "\e[0;33m" << target.getName() << " is the target of AMateria\e[0m" << std::endl;
}

