#include "BitcoinExchange.hpp"

/**
 * @brief Ex00 btc, container used: std::map
 */
int main(int ac, char **av)
{
	if (ac != 2)
		return v("Usage: ./btc <input_file>"), 1;
	try 
	{
		BitcoinExchange exchange(av[1]); 
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