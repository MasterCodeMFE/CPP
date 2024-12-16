/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:23:27 by manufern          #+#    #+#             */
/*   Updated: 2024/12/16 11:06:12 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <iostream>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string type;
        Animal();
		Animal(std::string type);
		Animal(const Animal& other);
    
    public:
        virtual ~Animal();
        Animal& operator=(const Animal& other);

        virtual void makeSound() const = 0;
        std::string getType() const;
};

#endif