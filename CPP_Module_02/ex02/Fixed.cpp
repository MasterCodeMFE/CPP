/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:20:52 by manufern          #+#    #+#             */
/*   Updated: 2024/11/25 14:55:18 by manufern         ###   ########.fr       */
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

int fixed::getRawBits(void) const
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
    return static_cast<float>(this->num) / (1 << this->raw);  // 8 bits fraccionales
}

int fixed::toInt(void) const
{
    return this->num >> this->raw;  // 8 bits fraccionales
}

fixed::~fixed()
{
    std::cout << "Defoult destructor called" << std::endl;
}

bool fixed::operator>(const fixed& other) const
{
    return this->num > other.num;
}

bool fixed::operator>=(const fixed& other) const
{
    return this->num >= other.num;
}

bool fixed::operator<(const fixed& other) const
{
    return this->num < other.num;
}

bool fixed::operator<=(const fixed& other) const
{
    return this->num <= other.num;
}

bool fixed::operator==(const fixed& other) const
{
    return this->num == other.num;
}

bool fixed::operator!=(const fixed& other) const
{
    return this->num != other.num;
}


fixed fixed::operator+(const fixed &other) const
{
    fixed result;
    result.num = this->num + other.num;
    return result;
}

fixed fixed::operator-(const fixed &other) const
{
    fixed result;
    result.num = this->num - other.num;
    return result;
}

fixed fixed::operator*(const fixed &other) const
{
    fixed result;
    result.num = this->num * other.num;
    return result;
}

fixed fixed::operator/(const fixed &other) const
{
    fixed result;
    if (other.num != 0)
    {
        result.num = this->num / other.num; 
    }
    return result; 
}

// Pre-incremento
fixed& fixed::operator++() {
    ++this->num; // Incrementa el valor en 1
    return *this;   // Devuelve una referencia al objeto modificado
}

// Post-incremento
fixed fixed::operator++(int) {
    fixed temp(*this); // Crea una copia del valor actual
    ++(*this);     // Incrementa el valor en 1
    return temp;        // Devuelve la copia anterior
}

// Pre-decremento
fixed& fixed::operator--() {
    --this->num; // Decrementa el valor en 1
    return *this;   // Devuelve una referencia al objeto modificado
}

// Post-decremento
fixed fixed::operator--(int) {
    fixed temp(*this); // Crea una copia del valor actual
    ++(*this);     // Decrementa el valor en 1
    return temp;        // Devuelve la copia anterior
}

fixed& fixed::min(fixed& a, fixed& b)
{
    if (a.num < b.num)
    {
        return a;
    }
    else
    {
        return b;
    }
}


fixed& fixed::max(fixed& a, fixed& b)
{
    if (a.num > b.num)
    {
        return a;
    }
    else
    {
        return b;
    }
}

const fixed& fixed::min(const fixed& a, const fixed& b)
{
    if (a.num < b.num)
    {
        return a;
    }
    else
    {
        return b;
    }
}

const fixed& fixed::max(const fixed& a, const fixed& b)
{
     if (a.num > b.num)
    {
        return a;
    }
    else
    {
        return b;
    }
}