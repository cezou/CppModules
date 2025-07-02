#pragma once

#include "PmergeMe.hpp"

template <typename Container, typename PairContainer>
void updateContainer(Container& container, const PairContainer& pairs)
{
    container.clear();
    for (typename PairContainer::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
        container.insert(container.end(), it->begin(), it->end());
}

template <typename Container, typename PairContainer>
void updateContainer(Container& original, const PairContainer& main, const PairContainer& nonParticipating)
{
    original.clear();
    for (typename PairContainer::const_iterator it = main.begin(); it != main.end(); ++it)
        original.insert(original.end(), it->begin(), it->end());
    for (typename PairContainer::const_iterator it = nonParticipating.begin(); it != nonParticipating.end(); ++it)
        original.insert(original.end(), it->begin(), it->end());
}
