#include "easyfind.hpp"

int main()
{
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);

    std::cout << "Test 1: Looking for 30..." << std::endl;
    try
	{
        std::vector<int>::iterator it = easyfind(numbers, 30);
        std::cout << "Success! Found value: " << *it << std::endl;
    } 
    catch (const std::exception& e)
	{
        std::cout << "Test 1 Failed unexpectedly: " << RED << e.what() << WHITE << std::endl;
    }

    std::cout << "--------------------------" << std::endl;

    std::cout << "Test 2: Looking for 99..." << std::endl;
    
	try 
	{
        easyfind(numbers, 99);
        std::cout << "Test 2 Failed: Should have thrown an exception!" << std::endl;
    } 
    catch (const std::exception& e)
	{
        std::cout << "Success! Caught expected error: " << RED << e.what() << WHITE << std::endl;
    }
    
	return (0);
}

template <typename T>
typename T::iterator easyfind( T &container, int i)
{
	typename T::iterator it = std::find(container.begin(), container.end(), i);

	if(it == container.end())
		throw NoValueEx();
	return(it);
}
