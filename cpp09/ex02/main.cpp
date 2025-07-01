#include "PmergeMe.hpp"

size_t g_comparison_count = 0;

void checkArgs(size_t nb_args, char **args)
{
	std::vector<int> dupchecker;
	for (size_t i = 0; i < nb_args; i++)
	{
		std::istringstream iss(args[i]);	
		int number;
		if (!(iss >> number) || iss.peek() != EOF)
			throw RedException("Invalid Number: " B + std::string(args[i]) + R);
		if (number < 0 )
			throw RedException("Negative numbers not authorized: "  B + std::string(args[i]) + R);
		if (std::find(dupchecker.begin(), dupchecker.end(), number) != dupchecker.end())
			throw RedException("Duplicate number: " B + std::string(args[i]) + R);
		dupchecker.push_back(number);
	}
	if (is_sorted(dupchecker))
		throw RedException("List already sorted");
}

void printTime(double time, size_t size, std::string container, std::string color)
{
	d_cout << "Time to process a range of " << size
			  << " elements with std::" << container << " : " B << color << time << R " us" << std::endl;
}

/**
 * @brief Ex02 PmergeMe, containers used: std::deque and std::vector
 */
int main(int ac, char **av)
{
	if (ac < 2)
		return v("Usage: ./PMergeMe positive integer sequence"), 1;
	try 
	{
		checkArgs(ac - 1, av + 1);
		PmergeMe<std::deque<IntC> > dequeSort(ac - 1, av + 1);
		PmergeMe<std::vector<IntC> > vectorSort(ac - 1, av + 1);
		
		std::cout << "Nombre de comparaisons: " << g_comparison_count << std::endl;
		
		if (is_sorted(dequeSort.getContainer()))
			std::cout << GREEN B "La liste deque finie bien triée" R << std::endl;
		else
			std::cout << RED B "La liste deque ne finie pas triée" R << std::endl;
			
		if (is_sorted(vectorSort.getContainer()))
			std::cout << GREEN B "La liste vector finie bien triée" R << std::endl;
		else
			std::cout << RED B "La liste vector ne finie pas triée" R << std::endl;
			
		printTime(dequeSort.getTime(), dequeSort.getContainer().size(), "deque", 
				 vectorSort.getTime() > dequeSort.getTime() ? RED : GREEN);
		printTime(vectorSort.getTime(), vectorSort.getContainer().size(), "vector", 
				 dequeSort.getTime() > vectorSort.getTime() ? RED : GREEN);
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
