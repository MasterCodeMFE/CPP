#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename MutantStack<T>::container_type::reverse_iterator	reverse_iterator;


        iterator begin();
        iterator end();
        reverse_iterator	rbegin( void );
		reverse_iterator	rend( void );
};

#include "MutantStack.tpp"

#endif