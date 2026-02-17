#include "Span.hpp"

int main()
{
    std::cout << "--- Test 1: subject test ---" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;


    std::cout << "--- Test 2: addRange ---" << std::endl;
    try
    {
        Span sp(5);
        std::vector<int> v;
        v.push_back(1);
        v.push_back(20);
        v.push_back(30);
        v.push_back(99);

        sp.addRange(v.begin(), v.end());
        sp.addNumber(10);

        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest:  " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
	return (0);
}
