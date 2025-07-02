# pragma once

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include "../utils.hpp"
#include "PmergeMe.hpp"
#include "IntC.hpp"
#include <algorithm>
#include <cstdio>

extern size_t g_comparison_count;

// Container traits to define nested container types
template <typename Container>
struct ContainerTraits;

template <typename T>
struct ContainerTraits<std::deque<T> > {
	typedef std::deque<T> Pair;
	typedef std::deque<std::deque<T> > PairContainer;
	typedef typename PairContainer::iterator PairIterator;
	typedef std::pair<std::deque<T>, size_t> PairTarget;
	typedef std::deque<PairTarget> Pend;
	typedef typename Pend::iterator PendIterator;
};

template <typename T>
struct ContainerTraits<std::vector<T> > {
	typedef std::vector<T> Pair;
	typedef std::vector<std::vector<T> > PairContainer;
	typedef typename PairContainer::iterator PairIterator;
	typedef std::pair<std::vector<T>, size_t> PairTarget;
	typedef std::vector<PairTarget> Pend;
	typedef typename Pend::iterator PendIterator;
};


void printTime(double time, size_t size, std::string container, std::string color);


template <typename PairContainer>
bool is_sorted(const PairContainer& container)
{
	return std::adjacent_find(container.begin(), container.end(), std::greater<int>()) == container.end();
}

template <typename PairContainer>
void printIsSorted(const PairContainer& container)
{
	if (is_sorted(container))
		std::cout << GREEN B "La liste est triée" R << std::endl;
	else
		std::cout << RED B "La liste n'est pas triée" R << std::endl;
}
