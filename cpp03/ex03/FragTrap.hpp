#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(const std::string name);
	virtual ~FragTrap();
	void highFivesGuys();
};

#endif
