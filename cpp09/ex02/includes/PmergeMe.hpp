# pragma once

# include <iostream>
# include <string>
# include "../../utils.hpp"
# include "IntC.hpp"
# include "Jacobsthal.hpp"
#include "printUtils.hpp"
# include <cstdio>
# include "algorithm"
# include <deque>
# include <list>

class IntC;

class PmergeMe
{
public:
	PmergeMe(size_t nb_args, char **args);

	~PmergeMe() {};

	void checkArgs();

	template <typename Container>
	void store(Container& container);
	template <typename Container>
	void storeAndSort(Container& container);
	template <typename Container>
	void sort(Container& container);
	
	void divideIntoPairsAndSort(std::deque<IntC> &deque, int &r);
	void initAndSort(std::deque<IntC> &deque, int &r);
	void binaryInsert(PairWithIndex &src, PairContainer &sorted);
private:
	std::deque<IntC> _deque;
	std::list<IntC> _list;

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

size_t binarySearch(const PairContainer& sorted, IntC elem, size_t start, size_t end);