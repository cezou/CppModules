#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include "../utils.hpp"
# include <algorithm>
# include <iterator>
# include <vector>
# include <list>
# include <deque>

template<typename T>
typename T::iterator easyfind(T& container, int n)
{
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::out_of_range(RED "Element not found" RESET);
    return it;
}

template<typename T>
void testEasyFind(T& container, int value, const std::string& containerName)
{
    std::cout << BOLD "Testing " << containerName << "..." RESET << std::endl;
    try
    {
        typename T::iterator result = easyfind(container, value);
        std::cout << GREEN "✓ " RESET "Found value " << *result 
                  << " in " << containerName << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << RED "✗ " RESET << e.what() << " in " << containerName << std::endl;
    }
    std::cout << std::endl;
}

#endif