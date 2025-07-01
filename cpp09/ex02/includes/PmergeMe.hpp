# pragma once

# include <iostream>
# include <string>
# include "../utils.hpp"
# include "IntC.hpp"
# include "Jacobsthal.hpp"
# include "printUtils.hpp"
# include <cstdio>
# include "algorithm"
# include <deque>
# include <vector>
# include <ctime>
#include <math.h>

class IntC;


template <typename Container>
class PmergeMe
{
public:
	// Use traits to define the correct types
	typedef typename ContainerTraits<Container>::Pair Pair;
	typedef typename ContainerTraits<Container>::PairContainer PairContainer;
	typedef typename ContainerTraits<Container>::PairIterator PairIterator;
	typedef typename ContainerTraits<Container>::PairTarget PairTarget;
	typedef typename ContainerTraits<Container>::Pend Pend;
	typedef typename ContainerTraits<Container>::PendIterator PendIterator;

	PmergeMe(size_t nb_args, char **args);
	~PmergeMe() {};

	void store();
	void storeAndSort();
	void sort();
	
	void divideIntoPairsAndSort(int &r);
	void initAndSort(int &r);
	void initPairs(PairContainer &pairs, const Pair &deque);
	void initMainandPend(PairContainer &main, Pend &pend, PairContainer &nonParticipating, const Pair &deque);
	void insertPendIntoMain(PairContainer &main, Pend &pend);
	void insertUpdatingPend(PendIterator &it, PairContainer &main, Pend &pend, size_t &shift);
	void binaryInsert(PairTarget &src, PairContainer &sorted, Pend &pend);
	void updatePendTargets(Pend &pend, size_t start_increase);
	
	// Print functions
	void print(const PairContainer& pairs);
	void print(const PairContainer& original, const Pend& pend, const PairContainer& main, const PairContainer& nonParti, size_t recursion);
	void print(const Pend &p);
	void print(const Pair &container, const std::string &color);
	void print(const PairContainer &c, const std::string &color);
	void print(const PairContainer &c, const std::string &color, char letter);
	void print(typename PairContainer::const_iterator elemIt, const std::string &color, char letter, size_t i);
	void printBeforeInsert(PairTarget &src, PairContainer &sorted);
	
	
	Container getContainer() { return _container; }
	double getTime() { return static_cast<double>(_end - _start) / CLOCKS_PER_SEC * 1000000; }
	
	int r;

private:
	Container _container;
	char **_args;
	size_t _nb_args;
	clock_t _start, _end;

	// Not used but respects the rule of 5
	PmergeMe() {};
	PmergeMe(const PmergeMe &c) {(void)c;};
	PmergeMe & operator=(const PmergeMe &a) {(void)a; return *this;};
};


template <typename Container, typename PairContainer>
void updateContainer(Container& container, const PairContainer& pairs);

template <typename Container, typename PairContainer>
void updateContainer(Container& original, const PairContainer& main, const PairContainer& nonParticipating);

template <typename PairContainer>
size_t binarySearch(const PairContainer& sorted, IntC elem, size_t start, size_t end);

void checkArgs(size_t nb_args, char **args);


#include "../srcs/PmergeMe.tpp"