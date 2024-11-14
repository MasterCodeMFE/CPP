/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:38:19 by manufern          #+#    #+#             */
/*   Updated: 2024/10/21 12:11:22 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

void Weapon::setType(std::string type)
{
    this->type = type;
}

Weapon::Weapon()
{
    std::cout << "Constructor Weapon called." << std::endl;
}

Weapon::Weapon(std::string type)
{
    std::cout << "Constructor Weapon called." << std::endl;
    this->type = type;
}

Weapon::~Weapon()
{
    std::cout << "Destructor Weapon called." << std::endl;
}