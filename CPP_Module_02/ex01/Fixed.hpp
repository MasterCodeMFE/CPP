/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:20:56 by manufern          #+#    #+#             */
/*   Updated: 2024/11/13 11:31:48 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

 class fixed
 {
    private:
        int num;
        static const int raw = 8;
  
    public:
        // cannonical or complied form
        fixed();
        fixed(const int);
        fixed(const float);
        fixed(const fixed& other);
        fixed& operator=(const fixed& other);
        ~fixed();
        
        // auxiliar functions and elements
        int getRawBits(void);
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
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