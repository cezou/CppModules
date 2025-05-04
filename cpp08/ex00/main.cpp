#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i * 10);
    testEasyFind(vec, 30, "vector");
    testEasyFind(vec, 55, "vector");
    
    std::list<int> lst;
    for (int i = 0; i < 5; i++)
        lst.push_back(i * 5);
    testEasyFind(lst, 15, "list");
    testEasyFind(lst, 42, "list");
    
    std::deque<int> deq;
    for (int i = 0; i < 7; i++)
        deq.push_back(i * 7);
    testEasyFind(deq, 21, "deque");
    testEasyFind(deq, 100, "deque");
    
}
