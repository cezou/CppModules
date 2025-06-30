# pragma once

# include <iostream>
# include <string>
# include "../../utils.hpp"
# include "IntC.hpp"
# include "Jacobsthal.hpp"
# include "printUtils.hpp"
# include <cstdio>
# include "algorithm"
# include <deque>
# include <vector>

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
	
	void divideIntoPairsAndSort(Pair &deque, int &r);
	void initAndSort(Pair &deque, int &r);
	void initPairs(PairContainer &pairs, const Pair &deque);
	void initMainandPend(PairContainer &main,	Pend &pend, PairContainer &nonParticipating, const Pair &deque);
	void insertPendIntoMain(PairContainer &main, Pend &pend);


	void insertUpdatingPend(PendIterator &it, PairContainer &main, Pend &pend, size_t &shift);
	void binaryInsert(PairTarget &src, PairContainer &sorted, Pend &pend);
	void updatePendTargets(Pend &pend, size_t start_increase);
	std::deque<IntC> getDeque() {return _deque;};
	std::vector<IntC> getVec() {return _vec;};
	int r;

private:
	std::deque<IntC> _deque;
	std::vector<IntC> _vec;

	char **_args;
	size_t _nb_args;
	clock_t _start, _end;

	// Not used but respects the rule of 5
	PmergeMe() {};
	PmergeMe(const PmergeMe &c) {(void)c;};
	PmergeMe & operator=(const PmergeMe &a) {(void)a; return *this;};

};


	
template <typename Container, typename PairContainer>
void updateContainer(Container& container, const PairContainer& pairs)
{
    container.clear();
    for (typename PairContainer::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
        for (typename Container::const_iterator elem = it->begin(); elem != it->end(); ++elem)
            container.push_back(*elem);
}

template <typename Container, typename PairContainer>
void updateContainer(Container& original, const PairContainer& main,  const PairContainer& nonParticipating)
{
	original.clear();
	for (typename PairContainer::const_iterator it = main.begin(); it != main.end(); ++it)
		for (typename Container::const_iterator elem = it->begin(); elem != it->end(); ++elem)
			original.push_back(*elem);
	for (typename PairContainer::const_iterator it = nonParticipating.begin(); it != nonParticipating.end(); ++it)
		for (typename Container::const_iterator elem = it->begin(); elem != it->end(); ++elem)
			original.push_back(*elem);
}

size_t binarySearch(const PairContainer& sorted, IntC elem, size_t start, size_t end);