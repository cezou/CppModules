#include "PmergeMe.hpp"

/**
 *  - 1: Divide into pairs and sort it, x2 size of pairs and sort by last element. 
 *      When recursion level * 2 > size of list, we start the next step.
 */
void PmergeMe::divideIntoPairsAndSort(Pair &deque, int &r)
{
	while (r * 2 < (int)deque.size())
	{
		PairContainer pairs;
		for (size_t i = 0; i < deque.size(); i += r)
		{
			Pair pair; 
			for (size_t j = 0; j < r && (i + j) < deque.size(); j++)
				pair.push_back(deque[i + j]);
			pairs.push_back(pair);
		}
		print(pairs);
		for (PairIterator it = pairs.begin(); it != pairs.end() && (it + 1) != pairs.end(); it += 2)
			if (it->size() + (it + 1)->size() == r * 2)
				if (it->back() > (it + 1)->back())
					std::swap(*it, *(it + 1));
		print(pairs);
		updateContainer(deque, pairs);
		r*=2;
	}
}

