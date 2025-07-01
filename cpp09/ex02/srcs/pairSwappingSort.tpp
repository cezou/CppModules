#pragma once

template <typename Container>
void PmergeMe<Container>::divideIntoPairsAndSort(int &r)
{
	while (r * 2 < (int)_container.size())
	{
		PairContainer pairs;
		for (size_t i = 0; i < _container.size(); i += r)
		{
			Pair pair; 
			for (int j = 0; j < r && (int)(i + j) < (int)_container.size(); j++)
				pair.push_back(_container[i + j]);
			pairs.push_back(pair);
		}
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
