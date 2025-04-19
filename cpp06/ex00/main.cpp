#include "includes/ScalarConverter.hpp"
#include "../../Utils.hpp"
#include <limits> // Include for numeric_limits
#include <iomanip> // Include for setprecision, fixed



#ifndef PRINT_LIMITS
	#define PRINT_LIMITS 0
#endif

int main(int ac, char **av)
{
#if PRINT_LIMITS
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "--- Numeric Limits (PRINT_LIMITS=1) ---" << std::endl;
	std::cout << "Int Min:    " << std::numeric_limits<int>::min() << std::endl;
	std::cout << "Int Max:    " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "Float Min:  " << -std::numeric_limits<float>::max() << std::endl;
	std::cout << "Float Max:  " << std::numeric_limits<float>::max() << std::endl;
	std::cout << "Double Min: " << -std::numeric_limits<double>::max() << std::endl;
	std::cout << "Double Max: " << std::numeric_limits<double>::max() << std::endl;
	std::cout << "---------------------------------------" << std::endl << std::endl;
#endif
	if (ac < 2)
		return (v(B "Usage: "  R RED << av[0] << B " <input1> <inputN>" R), 1);
	for (int i = 1; i < ac; ++i)
	{
		std::cout << B "Input: " R CYAN << av[i] << R << std::endl;
		ScalarConverter::convert(av[i]);
		if (i < ac - 1) 
			std::cout << std::endl;
	}
	return 0;
}