#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span
{
    private:
        std::vector<int> numbers;
        unsigned int Max;
    public:
    Span(unsigned int N);
    ~Span();
    Span(const Span& other);
    Span& operator=(const Span& other);

    void addNumber(int num);
    void shortestSpan();
    void longestSpan();
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif