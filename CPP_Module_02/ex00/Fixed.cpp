/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:20:52 by manufern          #+#    #+#             */
/*   Updated: 2024/11/12 10:07:20 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

fixed::fixed()
{
    std::cout << "Defoult constructor called" << std::endl;
    this->num = 0;
}

fixed::fixed(const fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->num = other.num;
}

fixed& fixed::operator=(const fixed& other)
{
    std::cout << "Copy assignment operator calle" << std::endl;
    if (this != &other)
    {
        this->num = other.num;
    }
    return *this;
}

int fixed::getRawBits(void)
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->num);
}

void fixed::setRawBits(int const raw)
{
    this->num = raw;
}
fixed::~fixed()
{
    std::cout << "Defoult destructor called" << std::endl;
}