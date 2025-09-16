#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <utility>
#include <algorithm>


// Se utilizan std::vector y std::deque para:
// - Comparar rendimiento y eficiencia en la implementación del algoritmo Ford-Johnson.
// - Evaluar cómo cada contenedor maneja inserciones y accesos aleatorios durante la ordenación.
// Esto permite analizar las diferencias prácticas entre ambos en escenarios de ordenación intensiva.
class PmergeMe {
    private:
        std::vector<unsigned int> vec;  // Contenedor 1
        std::deque<unsigned int> deq;   // Contenedor 2
        long lastDeq;
        long lastVec;
        std::vector<std::pair<int, int> > vecPair;
        std::vector<unsigned int> sortedVec;


        std::deque<std::pair<int, int> > deqPair;
        std::deque<unsigned int> sortedDeq;
        // Métodos privados
        void sortPairs();

        
        void parseArguments(int argc, char **argv);
        void pairsOrderVec(std::vector<unsigned int>& vec);
        void orderPairVec(std::vector<std::pair<int, int> > &vecPair);
        void insertRemainingElementsVec(std::vector<unsigned int> &sortedVec);
        void printSortedPairsVec(const std::vector<std::pair<int, int> > &vecPair);
        void insertRestVec(std::vector<unsigned int> &sortedVec);

        void pairsOrderDeq( std::deque<unsigned int> &deq);
        void orderPairDeq(std::deque<std::pair<int, int> > &deqPair);
        void insertRemainingElementsDeq(std::deque<unsigned int> &sortedDeq);
        void printSortedPairsDeq(const std::deque<std::pair<int, int> > &deqPair);
        void insertRestDeq(std::deque<unsigned int> &sortedDeq);

        size_t binarySearchVec(const std::vector<unsigned int>& sortedVec, unsigned int target);
        size_t binarySearchDeq(const std::deque<unsigned int>& sortedDeq, unsigned int target);


    public:
        // Constructor y destructor
        PmergeMe(int argc, char **argv);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        // Función principal para ordenar
        void sortVec();
        void sortDeq();

        template <typename T>
        void printHelper(const T& container) const;

        const std::vector<unsigned int>& getVector() const;
        const std::deque<unsigned int>& getDeque() const;
        const std::vector<unsigned int>& getSortedVec() const;
        const std::deque<unsigned int>& getSortedDeq() const;

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