/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:30:39 by manufern          #+#    #+#             */
/*   Updated: 2025/04/02 17:12:31 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cctype>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: you must provide at least one argument." << std::endl;
        return 1;
    }
    if (argc == 2)
    {
        for(int i = 0; argv[1][i]; i ++)
        {
            if(!isdigit(argv[1][i]))
            {
                std::cout << "Error: you must provide a number." << std::endl; 
                return 1;
            }
        }
        return 0;
    }
    try
    {
        PmergeMe sorter(argc, argv);

        std::cout << "Numbers entered in vector: ";
        sorter.printHelper(sorter.getVector());

        std::cout << "Numbers entered in deque: ";
        sorter.printHelper(sorter.getDeque());


        clock_t startVec = clock();
        sorter.sortVec();
        clock_t endVec = clock();


        clock_t startDeq = clock();
        sorter.sortDeq();
        clock_t endDeq = clock();


        std::cout << "Order numbers in vector: ";
         sorter.printHelper(sorter.getSortedVec());

        std::cout << "Order numbers in deque: ";
        sorter.printHelper(sorter.getSortedDeq());
        
        double durationVec = (endVec - startVec) * 1000.0 / CLOCKS_PER_SEC;
        std::cout << "Execution time vector: " << durationVec << " milliseconds" << std::endl;

        double durationDec = (endDeq - startDeq) * 1000.0 / CLOCKS_PER_SEC;
        std::cout << "Execution time deque: " << durationDec << " milliseconds" << std::endl;

    }
    catch (const std::invalid_argument &e)
    {
        return 1;
    }

    return 0;
}