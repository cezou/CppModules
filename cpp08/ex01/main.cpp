#include "Span.hpp"

void tests()
{
    std::cout << "\n--- TESTING EMPTY SPAN ---" << std::endl;
    Span sp = Span(5);
    try {
        std::cout << "Attempting to find shortest span in empty span..." << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "Attempting to find longest span in empty span..." << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TESTING ADD RANGE ---" << std::endl;
    int arr[] = {6, 3, 17, 9, 11};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    try {
        sp.addRange(vec.begin(), vec.end());
        std::cout << "Successfully added range of 5 elements" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "\n--- TESTING ADD RANGE WITH FULL SPAN ---" << std::endl;
		vec.push_back(42);
		sp.addRange(vec.begin(), vec.end());
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TESTING SPAN FULL ---" << std::endl;
    try {
        sp.addNumber(42); 
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TESTING LARGE SPAN ---" << std::endl;
    Span largeSpan(10000);
    std::vector<int> largeVector;
    for (int i = 0; i < 10000; i++) 
        largeVector.push_back(i);

    try {
        largeSpan.addRange(largeVector.begin(), largeVector.end());
        std::cout << "Successfully added 10,000 elements" << std::endl;
        std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

	std::cout << "\n--- TESTING ADD RANGE WITH DEQUE ---" << std::endl;
	int arr2[] = {1, 2, 3, 4, 5};
    std::deque<int> deq(arr2, arr2 + sizeof(arr2) / sizeof(int));
	Span sp2(10);
	try {
		sp2.addRange(deq.begin(), deq.end());
		std::cout << "Successfully added range from deque" << std::endl;
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

int main()
{
    std::cout << "--- SUBJECT TESTS ---" << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    tests();
    return 0;
}