#include "../includes/printUtils.hpp"
#include <iostream>


void printTime(double time, size_t size, std::string container, std::string color)
{
	std::cout 	<< "Time to process a range of " << size
				<< " elements with std::" << container << " : " B << color << time << R " us" << std::endl;
}

void print(PairContainer pairs)
{
	std::cout << "Recursion: " << pairs[0].size() /2 << std::endl;
	for (size_t i = 0; i < pairs.size(); i++)
	{
			if (i % 2 == 0)
				print(pairs[i], RED);
			else
				print(pairs[i], GREEN);
		std::cout << " ";
	}
	std::cout << std::endl;
}

void print(PairContainer original, PairContainer pend, PairContainer main, PairContainer nonParti, size_t recursion)
{
	std::cout << "Recursion: " << recursion/2<< std::endl;
	for (size_t i = 0; i < original.size(); i++)
		if (original[i].size() != recursion)
				print(original[i], WHITE);
		else if (i % 2 == 1)
				print(original[i], GREEN);
		else
				print(original[i], RED);
	std::cout << std::endl;

	print(main[0], RED);
	for (size_t i = 1; i < main.size(); i++)
		print(main[i], GREEN);
	std::cout << " |  ";
	for (size_t i = 0; i < pend.size(); i++)
		print(pend[i], RED);
	std::cout << " |  ";
	for (size_t i = 0; i < nonParti.size(); i++)
		print(nonParti[i], WHITE);
	std::cout << std::endl;
}

// print_container(std::deque<IntC> &container, const std::string &color)
// Je veux un container de IntC, template, qui peut etre soit std::deque ou std::list
template <typename Container>
void print(const Container &container, const std::string &color)
{
	std::cout << color << "[";
	for (std::deque<IntC>::const_iterator elem_it = container.begin(); elem_it != container.end(); ++elem_it)
	{
		if (elem_it != container.begin())
			std::cout << " ";
		std::cout << *elem_it;
	}
	std::cout << "] " RESET;
}

