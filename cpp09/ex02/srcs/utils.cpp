#include "PmergeMe.hpp"
#include <iomanip>

DebugStream d_cout;

void checkArgs(size_t nb_args, char **args)
{
	std::vector<int> dupchecker;
	for (size_t i = 0; i < nb_args; i++)
	{
		std::istringstream iss(args[i]);	
		int number;
		if (!(iss >> number) || iss.peek() != EOF)
			throw RedException("Invalid Number: " B + std::string(args[i]) + R);
		if (number < 0)
			throw RedException("Negative number: " B + std::string(args[i]) + R);
		if (std::find(dupchecker.begin(), dupchecker.end(), number) != dupchecker.end())
			throw RedException("Duplicate number: " B + std::string(args[i]) + R);
		dupchecker.push_back(number);
	}
	if (is_sorted(dupchecker))
		throw RedException("List already sorted");
}

static size_t F(size_t n)
{
	int sum = 0;
	for (size_t k = 1; k <= n; ++k)
	{
		double value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
	}
	return sum;
}

void printComparaisons(size_t nb_args)
{
	size_t max_comps = F(nb_args);

	std::cout << "Nombre de comparaisons: " B << (g_comparison_count > max_comps ? RED : GREEN) 
			  <<  g_comparison_count << R << " (max: " B << max_comps << R ")" << std::endl;
}

static void printTime(double time, size_t size, std::string container, std::string color)
{
	std::cout << "Time to process a range of " << size
			  << " elements with std::" << container << " : " B << color << std::fixed << std::setprecision(3) << time << R " us" << std::endl;
}

void printTime(PmergeMe<std::vector<IntC> > &vec, PmergeMe<std::deque<IntC> > &deque)
{
	std::string deque_color, vec_color;
	vec.getTime() > deque.getTime() ?
		(deque_color = GREEN, vec_color = RED) :
		(vec_color = GREEN, deque_color = RED);

	printTime(deque.getTime(), deque.getContainer().size(), "deque", deque_color);
	printTime(vec.getTime(), vec.getContainer().size(), "vector", vec_color);
}
