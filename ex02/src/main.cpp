#include "MutantStack.hpp"
#include "MutantStack.tpp"

int main()
{
    std::cout << "--- MutantStack Tests ---" << std::endl;
    MutantStack<int> mstack;
	
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite)
	{
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\n--- Comparison with std::list ---" << std::endl;
    std::list<int> mylist;
    mylist.push_back(5);
    mylist.push_back(17);
    
    std::cout << "Top (back): " << mylist.back() << std::endl; 
    
    mylist.pop_back();
    std::cout << "Size: " << mylist.size() << std::endl;
    
    mylist.push_back(3);
    mylist.push_back(5);
    mylist.push_back(737);
    mylist.push_back(0);

    std::list<int>::iterator lit = mylist.begin();
    std::list<int>::iterator lite = mylist.end();

    while (lit != lite)
	{
        std::cout << *lit << std::endl;
        ++lit;
    }

    return 0;
}
