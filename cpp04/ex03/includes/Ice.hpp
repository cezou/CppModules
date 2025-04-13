#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "Utils.hpp"
#include "ICharacter.hpp"

class ICharacter;
class AMateria;

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &copy);
	virtual ~Ice();

	Ice &operator=(const Ice &assign);

	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif
