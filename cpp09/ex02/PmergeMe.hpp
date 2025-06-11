# pragma once

# include <iostream>
# include <string>
# include "../utils.hpp"
# include <cstdio>
# include "algorithm"
# include <deque>
# include <list>

class PmergeMe
{
public:
	PmergeMe(size_t nb_args, char **args);
	~PmergeMe() {};

	void checkArgs();
	void storeAndSortList();
	void storeAndSortDeque();

	template <typename Container>
	void store(Container& container);

	void sort(std::list<int> l);
	double stopwatch(void (PmergeMe::*fun)());
	void printTime(double time, size_t size, std::string container, std::string color);
private:
	std::deque<int> _deque;
	std::list<int> _list;

	char **_args;
	size_t _nb_args;
	clock_t _start, _end;

	// Not used but respects the rule of 5
	PmergeMe() {};
	PmergeMe(const PmergeMe &c) {(void)c;};
	PmergeMe & operator=(const PmergeMe &a) {(void)a; return *this;};

};
