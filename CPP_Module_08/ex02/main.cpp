/* #include "MutantStack.hpp"
#include <iostream>
#include <string>

template <typename T>
void testMutantStack(const std::string& typeName, T v1, T v2, T v3, T v4, T v5)
{
    std::cout << "===== Testing MutantStack<" << typeName << "> =====" << std::endl;

    MutantStack<T> mstack;
    mstack.push(v1);
    mstack.push(v2);
    
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(v3);
    mstack.push(v4);
    mstack.push(v5);

    std::cout << "Stack elements (normal order):" << std::endl;
    for (typename MutantStack<T>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Stack elements (reverse order):" << std::endl;
    for (typename MutantStack<T>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
    {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    std::stack<T> s(mstack); // Verificar conversión a std::stack
    std::cout << "Copy to std::stack successful." << std::endl;
    std::cout << "====================================\n" << std::endl;
}

int main()
{
    testMutantStack<int>("int", 5, 17, 3, 5, 737);
    testMutantStack<double>("double", 3.14, 2.71, 1.61, 4.20, 0.99);
    testMutantStack<std::string>("std::string", "hello", "world", "C++", "98", "STL");

    return 0;
} */

/* #include <deque>
#include <stack>
#include <iostream>

int	main( void )
{
	std::deque<int>	mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);

	mstack.push_back(0);
	std::deque<int>::iterator it = mstack.begin();
	std::deque<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::deque<int>::reverse_iterator rit = mstack.rbegin();
	std::deque<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::stack< int, std::deque<int> > s(mstack);
	return 0;
} */

/* #include <list>
#include <stack>
#include <iostream>

int	main( void )
{
	std::list<int>	mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);

	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int>::reverse_iterator rit = mstack.rbegin();
	std::list<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::stack< int, std::list<int> > s(mstack);
	return 0;
} */

#include <vector>
#include <stack>
#include <iostream>

int	main( void )
{
	std::vector<int>	mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);

	mstack.push_back(0);
	std::vector<int>::iterator it = mstack.begin();
	std::vector<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::vector<int>::reverse_iterator rit = mstack.rbegin();
	std::vector<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::stack< int, std::vector<int> > s(mstack);
	return 0;
}