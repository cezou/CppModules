#pragma once
#include <sstream>

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

template <typename Container>
PmergeMe<Container>::PmergeMe(size_t nb_args, char **args) : _args(args), _nb_args(nb_args)
{
	g_comparison_count = 0;
	storeAndSort();
	printComparaisons(_nb_args);
	printIsSorted(this->_container);
}

template <typename Container>
void PmergeMe<Container>::store()
{
	int number;
	for (size_t i = 0; i < _nb_args; i++)
	{
		std::istringstream iss(_args[i]);	
		iss >> number;
		_container.push_back(IntC(number));
	}
}

template <typename Container>
void PmergeMe<Container>::storeAndSort()
{
	_start = clock();
	store();
	sort();
	_end = clock();
}

template <typename Container>
void PmergeMe<Container>::sort()
{
	r = 1;
	d_cout << GREEN B "Started pairing & sort, increasing recursion" R << std::endl;
	divideIntoPairsAndSort(r);
	d_cout << GREEN B "Started insertion sort, decreasing recursion" R << std::endl;
	initAndSort(r);
}

#include "sortPairSwapping.tpp"
#include "sortInsertion.tpp"
#include "containerUtils.tpp"
#include "printUtils.tpp"