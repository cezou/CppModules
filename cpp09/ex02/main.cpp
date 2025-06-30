#include "PmergeMe.hpp"

size_t g_comparison_count = 0;

/**
 * @brief Ex02 PmergeMe, containers used: std::deque and std::vector
 */
int main(int ac, char **av)
{
	if (ac < 2)
		return v("Usage: ./PMergeMe positive integer sequence"), 1;
	try 
	{
		PmergeMe sort(ac, av + 1);
		std::cout << "Nombre de comparaisons: " << g_comparison_count << std::endl;
		if (is_sorted(sort.getDeque()))
			std::cout << GREEN B "La liste finie bien triée" R << std::endl;
		else
			std::cout << RED B "La liste ne finie pas triée" R << std::endl;
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
