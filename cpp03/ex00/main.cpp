#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Pierre Chabrier");
	ClapTrap b("Sylvain Lyve");

	a.displayStats();
	b.displayStats();

	a.attack("Sylvain Lyve");
	b.takeDamage(1);
	b.displayStats();

	b.beRepaired(1);
	b.displayStats();

	b.takeDamage(10);
	b.displayStats();

	b.beRepaired(1);
	b.displayStats();

	a.attack("Sylvain Lyve");
	a.attack("Sylvain Lyve");
	a.attack("Sylvain Lyve");
	a.attack("Sylvain Lyve");
	a.attack("Sylvain Lyve");
	a.attack("Sylvain Lyve");
	a.attack("Sylvain Lyve");
	a.attack("Sylvain Lyve");
	a.attack("Sylvain Lyve");
	a.displayStats();

	a.attack("Sylvain Lyve");
	a.beRepaired(1);

	return 0;
}