#include "PmergeMe.hpp"

/**
 * @brief Ex02 PmergeMe, containers used: std::deque and std::list
 */
int main(int ac, char **av)
{
	if (ac < 2)
		return v("Usage: ./PMergeMe positive integer sequence"), 1;
	try 
	{
		PmergeMe sort(ac, av + 1);
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