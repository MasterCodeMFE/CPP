/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:59:36 by manufern          #+#    #+#             */
/*   Updated: 2024/12/02 15:00:42 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Constructor zombie called." << std::endl;
}

Zombie::~Zombie()
{
        std::cout << "Destructor for zombie '" << name << "' called." << std::endl;
}

Zombie::Zombie(std::string name)
{
    std::cout << "Constructor name called." << std::endl;
    this->name = name;
}

void Zombie::announce(void)
{
    std::cout << "\033[1;32m" << name << " (Zombie) says: BraiiiiiiinnnzzzZ! 🧟\033[0m" << std::endl;
}