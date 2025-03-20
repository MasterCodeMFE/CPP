#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(): std::stack<T>()
{

}

template<typename T>
MutantStack<T>::~MutantStack()
{

}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other): std::stack<T>(other)
{

}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
    if (this != &other)
        std::stack<T>::operator=(other);
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin( void )
{
	return ( this->c.rbegin() );
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend( void )
{
	return ( this->c.rend() );
}