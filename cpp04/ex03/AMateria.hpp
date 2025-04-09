#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string _type;

public:
	// Constructors
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &copy);
	~AMateria();

	// Operators
	AMateria &operator=(const AMateria &assign);

	// Member functions
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif