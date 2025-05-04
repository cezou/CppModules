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
    int shortestSpan();
    int longestSpan();
    
    class SpanFullException : public std::exception
    {
        const char* what() const throw()
        {
            return RED "Span is full" RESET;
        }
    };
    
private:
    unsigned int _n;
    std::vector<int> _numbers;
};

#endif