/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:20:52 by manufern          #+#    #+#             */
/*   Updated: 2024/12/04 16:44:49 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ! Constructor por defecto
fixed::fixed(): num(0)
{
    std::cout << "Defoult constructor called" << std::endl;
}

// ! Constructor con parámetro entero
fixed::fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    this->num = number << raw;
}

// ! Constructor con parámetro flotante
fixed::fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    this->num = static_cast<int>(roundf(number * (1 << raw)));
}

// ! Constructor de copia
fixed::fixed(const fixed& other) : num(other.num)
{
    std::cout << "Copy constructor called" << std::endl;
}

// ! Operador de asignación
fixed& fixed::operator=(const fixed& other)
{
    std::cout << "Copy assignment operator calle" << std::endl;
    if (this != &other)
    {
        this->num = other.num;
    }
    return *this;
}

// ! Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& os, const fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

// ! Getter para obtener los bits "raw"
int fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->num);
}

// ! Setter para establecer los bits "raw"
void fixed::setRawBits(int const raw)
{
    this->num = raw;
}

// ! Conversión a float
float fixed::toFloat(void) const
{
    return static_cast<float>(this->num) / (1 << this->raw);  // 8 bits fraccionales
}

// ! Conversión a int
int fixed::toInt(void) const
{
    return this->num >> this->raw;  // 8 bits fraccionales
}

// ! Destructor
fixed::~fixed()
{
    std::cout << "Defoult destructor called" << std::endl;
}

// ! Sobrecarga de operadores relacionales
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

// ! Sobrecarga de operadores aritméticos
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
    result.num = (this->num * other.num) >> this->raw;
    return result;
}

fixed fixed::operator/(const fixed &other) const
{
    fixed result;
    if (other.num != 0)
    {
        result.num = this->num * (1 << raw) / other.num; 
    }
    return result; 
}

// ! Pre-incremento
fixed& fixed::operator++() {
    ++this->num; // Incrementa el valor en 1
    return *this;   // Devuelve una referencia al objeto modificado
}

// ! Post-incremento
fixed fixed::operator++(int) {
    fixed temp(*this); // Crea una copia del valor actual
    ++(*this);     // Incrementa el valor en 1
    return temp;        // Devuelve la copia anterior
}

// ! Pre-decremento
fixed& fixed::operator--() {
    --this->num; // Decrementa el valor en 1
    return *this;   // Devuelve una referencia al objeto modificado
}

// ! Post-decremento
fixed fixed::operator--(int) {
    fixed temp(*this); // Crea una copia del valor actual
    --(*this);     // Decrementa el valor en 1
    return temp;        // Devuelve la copia anterior
}

// ! Mínimo entre dos valores
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

// ! Máximo entre dos valores
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

// ! Mínimo entre dos valores constantes
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

// ! Máximo entre dos valores constantes
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
