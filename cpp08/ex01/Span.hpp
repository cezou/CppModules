#ifndef SPAN_HPP
# define SPAN_HPP

# include "../utils.hpp"
# include <algorithm>
# include <iterator>
# include <vector>
# include <list>
# include <deque>

class Span
{
public:
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);
	
	template <typename Iterator>
	void addRange(Iterator begin, Iterator end)
	{
		if (std::distance(begin, end) + _numbers.size() > _n)
			throw RedException("Not enough space in Span to add this range");
		_numbers.insert(_numbers.end(), begin, end);
	}

	int shortestSpan();
	int longestSpan();

private:
	unsigned int _n;
	std::vector<int> _numbers;
};

#endif