#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return v("Usage: ./btc <input_file>"), 1;
	try 
	{
		BitcoinExchange exchange(av[1]); 
	}
	catch (const LineException& e)
	{
		return v(e.what()), 1;
	}
	catch (const RedException& e)
	{
		return v(e.what()), 1;
	}
	catch (...)
	{
		return v("An unknown error occurred"), 1;
	}
}