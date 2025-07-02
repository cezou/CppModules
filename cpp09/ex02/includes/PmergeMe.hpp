# pragma once

# include <iostream>
# include <string>
# include "../utils.hpp"
# include "IntC.hpp"
# include "Jacobsthal.hpp"
# include "printUtils.hpp"
# include "utils.hpp"
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
	void initMainandPend(PairContainer &main, Pend &pend, PairContainer &nonParticipating,
							const Pair &deque);
	void insertPendIntoMain(PairContainer &main, Pend &pend);
	void insertUpdatingPend(PendIterator &it, PairContainer &main, Pend &pend, size_t &shift);
	void binaryInsert(PairTarget &src, PairContainer &sorted, Pend &pend);
	void updatePendTargets(Pend &pend, size_t start_increase);
	
	// Print functions
	void print(const PairContainer& pairs);
	void print(const PairContainer& original, const Pend& pend, const PairContainer& main,
				const PairContainer& nonParti, size_t recursion);
	void print(const Pend &p);
	void print(const Pair &container, const std::string &color);
	void print(const PairContainer &c, const std::string &color);
	void print(const PairContainer &c, const std::string &color, char letter);
	void print(typename PairContainer::const_iterator elemIt, const std::string &color,
				char letter, size_t i);
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

inline void printTime(double time, size_t size, std::string container, std::string color)
{
	std::cout << "Time to process a range of " << size
			  << " elements with std::" << container << " : " B << color << time << R " us" << std::endl;
}

inline void printTime(PmergeMe<std::vector<IntC> > &vec, PmergeMe<std::deque<IntC> > &deque)
{
	bool greater =  vec.getTime() > deque.getTime();
	printTime(deque.getTime(), deque.getContainer().size(), "deque", 
				 greater ? GREEN : RED);
	printTime(vec.getTime(), vec.getContainer().size(), "vector", 
				!greater ? GREEN : RED);
}

#include "../srcs/PmergeMe.tpp"