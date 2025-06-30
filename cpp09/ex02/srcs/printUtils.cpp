#include "../includes/printUtils.hpp"
#include <iostream>

void printTime(double time, size_t size, std::string container, std::string color)
{
	d_cout << "Time to process a range of " << size
			  << " elements with std::" << container << " : " B << color << time << R " us" << std::endl;
}

void print(PairContainer pairs)
{
	d_cout << "Recursion: " << pairs[0].size() / 2 << std::endl;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (i % 2 == 0)
			print(pairs[i], RED);
		else
			print(pairs[i], GREEN);
		d_cout << " ";
	}
	d_cout << std::endl;
}

void print(PairContainer original, Pend pend, PairContainer main, PairContainer nonParti, size_t recursion)
{
	d_cout << std::endl << B "Before init: " R;
	PairContainer::const_iterator elemIt;
	size_t i;

	for (elemIt = original.begin(), i = 0; elemIt != original.end(); ++elemIt, i++)
	{
		if ((*elemIt).size() != recursion)
			print(*elemIt, WHITE);
		else if (i % 2 == 0)
			print(elemIt, RED, 'b', i / 2 + 1);
		else
			print(elemIt, GREEN, 'a', i / 2 + 1);
	}
	d_cout << std::endl << B "Main: " R;
	print(main, GREEN, 'a');
	d_cout << std::endl << B "Pend: " R;
	print(pend);
	d_cout << std::endl << B "Non Participating: " R;
	print(nonParti, WHITE);
	d_cout << std::endl;
}

template <typename Container>
void print(const Container &container, const std::string &color)
{
	d_cout << color << "[";
	typename Container::const_iterator elemIt;
	for (elemIt = container.begin(); elemIt != container.end(); ++elemIt)
	{
		if (elemIt != container.begin())
			d_cout << " ";
		d_cout << *elemIt;
	}
	d_cout << "] " RESET;
}

void print(const PairContainer &c, const std::string &color)
{
	PairContainer::const_iterator elemIt;
	for (elemIt = c.begin(); elemIt != c.end(); ++elemIt)
	{
		if (elemIt != c.begin())
			d_cout << " ";
		print(*elemIt, color);
	}
}



void print(PairContainer::const_iterator elemIt, const std::string &color, char letter, size_t i)
{
	d_cout << letter << i;
	print(*elemIt, color);
}


void print(const PairContainer &c, const std::string &color, char letter)
{
	PairContainer::const_iterator elemIt;
	size_t i;

	if (letter == 'b')
		for (elemIt = c.begin(), i = 2; elemIt != c.end(); ++elemIt, i++)
			print(elemIt, color, 'b', i);
	else if (letter == 'a')
		for (elemIt = c.begin(), i = 0; elemIt != c.end(); ++elemIt, i++)
			if (i == 0)
				print(elemIt, RED, 'b', 1);
			else
				print(elemIt, color, 'a', i);
	else
		print(c, color);
}

void print(const Pend &p)
{
	Pend::const_iterator elemIt;
	size_t i;

	for (elemIt = p.begin(), i = 2; elemIt != p.end(); ++elemIt, i++)
	{
		if (elemIt == p.end())
			break;
		if (elemIt != p.begin())
			d_cout << " ";
		d_cout << "b" << i;
		print(elemIt->first, RED);
		d_cout << " (target: " PINK "a" << elemIt->second << R ")" << std::endl;
	}
}


void printBeforeInsert(PairTarget &src, PairContainer &sorted)
{
	d_cout 	<< "searching index for " B CYAN << src.first.back() << R " between 0 and " << src.second << std::endl
				<<  "Target is " B PINK << sorted[src.second].back() << R << std::endl;
	for (PairIterator it = sorted.begin(); it != sorted.end(); it++)
		d_cout << it->back() << " ";
	d_cout << std::endl;
}
