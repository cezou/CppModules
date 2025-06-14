#include "PmergeMe.hpp"

void PmergeMe::printTime(double time, size_t size, std::string container, std::string color)
{
	std::cout 	<< "Time to process a range of " << size
				<< " elements with std::" << container << " : " B << color << time << R " us" << std::endl;
}

PmergeMe::PmergeMe(size_t nb_args, char **args) : _args(args), _nb_args(nb_args - 1)
{
	checkArgs();
	double l_time = stopwatch(&PmergeMe::storeAndSortList);
	double d_time = stopwatch(&PmergeMe::storeAndSortDeque);

	printTime(d_time, _deque.size(), "deque", l_time > d_time ? RED : GREEN );
	printTime(l_time, _list.size(), "list",  d_time > l_time ? RED : GREEN);
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

void PmergeMe::storeAndSortList()
{
	store(_list);
	sort(_list);
}

void PmergeMe::storeAndSortDeque()
{
	store(_deque);
}

double PmergeMe::stopwatch(void (PmergeMe::*fun)())
{
	_start = clock();
    (this->*fun)();
	_end = clock();
	return ((_end - _start) / CLOCKS_PER_SEC) * 1000000;
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
 * 	- 2.2: Insertion:
 * 		Boucle: Jacobstahl suivant dans la liste (on commence par 3)
* 												  (donc itération 0: 3. 1: 5. 2:7) et
 * 
 *      Insert the b{jackobstahl}
 *      Insert   b(jackobstahl -1)
 */
void PmergeMe::sort(std::list<int> l)

{
	(void)l;
}