#include "PmergeMe.hpp"

DebugStream d_cout;

PmergeMe::PmergeMe(size_t nb_args, char **args) : _args(args), _nb_args(nb_args - 1)
{
	checkArgs();
	storeAndSort(_deque);

	// double l_time = stopwatch(&PmergeMe::template storeAndSort<std::list<IntC> >, _list);
	// double d_time = stopwatch(&PmergeMe::template storeAndSort<std::deque<IntC> >, _deque);

	// printTime(d_time, _deque.size(), "deque", l_time > d_time ? RED : GREEN );
	// printTime(l_time, _list.size(), "list",  d_time > l_time ? RED : GREEN);
}

void PmergeMe::checkArgs()
{

	for (size_t i = 0; i < _nb_args; i++)
	{
		std::istringstream iss(_args[i]);	
		int number;
		if (!(iss >> number) || iss.peek() != EOF)
			throw RedException("Invalid Number: " B + std::string(_args[i]) + R);
		if (number < 0 )
			throw RedException("Negative numbers not authorized: "  B + std::string(_args[i]) + R);
		// if (std::find(_list.begin(), _list.end(), number) != _list.end())
		// 	throw RedException("Duplicate number: " B + std::string(_args[i]) + R);
	}
}

template <typename Container>
void PmergeMe::store(Container& container)
{
	int number;

	for (size_t i = 0; i < _nb_args; i++)
	{
		std::istringstream iss(_args[i]);	
		iss >> number;
		container.push_back(number);
	}
}

template <typename Container>
void PmergeMe::storeAndSort(Container& container)
{
	store(container);
	sort(container);
}




/**
 * @details steps: 
 * - 1: Divide into pairs and sort it, x2 size of pairs and sort by last element. 
 *      When recursion level * 2 > size of list, we start the next step.
 * - 2:
 * 	- 2.1: Initalisation: The actual sequence is b1 a1 b2 a2 b3 a3.. bn an NonParticipating
 * 						Where the elements are the last pairs at the end of step 1.
 *                      NonParticipating is when the size of the last numbers < pair size
 * 
 * 		Pend list is init with B1 and all As
 *      Main list is init with the rest of Bs
 * 	- 2.2: Insertion with binary sort:
 * 		Boucle: Jacobstahl suivant dans la liste (on commence par 3)
 *					(donc itération 0: 3. 1: 5. 2:7) 
 *      		- Insert the b{jackobstahl} 
 *      		- Insert   b(jackobstahl -1)
 * 		jusqu'à ce que jacobstahlnb > nb
 *      à ce moment, on instert tous les éléments dans le sens inverse en partant du dernier
 *     
 */
template <typename Container>
void PmergeMe::sort(Container& container)
{
	r = 1;

	divideIntoPairsAndSort(container, r);
	initAndSort(container, r);
}


/**
 *  - 1: Divide into pairs and sort it, x2 size of pairs and sort by last element. 
 *      When recursion level * 2 > size of list, we start the next step.
 */
void PmergeMe::divideIntoPairsAndSort(Pair &deque, int &r)
{
	d_cout << GREEN B "Started pairing & sort, increasing recursion" R << std::endl;
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


void PmergeMe::initPairs(PairContainer &pairs, const Pair &deque)
{
	for (size_t i = 0; i < deque.size(); i += r)
	{
		Pair pair; 
		for (size_t j = 0; j < r && (i + j) < deque.size(); j++)
			pair.push_back(deque[i + j]);
		pairs.push_back(pair);
	}
}

void PmergeMe::initMainandPend(PairContainer &main,	Pend &pend, PairContainer &nonParticipating, const Pair &deque)
{
	PairContainer pairs;
	initPairs(pairs, deque);
	main.push_back(*pairs.begin());
	size_t i = 0; PairIterator it;
	for (it = pairs.begin() + 1, i = 0; it != pairs.end() && (it + 1) != pairs.end(); it++, i++)
	{
		if ((*it).size() == r)
			main.push_back(*it++);
		else
		{
			nonParticipating.push_back(*it++);
			break;
		}
		if ((*it).size() == r)
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

void PmergeMe::insertUpdatingPend(PendIterator &it, PairContainer &main, Pend &pend, size_t &shift)
{
	binaryInsert(*it, main, pend);
	it = pend.erase(it);
	--it;
	shift++;
}



void PmergeMe::initAndSort(Pair &deque, int &r)
{
	r /= 2;
	d_cout << GREEN B "Started insertion sort, decreasing recursion" R << std::endl;
	while (r >= 0)
	{
		PairContainer main;
		Pend pend;
		PairContainer nonParticipating;
		initMainandPend(main, pend, nonParticipating, deque);
		
		// Inserting
		Jacobsthal jacob;
		size_t shift = 0;
		while (!pend.empty())
		{
			size_t jacob_original = jacob++  -2 ;
			d_cout << std::endl << "Jacob nb: " << jacob  << " decreased to " << jacob_original << std::endl;
			d_cout << "Actual pend: ";
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
				{
					print(pend[j].first, WHITE);
					binaryInsert(pend[j], main, pend);
				}
				d_cout << B "FINI LA PEND" R << std::endl;
				break ;
			}
		}
		updateContainer(deque, main, nonParticipating);

		r /= 2;
		if (r == 0)
			break;
	}
}

void  PmergeMe::binaryInsert(PairWithIndex &src, PairContainer &sorted, Pend &pend)
{
	if (src.second >= sorted.size())
	{
		src.second = sorted.size() - 1;
	}
	d_cout 	<< "searching index for " B CYAN << src.first.back() << R " between 0 and " << src.second << std::endl
				<<  "Target is " B PINK << sorted[src.second].back() << R << std::endl;

	for (PairIterator it = sorted.begin(); it != sorted.end(); it++)
		d_cout << it->back() << " ";
	d_cout << std::endl;
	size_t insert_index = binarySearch(sorted, src.first.back(), 0, src.second);
	d_cout << "Inserting " BOLD  <<  src.first.back() <<  R " at insert index " B << insert_index << R << std::endl;

	PairIterator it = sorted.begin();
	std::advance(it, insert_index);
	sorted.insert(it, src.first);
	updatePend(pend, insert_index);
}

void PmergeMe::updatePend(Pend &pend, size_t start_increase)
{
	PendIterator it = pend.begin();
	for (it; it != pend.end(); ++it)
		if (it->second >= start_increase)
			it->second++;
}

/**
 * @brief Binary search to find where the element should be inserted in a sorted container.
 * @param sorted The sorted container to search in.
 * @param elem The element to insert.
 * @param start The starting index of the search range.
 * @param end The ending index of the search range.
 * @return The index where the element should be inserted.
 */
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
