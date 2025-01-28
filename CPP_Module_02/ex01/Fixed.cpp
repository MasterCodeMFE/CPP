/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:20:52 by manufern          #+#    #+#             */
/*   Updated: 2024/11/13 11:36:38 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

fixed::fixed(): num(0)
{
    std::cout << "Defoult constructor called" << std::endl;
}

fixed::fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    this->num = number << raw;
}

fixed::fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    this->num = static_cast<int>(roundf(number * (1 << raw)));
}

fixed::fixed(const fixed& other) : num(other.num)
{
    std::cout << "Copy constructor called" << std::endl;
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

std::ostream& operator<<(std::ostream& os, const fixed& fixed)
{
    os << fixed.toFloat();
    return os;
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

float fixed::toFloat(void) const
{
    return static_cast<float>(this->num) / (1 << raw);
}

int fixed::toInt(void) const
{
    return this->num >> raw;
}

fixed::~fixed()
{
    std::cout << "Defoult destructor called" << std::endl;
}