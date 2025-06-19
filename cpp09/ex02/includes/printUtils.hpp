# pragma once

#include <iostream>
#include <string>
#include <deque>
#include "../utils.hpp"
#include "IntC.hpp"

extern size_t g_comparison_count;
typedef std::deque<IntC> Pair;
typedef std::deque<Pair> PairContainer;
typedef PairContainer::iterator PairIterator;


void printTime(double time, size_t size, std::string container, std::string color);
void print(PairContainer pairs);
void print(PairContainer original, PairContainer pend, PairContainer main, PairContainer nonParti, size_t recursion);
template <typename Container>
void print(const Container &container, const std::string &color);