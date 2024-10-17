/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:45:18 by manufern          #+#    #+#             */
/*   Updated: 2024/10/17 14:57:43 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


int main(void)
{
    std::string a = "HI THIS IS BRAIN";
    std::string *b = &a;
    std::string &c = a;

    std::cout <<"memory print string a: " << &a << std::endl;  
    std::cout <<"memory print string *b: " << b << std::endl; 
    std::cout <<"memory print string &c: " << &c << std::endl;

    std::cout <<"value print string a: " << a << std::endl;
    std::cout <<"value print string b: " << b[0] << std::endl;
    std::cout <<"value print string c: " << c << std::endl;
}