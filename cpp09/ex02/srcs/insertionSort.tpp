#pragma once

template <typename Container>
void PmergeMe<Container>::initAndSort(int &r)
{
	r /= 2;
	while (r > 0)
	{
		d_cout << std::endl << "Pairs size: " BOLD << r << R << std::endl;
		PairContainer main;
		Pend pend;
		PairContainer nonParticipating;
		initMainandPend(main, pend, nonParticipating, _container);
		insertPendIntoMain(main, pend);
		updateContainer(_container, main, nonParticipating);
		r /= 2;
	}
}

template <typename Container>
void PmergeMe<Container>::initPairs(PairContainer &pairs, const Pair &deque)
{
	for (size_t i = 0; i < deque.size(); i += r)
	{
		Pair pair; 
		for (int j = 0; j < r && (int)(i + j) < (int)deque.size(); j++)
			pair.push_back(deque[i + j]);
		pairs.push_back(pair);
	}
}

template <typename Container>
void PmergeMe<Container>::initMainandPend(PairContainer &main, Pend &pend, PairContainer &nonParticipating, const Pair &deque)
{
	PairContainer pairs;
	initPairs(pairs, deque);
	main.push_back(*pairs.begin());
	size_t i = 0; PairIterator it;
	for (it = pairs.begin() + 1, i = 0; it != pairs.end() && (it + 1) != pairs.end(); it++, i++)
	{
		if ((int)(*it).size() == r)
			main.push_back(*it++);
		else
		{
			nonParticipating.push_back(*it++);
			break;
		}
		if ((int)(*it).size() == r)
			pend.push_back(std::make_pair(*it, i + 2));
		else
			nonParticipating.push_back(*it);
	}
	if (r == 1 && !(pairs.size() % 2))
		main.push_back(pairs.back());
	else if (!(pairs.size() % 2))
		nonParticipating.push_back(pairs.back());
	print(pairs, pend, main, nonParticipating, r);
}

template <typename Container>
void PmergeMe<Container>::insertPendIntoMain(PairContainer &main, Pend &pend)
{
	Jacobsthal jacob;
	size_t shift = 0;

	while (!pend.empty())
	{
		size_t jacob_original = jacob++  -2 ;
		d_cout << std::endl << "Jacob nb: " << jacob  << " decreased to " << jacob_original << std::endl;
		print(pend);
		if (jacob_original - shift < pend.size())
		{
			PendIterator it = pend.begin();
			std::advance(it, jacob_original - shift);
			insertUpdatingPend(it, main, pend, shift);
			insertUpdatingPend(it, main, pend, shift);
		}
		else
		{
			d_cout << B " ---- Inserting all from the end ---- " R << std::endl;
			print(pend);
			for (int j = pend.size() - 1; j >= 0; j--)
				binaryInsert(pend[j], main, pend);
			d_cout << B "FINI LA PEND" R << std::endl;
			break ;
		}
	}
}

template <typename Container>
void PmergeMe<Container>::insertUpdatingPend(PendIterator &it, PairContainer &main, Pend &pend, size_t &shift)
{
	binaryInsert(*it, main, pend);
	it = pend.erase(it);
	--it;
	shift++;
}

template <typename Container>
void PmergeMe<Container>::binaryInsert(PairTarget &src, PairContainer &sorted, Pend &pend)
{
	if (src.second >= sorted.size())
		src.second = sorted.size() - 1;
	printBeforeInsert(src, sorted);

	size_t insert_index = binarySearch(sorted, src.first.back(), 0, src.second);

	d_cout << "Inserting " BOLD  <<  src.first.back() <<  R " at insert index " B << insert_index << R << std::endl;
	PairIterator it = sorted.begin();
	std::advance(it, insert_index);
	sorted.insert(it, src.first);
	updatePendTargets(pend, insert_index);
}


template <typename PairContainer>
size_t binarySearch(const PairContainer& sorted, IntC elem, size_t start, size_t end)
{
	size_t mid = (end + start) / 2;

	if (end == 0)
		return 0;
	if (start == sorted.size() - 2)
		return sorted.size();
	if (elem > sorted[mid].back())
	{
		if (elem < sorted[mid + 1].back())
			return mid + 1;
		return binarySearch(sorted, elem, mid, end);
	}
	return binarySearch(sorted, elem, start, mid);
}

template <typename Container>
void PmergeMe<Container>::updatePendTargets(Pend &pend, size_t start_increase)
{
	for (PendIterator it = pend.begin(); it != pend.end(); ++it)
		if (it->second >= start_increase)
			it->second++;
}
