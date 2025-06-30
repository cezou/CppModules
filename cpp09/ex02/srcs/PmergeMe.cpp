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
	std::vector<int> dupchecker;
	for (size_t i = 0; i < _nb_args; i++)
	{
		std::istringstream iss(_args[i]);	
		int number;
		if (!(iss >> number) || iss.peek() != EOF)
			throw RedException("Invalid Number: " B + std::string(_args[i]) + R);
		if (number < 0 )
			throw RedException("Negative numbers not authorized: "  B + std::string(_args[i]) + R);
		if (std::find(dupchecker.begin(), dupchecker.end(), number) != dupchecker.end())
			throw RedException("Duplicate number: " B + std::string(_args[i]) + R);
		dupchecker.push_back(number);
	}
	if (is_sorted(dupchecker))
		throw RedException("List already sorted");
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
 */
template <typename Container>
void PmergeMe::sort(Container& container)
{
	r = 1;
	d_cout << GREEN B "Started pairing & sort, increasing recursion" R << std::endl;
	divideIntoPairsAndSort(container, r);
	d_cout << GREEN B "Started insertion sort, decreasing recursion" R << std::endl;
	initAndSort(container, r);
}


void  PmergeMe::binaryInsert(PairTarget &src, PairContainer &sorted, Pend &pend)
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

void PmergeMe::updatePendTargets(Pend &pend, size_t start_increase)
{
	for (PendIterator it = pend.begin(); it != pend.end(); ++it)
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
