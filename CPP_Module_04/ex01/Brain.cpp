/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:08:55 by manufern          #+#    #+#             */
/*   Updated: 2024/11/27 16:54:56 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
    int i = 0;
    while (i < 100)
    {
        Ideas[i] = "Default idea";
        i ++;
    }
}

// Destructor
Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

// Constructor de copia
Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    int i = 0;
    while (i < 100)
    {
        Ideas[i] = other.Ideas[i];
        i ++;
    }
    
}

// Operador de asignación
Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other)
    {
        int i = 0;
        while (i < 100)
        {
            Ideas[i] = other.Ideas[i];
            i ++;
        }
    }
    return *this;
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
    {
        Ideas[index] = idea;
    }
    else
    {
        std::cerr << "Error: Index out of bounds in setIdea()" << std::endl;
    }
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
    {
        return Ideas[index];
    }
    else
    {
        std::cerr << "Error: Index out of bounds in getIdea()" << std::endl;
        return "";
    }
}