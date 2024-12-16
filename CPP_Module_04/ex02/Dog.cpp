/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:25:14 by manufern          #+#    #+#             */
/*   Updated: 2024/12/16 11:02:26 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

Dog::Dog(const Dog& other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = other.type;
    this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
    return brain;
}