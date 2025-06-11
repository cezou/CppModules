#include "RPN.hpp"

/**
 * @brief Ex01 RPN, container used: std::stack
 */
int main(int ac, char **av)
{
	if (ac != 2)
		return v("Usage: ./RPN \"IPM expression\""), 1;
	try 
	{
		RPN calculate((std::string(av[1])));
	}
	catch (const std::exception& e)
	{
		return v(e.what()), 1;
	}
	catch (...)
	{
		return v("An unknown error occurred"), 1;
	}
}