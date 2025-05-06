#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span& other)
{
	if (this != &other)
	{
		_n = other._n;
		_numbers = other._numbers;
	}
}
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_n = other._n;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _n)
		throw RedException("Span is full");
	_numbers.push_back(number);
}


int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw RedException("Not enough numbers to find a span");
	return 	*std::max_element(_numbers.begin(), _numbers.end())
			- *std::min_element(_numbers.begin(), _numbers.end());
}

int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw RedException("Not enough numbers to find a span");

	std::vector<int> sorted = this->_numbers;
	std::sort(sorted.begin(), sorted.end());

	int span = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++)
		if (sorted[i] - sorted[i - 1] < span)
			span = sorted[i] - sorted[i - 1];
	return span;
}