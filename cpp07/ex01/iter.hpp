#ifndef ITER_HPP
# define ITER_HPP

# include "../utils.hpp"


template<typename T>
void iter(const T *array, size_t len, void (*f)(const T &))
{
	if (!array || !f)
		return;
	for (size_t i = 0; i < len; ++i)
		f(array[i]);
}

template<typename T>
void print(const T &a)
{
	std::cout << a << " "; 
}

template <typename T, size_t N>
void testIter(const T (&array)[N], const std::string& typeName) 
{
	std::cout 	<< std::endl
				 << CYAN << typeName << " array" << R << std::endl;
	::iter(array, N, print);
	std::cout << std::endl;
}

#endif