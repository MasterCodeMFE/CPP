/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:05:56 by manufern          #+#    #+#             */
/*   Updated: 2024/10/17 14:05:58 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Constructor zombie called." << std::endl;
}

Zombie::~Zombie()
{
   std::cout << "Destructor zombie called." << std::endl; 
}

Zombie::Zombie(std::string name)
{
    std::cout << "Constructor name called." << std::endl;
    this->name = name;
}

void Zombie::announce(void)
{

    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}