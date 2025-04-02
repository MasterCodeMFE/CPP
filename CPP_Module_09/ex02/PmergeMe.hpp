#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <cerrno>
#include <climits>
#include <cstdlib>

class PmergeMe {
private:
    std::vector<unsigned int> vec;  // Contenedor 1
    std::deque<unsigned int> deq;   // Contenedor 2

    // Métodos privados
    void sortPairs(std::vector<unsigned int>& container);
    void mergeInsertSort(std::vector<unsigned int>& container);
    void mergeInsertSort(std::deque<unsigned int>& container);
    
    void parseArguments(int argc, char **argv);

public:
    // Constructor y destructor
    PmergeMe(int argc, char **argv);
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    // Función principal para ordenar
    void sort();

    template <typename T>
    void printHelper(const T& container) const;

    const std::vector<unsigned int>& getVector() const;
    const std::deque<unsigned int>& getDeque() const;
};

template <typename T>
void PmergeMe::printHelper(const T& container) const
{
    size_t limit = 4;
    size_t size = container.size();

    for (size_t i = 0; i < size && i < limit; ++i) {
        std::cout << container[i] << " ";
    }
    if (size > limit) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

#endif