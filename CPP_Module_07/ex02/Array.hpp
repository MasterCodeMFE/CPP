#ifndef ARRAY_HPP
#define ARRAY_HPP


template<typename T>
class Array
{
    private:
        T *value;
        unsigned int size;
    public:
        Array();
        Array(int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        T& operator[](unsigned int index);       
        const T& operator[](unsigned int index) const; 
        unsigned int getSize() const;

};

#include "Array.tpp"    
#endif // ARRAY_HPP