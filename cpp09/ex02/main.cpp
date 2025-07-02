#include "PmergeMe.hpp"

size_t g_comparison_count = 0;

/**
 * @brief Ex02 PmergeMe, containers used: std::deque and std::vector
 */
int main(int ac, char **av)
{
	if (ac < 2)
		return v("Usage: ./PMergeMe positive integer sequence"), 1;
	ac--; av++;
	try 
	{
		checkArgs(ac, av);
		PmergeMe<std::deque<IntC> > dequeSort(ac, av);
		PmergeMe<std::vector<IntC> > vectorSort(ac, av);
		printTime(vectorSort, dequeSort);
	}
	catch (const std::exception& e)
		{ return v(e.what()), 1; }
	catch (...)
		{ return v("An unknown error occurred"), 1; }
}
