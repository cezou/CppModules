#pragma once

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
	clock_gettime(CLOCK_MONOTONIC, &_start);
	store();
	sort();
	clock_gettime(CLOCK_MONOTONIC, &_end);
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