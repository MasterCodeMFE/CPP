/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:59:36 by manufern          #+#    #+#             */
/*   Updated: 2024/10/18 09:50:08 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassZombie.hpp"

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