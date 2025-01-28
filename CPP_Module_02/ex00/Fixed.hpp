/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:20:56 by manufern          #+#    #+#             */
/*   Updated: 2024/11/12 10:09:56 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FIXED_HPP
# define FIXED_HPP
# include <iostream>

 class fixed
 {
    private:
        int num;
        static const int raw = 8;
  
    public:
        fixed();
        fixed(const fixed& other);
        fixed& operator=(const fixed& other);
        ~fixed();
        
        int getRawBits(void);
        void setRawBits(int const raw);

};
#endif