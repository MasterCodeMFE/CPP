/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:49:44 by manufern          #+#    #+#             */
/*   Updated: 2025/04/03 11:49:14 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
    parseArguments(argc, argv);
}

void PmergeMe::parseArguments(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        char *endptr; 
        errno = 0;

        unsigned long num = std::strtoul(argv[i], &endptr, 10);

        if (errno == ERANGE)
        {
            std::cerr << "Error: Number out of range." << std::endl;
            throw std::invalid_argument("Invalid argument");
        }
        else if (endptr == argv[i])
        {
            std::cerr << "Error: " << argv[i] << " not a valid number." << std::endl;
            throw std::invalid_argument("Invalid argument");
        }
        else
        {
            if (num > UINT_MAX)
            {
                std::cerr << "Error: The number must be between 0 and " << UINT_MAX << "." << std::endl;
                throw std::invalid_argument("Invalid argument");
            }
            if (num >= 0)
            {
                vec.push_back(static_cast<unsigned int>(num));
                deq.push_back(static_cast<unsigned int>(num));
            }
            else
            {
                std::cerr << "Error: The number must be positive." << std::endl;
                throw std::invalid_argument("Invalid argument");
            }
        }
    }
}

PmergeMe::~PmergeMe()
{}

const std::vector<unsigned int>& PmergeMe::getVector() const
{
    return vec;
}

const std::deque<unsigned int>& PmergeMe::getDeque() const
{
    return deq;
}

const std::vector<unsigned int>& PmergeMe::getSortedVec() const
{
    return sortedVec;
}

const std::deque<unsigned int>& PmergeMe::getSortedDeq() const
{
    return sortedDeq;
}

void PmergeMe::pairsOrderVec( std::vector<unsigned int> &vec)
{
    for(size_t i = 0; i < vec.size(); i += 2)
    {
        if(vec[i] > vec[i + 1])
            vecPair.push_back(std::make_pair(vec[i + 1], vec[i]));
        else
            vecPair.push_back(std::make_pair(vec[i], vec[i + 1]));
    }

    /* std::cout << "Pairs:" << std::endl;
    for (size_t j = 0; j < vecPair.size(); ++j) {
        std::cout << "(" << vecPair[j].first << ", " << vecPair[j].second << ")" << std::endl; // Print each pair
    } */

}

void PmergeMe::orderPairVec(std::vector<std::pair<int, int> >& vecPair)
{
    // Si el vector está vacío o tiene un solo elemento, ya está ordenado
    if (vecPair.empty() || vecPair.size() == 1)
        return;

    size_t size = vecPair.size(); // Tamaño del vector
    size_t mid = size / 2; // Calcular el punto medio

    // Crear dos vectores para las mitades
    std::vector<std::pair<int, int> > leftHalf(vecPair.begin(), vecPair.begin() + mid);
    std::vector<std::pair<int, int> > rightHalf(vecPair.begin() + mid, vecPair.end());

    // Llamadas recursivas para ordenar las dos mitades
    orderPairVec(leftHalf);
    orderPairVec(rightHalf);

    size_t leftIndex = 0;  // Índice para la mitad izquierda
    size_t rightIndex = 0; // Índice para la mitad derecha
    size_t mergeIndex = 0; // Índice para vecPair (resultado de la fusión)

    // Fusionar los vectores ordenados
    while (leftIndex < leftHalf.size() && rightIndex < rightHalf.size())
    {
        // Comparar los segundo elementos de los pares
        if (leftHalf[leftIndex].second < rightHalf[rightIndex].second)
        {
            vecPair[mergeIndex++] = leftHalf[leftIndex++];
        }
        else
        {
            vecPair[mergeIndex++] = rightHalf[rightIndex++];
        }
    }

    // Copiar los elementos restantes de la mitad izquierda
    while (leftIndex < leftHalf.size())
    {
        vecPair[mergeIndex++] = leftHalf[leftIndex++];
    }

    // Copiar los elementos restantes de la mitad derecha
    while (rightIndex < rightHalf.size())
    {
        vecPair[mergeIndex++] = rightHalf[rightIndex++];
    }
}

// Función para imprimir los pares ordenados después de que se haya llamado a orderPair
/* void PmergeMe::printSortedPairsVec(const std::vector<std::pair<int, int> > &vecPair)
{
    std::cout << "Sorted Pairs:" << std::endl;
    for (size_t printIndex = 0; printIndex < vecPair.size(); ++printIndex)
    {
        std::cout << "(" << vecPair[printIndex].first << ", " << vecPair[printIndex].second << ")" << std::endl; // Imprimir cada par
    }
} */


void PmergeMe::insertRemainingElementsVec(std::vector<unsigned int> &sortedVec)
{
    size_t itVectorPair = 0;

    while (itVectorPair < vecPair.size())
    {
        sortedVec.push_back(vecPair[itVectorPair].second);
        itVectorPair ++;
    }
    
}

size_t PmergeMe::binarySearchVec(const std::vector<unsigned int>& sortedVec, unsigned int target) {
    size_t left = 0;
    size_t right = sortedVec.size();

    while (left < right) {
        size_t mid = left + (right - left) / 2; // Calcular el índice medio

        if (sortedVec[mid] == target) {
            return mid; // Retornar el índice si se encuentra
        }
        else if (sortedVec[mid] < target) {
            left = mid + 1; // Buscar en la mitad derecha
        }
        else {
            right = mid; // Buscar en la mitad izquierda
        }
    }

    return left; // Retornar la posición donde se debería insertar el elemento
}

void PmergeMe::insertRestVec(std::vector<unsigned int> &sortedVec)
{
    sortedVec.insert(sortedVec.begin(), vecPair[0].first);
    if(sortedVec.size() == 1)
    {
        return ;
    }
    size_t itVectorPair = 1;
    size_t position;
    while(itVectorPair < vecPair.size())
    {
        position = binarySearchVec(sortedVec, vecPair[itVectorPair].first);
        sortedVec.insert(sortedVec.begin() + position, vecPair[itVectorPair].first);
        itVectorPair ++;
    }
    if (lastVec != -1)
    {
        position = binarySearchVec(sortedVec, lastVec);
        sortedVec.insert(sortedVec.begin() + position, lastVec);
    }
/*     std::cout << "Final Sorted Sequence:" << std::endl;
    for (size_t k = 0; k < sortedVec.size(); ++k) {
        std::cout << sortedVec[k] << " "; // Imprimir cada elemento de sortedVec
    }
    std::cout << std::endl; // Nueva línea al final */
}

 void PmergeMe::sortVec()
 {
    lastVec = -1;
    if (vec.size() % 2 != 0)
    {
        lastVec = vec.back();
        vec.pop_back();
        //std::cout << "Last: " << lastVec << std::endl;
    }
    //1. Agrupar por pares y ordenar los pares
    pairsOrderVec(vec);
    orderPairVec(vecPair);
    //printSortedPairs(vecPair);
    insertRemainingElementsVec(sortedVec);
    insertRestVec(sortedVec);
 }




























 void PmergeMe::pairsOrderDeq( std::deque<unsigned int> &deq)
{
    for(size_t i = 0; i < vec.size(); i += 2)
    {
        if(deq[i] > deq[i + 1])
            deqPair.push_back(std::make_pair(deq[i + 1], deq[i]));
        else
            deqPair.push_back(std::make_pair(deq[i], deq[i + 1]));
    }
}

void PmergeMe::orderPairDeq(std::deque<std::pair<int, int> >& deqPair)
{
    // Si el vector está vacío o tiene un solo elemento, ya está ordenado
    if (deqPair.empty() || deqPair.size() == 1)
        return;

    size_t size = deqPair.size(); // Tamaño del vector
    size_t mid = size / 2; // Calcular el punto medio

    // Crear dos vectores para las mitades
    std::deque<std::pair<int, int> > leftHalf(deqPair.begin(), deqPair.begin() + mid);
    std::deque<std::pair<int, int> > rightHalf(deqPair.begin() + mid, deqPair.end());

    // Llamadas recursivas para ordenar las dos mitades
    orderPairDeq(leftHalf);
    orderPairDeq(rightHalf);

    size_t leftIndex = 0;  // Índice para la mitad izquierda
    size_t rightIndex = 0; // Índice para la mitad derecha
    size_t mergeIndex = 0; // Índice para deqPair (resultado de la fusión)

    // Fusionar los vectores ordenados
    while (leftIndex < leftHalf.size() && rightIndex < rightHalf.size())
    {
        // Comparar los segundo elementos de los pares
        if (leftHalf[leftIndex].second < rightHalf[rightIndex].second)
        {
            deqPair[mergeIndex++] = leftHalf[leftIndex++];
        }
        else
        {
            deqPair[mergeIndex++] = rightHalf[rightIndex++];
        }
    }

    // Copiar los elementos restantes de la mitad izquierda
    while (leftIndex < leftHalf.size())
    {
        deqPair[mergeIndex++] = leftHalf[leftIndex++];
    }

    // Copiar los elementos restantes de la mitad derecha
    while (rightIndex < rightHalf.size())
    {
        deqPair[mergeIndex++] = rightHalf[rightIndex++];
    }
}

// Función para imprimir los pares ordenados después de que se haya llamado a orderPair
/* void PmergeMe::printSortedPairsDeq(const std::deque<std::pair<int, int> > &deqPair)
{
    std::cout << "Sorted Pairs:" << std::endl;
    for (size_t printIndex = 0; printIndex < deqPair.size(); ++printIndex)
    {
        std::cout << "(" << deqPair[printIndex].first << ", " << deqPair[printIndex].second << ")" << std::endl; // Imprimir cada par
    }
} */


void PmergeMe::insertRemainingElementsDeq(std::deque<unsigned int> &sortedDeq)
{
    size_t itDequePair = 0;

    while (itDequePair < deqPair.size())
    {
        sortedDeq.push_back(deqPair[itDequePair].second);
        itDequePair ++;
    }
    
}

size_t PmergeMe::binarySearchDeq(const std::deque<unsigned int>& sortedDeq, unsigned int target) {
    size_t left = 0;
    size_t right = sortedDeq.size();

    while (left < right) {
        size_t mid = left + (right - left) / 2; // Calcular el índice medio

        if (sortedDeq[mid] == target) {
            return mid; // Retornar el índice si se encuentra
        }
        else if (sortedDeq[mid] < target) {
            left = mid + 1; // Buscar en la mitad derecha
        }
        else {
            right = mid; // Buscar en la mitad izquierda
        }
    }

    return left; // Retornar la posición donde se debería insertar el elemento
}

void PmergeMe::insertRestDeq(std::deque<unsigned int> &sortedDeq)
{
    sortedDeq.insert(sortedDeq.begin(), deqPair[0].first);
    if(sortedDeq.size() == 1)
    {
        return ;
    }
    size_t itDequePair = 1;
    size_t position;
    while(itDequePair < deqPair.size())
    {
        position = binarySearchDeq(sortedDeq, deqPair[itDequePair].first);
        sortedDeq.insert(sortedDeq.begin() + position, deqPair[itDequePair].first);
        itDequePair ++;
    }
    if (lastDeq != -1)
    {
        position = binarySearchDeq(sortedDeq, lastDeq);
        sortedDeq.insert(sortedDeq.begin() + position, lastDeq);
    }
    /* std::cout << "Final Sorted Sequence:" << std::endl;
    for (size_t k = 0; k < sortedDeq.size(); ++k) {
        std::cout << sortedDeq[k] << " "; // Imprimir cada elemento de sortedVec
    }
    std::cout << std::endl; // Nueva línea al final */
}

 void PmergeMe::sortDeq()
 {
    lastDeq = -1;
    if (deq.size() % 2 != 0)
    {
        lastDeq = deq.back();
        deq.pop_back();
        //std::cout << "Last: " << lastDeq << std::endl;
    }
    //1. Agrupar por pares y ordenar los pares
    pairsOrderDeq(deq);
    orderPairDeq(deqPair);
    //printSortedPairs(vecPair);
    insertRemainingElementsDeq(sortedDeq);
    insertRestDeq(sortedDeq);
 }