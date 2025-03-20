# include "Span.hpp"

Span::Span(unsigned int N): Max(N)
{

}

Span::~Span()
{

}
Span::Span(const Span& other): numbers(other.numbers), Max(other.Max)
{

}
Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->numbers = other.numbers;
        this->Max = other.Max;
    }
    return *this;
}

void Span::addNumber(int num)
{
    if (this->numbers.size() >= Max)
    {
        throw std::out_of_range("Error: you cannot add more numbers, the vector is full.");
    }
    this->numbers.push_back(num);
}

void Span::shortestSpan()
{
    std::vector<int> copy = this->numbers;

    if (copy.size() < 2)
    {
        throw std::runtime_error("Cannot calculate the distance with fewer than 2 numbers.");
    }
    else
    {
        std::sort(copy.begin(), copy.end());
        int minSpan = std::numeric_limits<int>::max();
        for (std::vector<int>::iterator it = copy.begin(); it != copy.end() - 1; ++it)
        {
            int diff = *(it + 1) - *it;
            if (diff < minSpan)
            {
                minSpan = diff;
            }
        }
        std::cout << "Shortest distance: " << minSpan << std::endl;
    }
    
}

void Span::longestSpan()
{
    std::vector<int> copy = this->numbers;

    if (copy.size() < 2)
    {
        throw std::runtime_error("Cannot calculate the distance with fewer than 2 numbers.");
    }
    else
    {
        std::sort(copy.begin(), copy.end());
        int dif = copy.back() - copy.front();
        std::cout << "Longest distance: " << dif << std::endl;
    }
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->numbers.size() + std::distance(begin, end) > this->Max)
    {
        throw std::out_of_range("Error: you cannot add more numbers, the vector is full.");
    }
    this->numbers.insert(this->numbers.end(), begin, end);
}