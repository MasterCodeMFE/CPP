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
                deq.push_back(static_cast<unsigned int>(num)); // Opcional, si quieres llenar ambos
            }
            else
            {
                std::cerr << "Error: The number must be positive." << std::endl;
                throw std::invalid_argument("Invalid argument");
            }
        }
    }
}

PmergeMe:: ~PmergeMe()
{}

const std::vector<unsigned int>& PmergeMe::getVector() const
{
    return vec;
}

const std::deque<unsigned int>& PmergeMe::getDeque() const
{
    return deq;
}


