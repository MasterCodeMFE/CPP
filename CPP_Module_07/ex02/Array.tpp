#include "Array.hpp"

template<typename T>
Array<T>::Array(): value(NULL), size(0)
{
}

template<typename T>
Array<T>::Array(int n): size(n)
{
    this->value = new T[n]();    
}

template<typename T>
Array<T>::Array(const Array<T>& other): size(other.size)
{
    value = new T[size];
    for (unsigned int i = 0; i < size; i++)
    {
        value[i] = other.value[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        delete[] value;
        size = other.size;
        value = new T[size];
        for (unsigned int i = 0; i < size; i++)
        {
            value[i] = other.value[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array()
{
    delete[] value;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= size)
        throw std::out_of_range("Index out of range");
    return value[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= size)
        throw std::out_of_range("Index out of range");
    return value[index];
}

template<typename T>
unsigned int Array<T>::getSize() const
{
    return size;
}