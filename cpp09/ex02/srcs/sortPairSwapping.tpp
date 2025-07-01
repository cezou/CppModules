#pragma once
#include "PmergeMe.hpp"

template <typename Container>
void PmergeMe<Container>::divideIntoPairsAndSort(int &r)
{
	while (r * 2 < (int)_container.size())
	{
		PairContainer pairs;
		initPairs(pairs, _container);
		print(pairs);
		for (PairIterator it = pairs.begin(); it != pairs.end() && (it + 1) != pairs.end(); it += 2)
			if ((int)(it->size() + (it + 1)->size()) == r * 2)
				if (it->back() > (it + 1)->back())
					std::swap(*it, *(it + 1));
		print(pairs);
		updateContainer(_container, pairs);
		r*=2;
	}
}
