# pragma once

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include "../utils.hpp"
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

// Legacy typedefs for backward compatibility (using deque)
typedef std::deque<IntC> Pair;
typedef std::deque<Pair> PairContainer;
typedef PairContainer::iterator PairIterator;
typedef std::pair<Pair, size_t> PairTarget;
typedef std::deque<PairTarget> Pend;
typedef Pend::iterator PendIterator;


void printTime(double time, size_t size, std::string container, std::string color);

void print(PairContainer pairs);
void print(PairContainer original, Pend pend, PairContainer main, PairContainer nonParti, size_t recursion);
template <typename Container>
void print(const Container &container, const std::string &color);
void print(const PairContainer &c, const std::string &color, char letter);
void print(const PairContainer &c, const std::string &color);
void print(PairContainer::const_iterator elemIt, const std::string &color, char letter, size_t i);
void print(const Pend &p);
void printBeforeInsert(PairTarget &src, PairContainer &sorted);

// Template versions for generic containers
template <typename Container>
void print(const typename ContainerTraits<Container>::PairContainer& pairs);

template <typename Container>
void print(const typename ContainerTraits<Container>::PairContainer& original, 
          const typename ContainerTraits<Container>::Pend& pend, 
          const typename ContainerTraits<Container>::PairContainer& main, 
          const typename ContainerTraits<Container>::PairContainer& nonParti, 
          size_t recursion);

template <typename Container>
void print(const typename ContainerTraits<Container>::PairContainer &c, const std::string &color, char letter);

template <typename Container>
void print(typename ContainerTraits<Container>::PairContainer::const_iterator elemIt, const std::string &color, char letter, size_t i);

template <typename Container>
void print(const typename ContainerTraits<Container>::Pend &p);

template <typename Container>
void printBeforeInsert(typename ContainerTraits<Container>::PairTarget &src, typename ContainerTraits<Container>::PairContainer &sorted);

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
