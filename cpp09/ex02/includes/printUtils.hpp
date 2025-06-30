# pragma once

#include <iostream>
#include <string>
#include <deque>
#include "../../utils.hpp"
#include "IntC.hpp"
#include <algorithm>


extern size_t g_comparison_count;

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

template <typename PairContainer>
bool is_sorted(const PairContainer& container)
{
	return std::adjacent_find(container.begin(), container.end(), std::greater<int>()) == container.end();
}