/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:20:56 by manufern          #+#    #+#             */
/*   Updated: 2024/11/18 17:57:28 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class fixed {
private:
    int num;
    static const int raw = 8;

public:
    // canonical form
    fixed();
    fixed(const int);
    fixed(const float);
    fixed(const fixed& other);
    fixed& operator=(const fixed& other);

    // Arithmetic operators
    fixed operator+(const fixed &other) const;
    fixed operator-(const fixed &other) const;
    fixed operator*(const fixed &other) const;
    fixed operator/(const fixed &other) const;

    // Comparison operators
    bool operator>(const fixed& other) const;
    bool operator<(const fixed& other) const;
    bool operator>=(const fixed& other) const;
    bool operator<=(const fixed& other) const;
    bool operator==(const fixed& other) const;
    bool operator!=(const fixed& other) const;

    // Increment/Decrement operators
    fixed& operator++();       // Pre-increment
    fixed operator++(int);     // Post-increment
    fixed& operator--();       // Pre-decrement
    fixed operator--(int);     // Post-decrement

    ~fixed();

    // Auxiliary functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    static fixed& min(fixed& a, fixed& b);
    static const fixed& min(const fixed& a, const fixed& b);
    static fixed& max(fixed& a, fixed& b);
    static const fixed& max(const fixed& a, const fixed& b);
};
std::ostream& operator<<(std::ostream& os, const fixed& fixed);

#endif


/* int main (int argc, char **argv)
{
    class fixed fx;

    fx = new(fixed)

~fx()
    exit 0;
} */