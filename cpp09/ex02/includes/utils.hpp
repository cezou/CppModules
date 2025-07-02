# pragma once
#include "PmergeMe.hpp"
#include <math.h>

void checkArgs(size_t nb_args, char **args)
{
	std::vector<int> dupchecker;
	for (size_t i = 0; i < nb_args; i++)
	{
		std::istringstream iss(args[i]);	
		int number;
		if (!(iss >> number) || iss.peek() != EOF)
			throw RedException("Invalid Number: " B + std::string(args[i]) + R);

		if (std::find(dupchecker.begin(), dupchecker.end(), number) != dupchecker.end())
			throw RedException("Duplicate number: " B + std::string(args[i]) + R);
		dupchecker.push_back(number);
	}
	if (is_sorted(dupchecker))
		throw RedException("List already sorted");
}

size_t F(size_t n)
{
    int sum = 0;
    for (size_t k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

void printComparaisons(size_t nb_args)
{
	size_t max_comps = F(nb_args);
	std::string color = (g_comparison_count > max_comps) ? RED : GREEN;

	std::cout << "Nombre de comparaisons: " B << color <<  g_comparison_count << R 
			  << " (max: " B << max_comps << R ")" << std::endl;
}

