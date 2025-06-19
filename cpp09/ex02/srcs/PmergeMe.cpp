#include "PmergeMe.hpp"



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
		if (std::find(_list.begin(), _list.end(), number) != _list.end())
			throw RedException("Duplicate number: " B + std::string(_args[i]) + R);
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
	size_t recursion_level = 1;

	divideIntoPairsAndSort(container, recursion_level);
	initAndSort(container, recursion_level);
}


/**
 *  - 1: Divide into pairs and sort it, x2 size of pairs and sort by last element. 
 *      When recursion level * 2 > size of list, we start the next step.
 */
void PmergeMe::divideIntoPairsAndSort(std::deque<IntC> &deque, size_t &r)
{
	while (r * 2 < deque.size())
	{
		size_t pairSize = r;
		std::deque<std::deque<IntC> > pairs;
		for (size_t i = 0; i < deque.size(); i += pairSize)
		{
			std::deque<IntC> pair; 
			for (size_t j = 0; j < pairSize && (i + j) < deque.size(); j++)
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

void PmergeMe::initAndSort(std::deque<IntC> &deque, size_t &r)
{
	r /= 2;
	while (r >= 1)
	{
		size_t pairSize = r;
		PairContainer pairs;
		for (size_t i = 0; i < deque.size(); i += pairSize)
		{
			std::deque<IntC> pair; 
			for (size_t j = 0; j < pairSize && (i + j) < deque.size(); j++)
				pair.push_back(deque[i + j]);
			pairs.push_back(pair);
		}
		PairContainer main;
		PairContainer pend;
		PairContainer nonParticipating;
		
		main.push_back(*pairs.begin());
		for (PairIterator it = pairs.begin() + 1; it != pairs.end() && (it + 1) != pairs.end(); it++)
		{
			if ((*it).size() == pairSize)
				main.push_back(*it++);
			else
				nonParticipating.push_back(*it++);
			if ((*it).size() == pairSize)
				pend.push_back(*it);
			else
				nonParticipating.push_back(*it);
		}
		print(pairs, pend, main, nonParticipating, r);

		Jacobsthal jacob;
		PairIterator it = pend.begin();
		for (size_t i = 0; i < pend.size();)
		{
			size_t jacob_original = jacob -1 -i;
			if (jacob_original < pend.size())
			{
				std::advance(it, jacob_original);
				binaryInsert(*it, main, jacob_original);
				pend.erase(it);
				it--;
				binaryInsert(*it, main, jacob_original);
				pend.erase(it);
			}
			else
			{
				for (PairIterator ite = pend.end(); it != pend.begin(); ite--)
				{
					binaryInsert(*ite, main, jacob_original);
					pend.erase(ite);
				}
				break;
			}
		}
		updateContainer(deque, main, nonParticipating);
		r /= 2;
	}
}

/**
 * @brief Binary search to find where the element should be inserted in a sorted container.
 * @param sorted The sorted container to search in.
 * @param elem The element to insert.
 * @param start The starting index of the search range.
 * @param end The ending index of the search range.
 * @return The index where the element should be inserted.
 */
size_t binarySearch(PairContainer sorted, IntC elem, size_t start, size_t end)
{
	size_t mid = (end + start) / 2;
	if (elem > sorted[mid].back())
		binarySearch(sorted, elem, mid, end);
	else
		binarySearch(sorted, elem, start, mid);
}
void PmergeMe::binaryInsert(Pair &src, PairContainer sorted, size_t end)
{
	
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