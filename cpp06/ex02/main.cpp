#include "Base.hpp"

#define ITERATIONS 10

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < ITERATIONS; ++i)
	{
		std::cout << BOLD "-- Iteration n. " CYAN << i << WHITE " --" R << std::endl;
		Base *base = generate();
		identify(base);
		identify(*base);
		deleteAndNull(base);
		if (i < ITERATIONS - 1)
			std::cout << std::endl;
	}
}
