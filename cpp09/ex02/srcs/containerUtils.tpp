#pragma once

#include "PmergeMe.hpp"

template <typename Container, typename PairContainer>
void updateContainer(Container& container, const PairContainer& pairs)
{
    container.clear();
    for (typename PairContainer::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
        for (typename Container::const_iterator elem = it->begin(); elem != it->end(); ++elem)
            container.push_back(*elem);
}

template <typename Container, typename PairContainer>
void updateContainer(Container& original, const PairContainer& main, const PairContainer& nonParticipating)
{
	original.clear();
	for (typename PairContainer::const_iterator it = main.begin(); it != main.end(); ++it)
		for (typename Container::const_iterator elem = it->begin(); elem != it->end(); ++elem)
			original.push_back(*elem);
	for (typename PairContainer::const_iterator it = nonParticipating.begin(); it != nonParticipating.end(); ++it)
		for (typename Container::const_iterator elem = it->begin(); elem != it->end(); ++elem)
			original.push_back(*elem);
}


