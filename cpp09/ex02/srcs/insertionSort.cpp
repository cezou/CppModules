#include "PmergeMe.hpp"

/**
 * @brief
 * 	- Initalisation: initialisation of main, pend & nonParticipating
 * 	- Insertion with binary sort
 */
void PmergeMe::initAndSort(Pair &deque, int &r)
{
	r /= 2;
	while (r > 0)
	{
		d_cout << std::endl << "Pairs size: " BOLD << r << R << std::endl;
		PairContainer main;
		Pend pend;
		PairContainer nonParticipating;
		initMainandPend(main, pend, nonParticipating, deque);
		insertPendIntoMain(main, pend);
		updateContainer(deque, main, nonParticipating);
		r /= 2;
	}
}

/** 
 * @details Initalisation: The actual sequence is b1 a1 b2 a2 b3 a3.. bn an NonParticipating
 * 						Where the elements are the last pairs at the end of step 1.
 *                      NonParticipating is when the size of the last numbers < pair size
 * 		Pend list is init with B1 and all As
 *      Main list is init with the rest of Bs
 */
void PmergeMe::initMainandPend(PairContainer &main,	Pend &pend, PairContainer &nonParticipating, const Pair &deque)
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


/**
 *  @details Insertion with binary sort:
 * 		Boucle: Jacobstahl suivant dans la liste (on commence par 3)
 *					(donc itération 0: 3. 1: 5. 2:7) 
 *      		- Insert the b{jackobstahl} 
 *      		- Insert   b(jackobstahl -1)
 * 		jusqu'à ce que jacobstahlnb > nb
 *      à ce moment, on insert tous les éléments dans le sens inverse en partant du dernier
 */
void  PmergeMe::insertPendIntoMain(PairContainer &main, Pend &pend)
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

void PmergeMe::initPairs(PairContainer &pairs, const Pair &deque)
{
	for (size_t i = 0; i < deque.size(); i += r)
	{
		Pair pair; 
		for (int j = 0; j < r && (int)(i + j) < (int)deque.size(); j++)
			pair.push_back(deque[i + j]);
		pairs.push_back(pair);
	}
}

void PmergeMe::insertUpdatingPend(PendIterator &it, PairContainer &main, Pend &pend, size_t &shift)
{
	binaryInsert(*it, main, pend);
	it = pend.erase(it);
	--it;
	shift++;
}



