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
	std::cout << "Time to process a range of " << size
			  << " elements with std::" << container << " : " B << color << time << R " us" << std::endl;
}


void printTime(PmergeMe<std::vector<IntC> > &vec, PmergeMe<std::deque<IntC> > &deque)
{
	bool greater =  vec.getTime() > deque.getTime();
	printTime(deque.getTime(), deque.getContainer().size(), "deque", 
				 greater ? GREEN : RED);
	printTime(vec.getTime(), vec.getContainer().size(), "vector", 
				!greater ? GREEN : RED);
}



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
